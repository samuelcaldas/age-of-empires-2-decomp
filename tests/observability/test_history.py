"""Hand-derived complete-window rates and conditional scenario arithmetic."""

import pytest

from scripts.observability.history import estimate_completion, window_rate


def point(day, size, commit, series="stable"):
    return dict(timestamp=f"2026-10-{10 + day:02}T00:00:00Z", bytes=size,
                commit=commit, sequence=day + 1, series_id=series)


def test_exact_24_hour_net_rate():
    result = window_rate([point(0, 100, "a"), point(1, 200, "b")], 24)
    assert result["bytes_per_hour"] == pytest.approx(100 / 24)


def test_duplicate_commit_does_not_duplicate_delivery():
    history = [point(0, 100, "a"), point(1, 200, "b"), point(1, 200, "b")]
    assert window_rate(history, 24)["bytes_per_hour"] == pytest.approx(100 / 24)


def test_partial_window_is_not_extrapolated():
    history = [point(0, 100, "a"), point(1, 200, "b")]
    history[0]["timestamp"] = "2026-10-10T01:00:00Z"
    assert window_rate(history, 24)["bytes_per_hour"] is None
    assert window_rate(history, 168)["bytes_per_hour"] is None


def test_removed_bytes_preserve_negative_rate():
    result = window_rate([point(0, 200, "a"), point(1, 100, "b")], 24)
    assert result["bytes_per_hour"] == pytest.approx(-100 / 24)


def test_new_series_is_not_compatible_history():
    result = window_rate([point(0, 100, "a"), point(1, 200, "b", "expanded_inventory")], 24)
    assert result["bytes_per_hour"] is None
    assert result["reason"] == "INCOMPARABLE_SERIES"


def test_nonmonotonic_observation_time_is_not_elapsed_progress():
    result = window_rate([point(1, 100, "a"), point(0, 200, "b")], 24)
    assert result["bytes_per_hour"] is None
    assert result["reason"] == "CLOCK_ANOMALY"


def test_one_hour_baseline_tolerance_uses_actual_elapsed_time():
    history = [point(0, 100, "a"), point(1, 200, "b")]
    history[0]["timestamp"] = "2026-10-09T23:00:00Z"
    assert window_rate(history, 24)["bytes_per_hour"] == pytest.approx(100 / 25)
    history[0]["timestamp"] = "2026-10-09T22:59:59Z"
    assert window_rate(history, 24)["bytes_per_hour"] is None


def test_scenarios_use_three_independent_daily_deltas():
    history = [point(0, 0, "a"), point(1, 100, "b"),
               point(2, 300, "c"), point(3, 600, "d")]
    denominator = dict(bytes=1200, kind="audited_code", confidence="verified", source="registry")
    result = estimate_completion(history, denominator)
    assert result["central_days"] == 3
    assert result["optimistic_days"] == 2
    assert result["conservative_days"] == 6
    assert result["reason"] is None


@pytest.mark.parametrize("denominator", [
    None, dict(bytes=None, kind="unknown"),
    dict(bytes=4075488, kind="load_range", confidence="partial"),
])
def test_unknown_code_denominator_prevents_eta(denominator):
    assert estimate_completion([], denominator)["central_days"] is None


def test_zero_latest_rate_prevents_eta():
    history = [point(0, 0, "a"), point(1, 100, "b"), point(2, 200, "c"), point(3, 200, "d")]
    denominator = dict(bytes=1200, kind="audited_code", confidence="verified", source="registry")
    assert estimate_completion(history, denominator)["central_days"] is None
