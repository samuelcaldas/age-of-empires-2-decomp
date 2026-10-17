"""Official current status follows source ancestry, not report arrival or labels."""

from datetime import datetime, timezone

from scripts.observability.projection import build_projection
from .fixtures import snapshot

NOW = datetime(2026, 10, 17, 0, 2, tzinfo=timezone.utc)


def graph(head="b", anchor="a"):
    return dict(commits=["a" * 40, "b" * 40], head=head * 40, anchor=anchor * 40)


def test_newer_commit_wins_reverse_completion_order():
    newer = snapshot("b", 1)
    old_completed_late = snapshot("a", 2)
    result = build_projection([newer, old_completed_late], graph(), NOW)
    assert result["measured_commit"] == "b" * 40
    assert result["verified_cpp_bytes"] == 40


def test_new_failure_keeps_success_explicitly_historical():
    failed = snapshot("b", 2, "failed", ranges=[])
    failed["gates"]["matching"] = "failed"
    result = build_projection([snapshot("a"), failed], graph(), NOW)
    assert result["state"] == "failed"
    assert result["verified_cpp_bytes"] is None
    assert result["last_verified_cpp_bytes"] == 40
    assert result["head_commit"] == "b" * 40
    assert result["measured_commit"] == "a" * 40


def test_unmeasured_new_head_does_not_look_green():
    result = build_projection([snapshot("a")], graph(), NOW)
    assert result["state"] == "pending"
    assert result["verified_cpp_bytes"] is None
    assert result["last_verified_cpp_bytes"] == 40


def test_branch_flag_cannot_forge_main_membership():
    branch = snapshot("c", 9)
    result = build_projection([snapshot("b"), branch], graph(), NOW)
    assert result["measured_commit"] == "b" * 40
    assert result["branch_attempts"] == 1


def test_rerun_and_merge_are_not_duplicate_byte_deliveries():
    result = build_projection([snapshot("a"), snapshot("b", 2), snapshot("b", 3)], graph(), NOW)
    assert result["verified_cpp_bytes"] == 40
    assert len(result["history"]) == 2
    assert result["global_percent"] is None


def test_missing_approved_anchor_blocks_rewritten_history():
    result = build_projection([snapshot("b")], graph(anchor="c"), NOW)
    assert result["state"] == "blocked"
    assert result["reason"] == "HISTORY_REWRITTEN"
    assert result["verified_cpp_bytes"] is None


def test_multiple_producer_streams_require_enrollment():
    other = snapshot("b", 2)
    other["producer"] = "f" * 32
    result = build_projection([snapshot("a"), other], graph(), NOW)
    assert result["state"] == "blocked"
    assert result["reason"] == "PRODUCER_CONFLICT"
