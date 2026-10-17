"""Bind a queue attempt to fresh verification and a public-safe snapshot."""

from .atomic import write_atomic
from .model import content_digest
from .snapshot import make_snapshot, utc_now
from .verification import assess_evidence


def _assessment(result):
    if result.get("error"):
        return dict(state="blocked", ranges=[], errors=[result["error"]],
                    gates=dict(behavior="unavailable", matching="unavailable"))
    return assess_evidence(result["entry"], result["checkout"], result["before"],
                           result["after"], result["reports"])


def verify_revision(claim, executor, store):
    """Verify a queued immutable tree, recording blocked/failure outcomes honestly."""
    started = utc_now()
    result = executor.execute(claim)
    assessment = _assessment(result)
    assessment["evidence"] = [content_digest(result.get("reports", {}))]
    snapshot = make_snapshot(claim, result, assessment, started)
    _persist(claim, snapshot, store)
    return snapshot


def _persist(claim, snapshot, store):
    if "token" in claim:
        store.complete(claim, snapshot)
    if "token" not in claim:
        store.record_snapshot(snapshot)
    path = store.directory / "snapshots" / (content_digest(snapshot) + ".json")
    write_atomic(path, snapshot)
