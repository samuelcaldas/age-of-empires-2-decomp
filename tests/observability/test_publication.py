"""Offline publication plan validation and dry-run safety."""

import pytest

from scripts.observability.github import apply_publication, plan_publication
from .test_export import bundle


def test_dry_run_is_default_and_executes_no_writes():
    b = bundle()
    repo = dict(root="/tmp", default_branch="main", remote_url="https://github.com/samuelcaldas/age-of-empires-2-decomp.git")
    plan = plan_publication(b, repo)
    assert plan.get("mode") == "dry-run"
    assert "target_branch" in plan
    assert plan["target_branch"] == "decomp-metrics"
    # apply with dummy transport doing no writes
    calls = []
    receipt = apply_publication(plan, lambda op, *args: calls.append(op), deploy=False)
    assert receipt.get("status") == "dry-run"
    assert len(calls) == 0


def test_unauthorized_repo_fails():
    b = bundle()
    repo = dict(root="/tmp", default_branch="main", remote_url="https://github.com/other/repo.git")
    with pytest.raises(ValueError, match="remote"):
        plan_publication(b, repo)
