"""Actual SQLite persistence and immutable attempt accounting."""

from concurrent.futures import ProcessPoolExecutor
import pytest

from scripts.observability.store import MetricsStore
from .fixtures import snapshot


def request(commit="a"):
    return dict(commit=commit * 40, tree=commit * 40, edition="SLES-50282",
                profile="audited", fingerprint="0" * 64)


def enqueue_in_process(root):
    return MetricsStore(root).enqueue(request())


def test_pending_request_is_idempotent_and_shared(tmp_path):
    first = MetricsStore(tmp_path).enqueue(request())
    assert first.get("sequence") == 1
    assert MetricsStore(tmp_path).enqueue(request()) == first
    assert MetricsStore(tmp_path).read_events()[0]["state"] == "pending"


def test_multiprocess_enqueue_has_one_identity(tmp_path):
    with ProcessPoolExecutor(max_workers=3) as pool:
        results = list(pool.map(enqueue_in_process, [tmp_path] * 3))
    assert results[0].get("sequence") == 1
    assert results[0] == results[1] == results[2]


def test_sequences_increase_across_requests(tmp_path):
    store = MetricsStore(tmp_path)
    assert store.enqueue(request("a")).get("sequence") == 1
    assert store.enqueue(request("b")).get("sequence") == 2


def test_invalid_snapshot_cannot_overwrite_valid_evidence(tmp_path):
    store = MetricsStore(tmp_path)
    store.record_snapshot(snapshot())
    assert len(store.read_snapshots()) == 1
    with pytest.raises(ValueError):
        store.record_snapshot({"state": "verified", "raw_log": "secret"})
    assert len(store.read_snapshots()) == 1


def test_old_completion_does_not_replace_new_attempt(tmp_path):
    store = MetricsStore(tmp_path)
    store.record_snapshot(snapshot("b", sequence=2))
    store.record_snapshot(snapshot("a", sequence=1))
    assert [value["sequence"] for value in store.read_snapshots()] == [1, 2]


def test_same_record_is_idempotent_but_conflicting_content_is_rejected(tmp_path):
    store = MetricsStore(tmp_path)
    value = snapshot()
    store.record_snapshot(value)
    store.record_snapshot(value)
    assert len(store.read_snapshots()) == 1
    value["tree"] = "f" * 40
    with pytest.raises(ValueError, match="conflict"):
        store.record_snapshot(value)
