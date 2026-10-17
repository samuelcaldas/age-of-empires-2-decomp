"""Single shared, ancestry-aware calculation path for every output surface."""

from .history import estimate_completion, moment, window_rate
from .model import content_digest, validate_snapshot
from .ranges import function_count, union_code_bytes


def _empty(graph, now):
    return dict(schema_version=1, edition=graph.get("edition", "SLES-50282"), state="unavailable",
                reason="NO_EVIDENCE", head_commit=graph["head"],
                source_head_commit=graph.get("source_head", graph["head"]), measured_commit=None,
                latest_attempt=None, last_successful=None, verified_cpp_bytes=None,
                last_verified_cpp_bytes=None, functions=None, global_percent=None,
                denominator=dict(bytes=None, kind="unknown", confidence="unknown", source="unknown"),
                scope="audited_lower_bound", enrolled_units=0, observed=None, branch_attempts=0,
                history=[], rates={"24h": window_rate([], 24), "7d": window_rate([], 168)},
                eta=estimate_completion([], None), collected_at=now.isoformat().replace("+00:00", "Z"),
                stale=True, last_verified_at=None)


def _history_point(snapshot):
    identity = [snapshot["series_id"], snapshot["fingerprints"], snapshot["denominator"],
                snapshot["scope"]["kind"], snapshot["policy_version"]]
    return dict(commit=snapshot["commit"], sequence=snapshot["sequence"],
                timestamp=snapshot["times"]["collected"], bytes=union_code_bytes(snapshot["ranges"]),
                series_id=content_digest(identity))


def _official(records, graph):
    ranks = {commit: index for index, commit in enumerate(graph["commits"])}
    selected = [record for record in records if record["commit"] in ranks]
    return sorted(selected, key=lambda record: (ranks[record["commit"]], record["sequence"]))


def _verified_history(records):
    latest = {}
    for record in records:
        if record["state"] == "verified":
            latest[record["commit"]] = record
    return [_history_point(record) for record in latest.values()]


def _blocked(output, reason):
    output.update(state="blocked", reason=reason)
    return output


def _validate_stream(records, graph):
    if graph.get("anchor") and graph["anchor"] not in graph["commits"]:
        return "HISTORY_REWRITTEN"
    if len({record["producer"] for record in records}) > 1:
        return "PRODUCER_CONFLICT"
    return None


def build_projection(snapshots, graph, now):
    """Derive official status from trusted source ancestry; validate every record."""
    records = [validate_snapshot(value) for value in snapshots]
    output = _empty(graph, now)
    official = _official(records, graph)
    output["branch_attempts"] = len(records) - len(official)
    reason = _validate_stream(official, graph)
    if reason:
        return _blocked(output, reason)
    if not official:
        return output
    return _populate(output, official, now)


def _populate(output, records, now):
    attempt = records[-1]
    successes = [record for record in records if record["state"] == "verified"]
    output.update(latest_attempt=attempt, state=attempt["state"], reason=None,
                  edition=attempt["edition"], enrolled_units=attempt["scope"]["enrolled_units"],
                  observed=attempt["observed"], history=_verified_history(records))
    if attempt["commit"] != output["source_head_commit"]:
        output.update(state="pending", reason="HEAD_NOT_VERIFIED")
    if successes:
        _populate_success(output, successes[-1], now)
    if output["state"] == "verified":
        _current_measurement(output)
    return output


def _populate_success(output, success, now):
    timestamp = success["times"]["collected"]
    output.update(last_successful=success, measured_commit=success["commit"],
                  last_verified_cpp_bytes=union_code_bytes(success["ranges"]),
                  last_verified_at=timestamp, stale=(now - moment(timestamp)).total_seconds() > 900,
                  denominator=success["denominator"])


def _current_measurement(output):
    success = output["latest_attempt"]
    output.update(verified_cpp_bytes=union_code_bytes(success["ranges"]),
                  functions=function_count(success["ranges"]))
    denominator = success["denominator"]
    if denominator["kind"] == "audited_code" and denominator["confidence"] == "verified" and denominator["bytes"]:
        output["global_percent"] = output["verified_cpp_bytes"] * 100 / denominator["bytes"]
    output["rates"] = {"24h": window_rate(output["history"], 24), "7d": window_rate(output["history"], 168)}
    output["eta"] = estimate_completion(output["history"], denominator)
