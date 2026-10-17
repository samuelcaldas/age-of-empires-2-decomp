"""Fresh executor evidence becomes a bound immutable local snapshot."""

from scripts.observability.collector import verify_revision
from scripts.observability.store import MetricsStore
from .test_store import request
from .test_verification import entry, report


class SyntheticExecutor:
    def __init__(self, root, code=None):
        self.root = root
        self.code = code

    def execute(self, claim):
        identity = dict(commit=claim["request"]["commit"], tree=claim["request"]["tree"],
                        original="a" * 40, compiler="b" * 64, config="c" * 64,
                        verifier="d" * 64)
        return dict(entry=entry(self.root), checkout=self.root, before=identity,
                    after=identity, reports=dict(behavior=report(), matching=report()),
                    error=self.code, registry_digest="e" * 64, integrated=True)


def test_fresh_evidence_is_bound_and_stored(tmp_path):
    store = MetricsStore(tmp_path / "git")
    queued = store.enqueue(request())
    result = verify_revision(queued, SyntheticExecutor(tmp_path), store)
    assert result.get("state") == "verified"
    assert result["commit"] == "a" * 40
    assert result["attempt_id"] == queued["attempt_id"]
    assert result["scope"]["linked_executable"] == "not-run"
    assert len(store.read_snapshots()) == 1
    artifacts = list((store.directory / "snapshots").glob("*.json"))
    assert len(artifacts) == 1


def test_unavailable_remote_mount_is_blocked_not_zero_progress(tmp_path):
    store = MetricsStore(tmp_path / "git")
    queued = store.enqueue(request())
    result = verify_revision(queued, SyntheticExecutor(tmp_path, "REMOTE_MOUNT_UNAVAILABLE"), store)
    assert result.get("state") == "blocked"
    assert result["ranges"] == []
    assert result["errors"] == ["REMOTE_MOUNT_UNAVAILABLE"]
