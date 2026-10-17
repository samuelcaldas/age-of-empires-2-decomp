"""Comparable net-coverage windows and explicitly conditional completion scenarios."""

from datetime import datetime, timedelta
import math
from statistics import median


def moment(value):
    """Parse an observation time; reject naive timestamps."""
    result = datetime.fromisoformat(value.replace("Z", "+00:00"))
    if result.tzinfo is None:
        raise ValueError("observation time must include UTC offset")
    return result


def _deduplicate(history):
    records = {}
    for point in history:
        _keep_latest(records, point)
    return list(records.values())


def _keep_latest(records, point):
    current = records.get(point["commit"])
    if current is None or point["sequence"] >= current["sequence"]:
        records[point["commit"]] = point


def _current_series(points):
    if not points:
        return []
    last_change = max((index for index, point in enumerate(points)
                       if point["series_id"] != points[-1]["series_id"]), default=-1)
    return points[last_change + 1:]


def _history_reason(points):
    if len(points) < 2:
        return "INSUFFICIENT_HISTORY"
    times = [moment(point["timestamp"]) for point in points]
    if any(right <= left for left, right in zip(times, times[1:])):
        return "CLOCK_ANOMALY"
    if any(type(point["bytes"]) is not int or point["bytes"] < 0 for point in points):
        return "INVALID_MEASUREMENT"
    return None


def _rate_unavailable(reason):
    return dict(bytes_per_hour=None, reason=reason, as_of=None, elapsed_hours=None)


def window_rate(history, hours):
    """Return a full-window net rate using actual elapsed time, or a reason."""
    if not math.isfinite(hours) or hours <= 0:
        raise ValueError("rate window must be positive and finite")
    all_points = _deduplicate(history)
    points = _current_series(all_points)
    reason = _history_reason(points)
    if len(points) < 2 and len(all_points) > len(points):
        reason = "INCOMPARABLE_SERIES"
    if reason:
        return _rate_unavailable(reason)
    return _calculate_window(points, hours)


def _calculate_window(points, hours):
    end = points[-1]
    cutoff = moment(end["timestamp"]) - timedelta(hours=hours)
    candidates = [point for point in points[:-1]
                  if timedelta(0) <= cutoff - moment(point["timestamp"]) <= timedelta(hours=1)]
    if not candidates:
        return _rate_unavailable("INSUFFICIENT_HISTORY")
    start = candidates[-1]
    elapsed = (moment(end["timestamp"]) - moment(start["timestamp"])).total_seconds() / 3600
    return dict(bytes_per_hour=(end["bytes"] - start["bytes"]) / elapsed,
                reason=None, as_of=end["timestamp"], elapsed_hours=elapsed)


def _eta_unavailable(reason):
    return dict(central_days=None, optimistic_days=None, conservative_days=None,
                reason=reason, daily_rates=[])


def _daily_rates(points):
    intervals = ((right["bytes"] - left["bytes"],
                  (moment(right["timestamp"]) - moment(left["timestamp"])).total_seconds() / 3600)
                 for left, right in zip(points, points[1:]))
    return [delta * 24 / hours for delta, hours in intervals if 24 <= hours <= 25]


def estimate_completion(history, denominator):
    """Return observed-rate scenarios, never a confidence interval or guessed date."""
    if not denominator or denominator.get("kind") != "audited_code" or denominator.get("confidence") != "verified":
        return _eta_unavailable("UNKNOWN_DENOMINATOR")
    points = _current_series(_deduplicate(history))
    reason = _history_reason(points)
    if reason:
        return _eta_unavailable(reason)
    rates = _daily_rates(points)
    if len(rates) < 3:
        return _eta_unavailable("INSUFFICIENT_HISTORY")
    if rates[-1] <= 0:
        return _eta_unavailable("NON_POSITIVE_RATE")
    return _scenarios(points, rates, denominator)


def _scenarios(points, rates, denominator):
    remaining = denominator["bytes"] - points[-1]["bytes"]
    if remaining < 0:
        return _eta_unavailable("INVALID_DENOMINATOR")
    positive = [rate for rate in rates if rate > 0]
    return dict(central_days=remaining / median(positive), optimistic_days=remaining / max(positive),
                conservative_days=remaining / min(positive), reason=None, daily_rates=rates)
