"""Exclusive queue leases and explicit worker-loss recovery."""

import pytest

from scripts.observability.store import MetricsStore
from .test_store import request


def test_claim_is_exclusive(tmp_path):
    store = MetricsStore(tmp_path)
    expected = store.enqueue(request())
    claimed = store.claim("worker_one", 30, now=100)
    assert claimed is not None
    assert claimed["attempt_id"] == expected["attempt_id"]
    assert store.claim("worker_two", 30, now=110) is None


def test_expired_worker_records_loss_before_reclaim(tmp_path):
    store = MetricsStore(tmp_path)
    store.enqueue(request())
    store.claim("worker_one", 30, now=100)
    recovered = store.claim("worker_two", 30, now=131)
    assert recovered is not None
    assert any(event.get("code") == "WORKER_LOST" for event in store.read_events())


def test_expired_worker_cannot_complete_reclaimed_attempt(tmp_path):
    store = MetricsStore(tmp_path)
    store.enqueue(request())
    old = store.claim("old", 30, now=100)
    store.claim("new", 30, now=131)
    with pytest.raises(ValueError, match="lease"):
        store.complete(old, {})


@pytest.mark.parametrize("seconds", [0, -1, float("nan"), float("inf")])
def test_invalid_lease_is_rejected(tmp_path, seconds):
    with pytest.raises(ValueError):
        MetricsStore(tmp_path).claim("worker", seconds)
