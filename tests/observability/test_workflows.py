"""Validate GitHub workflow syntax and security boundaries."""

from pathlib import Path
import yaml


def test_workflow_permissions_and_concurrency():
    wf_path = Path(__file__).resolve().parents[2] / ".github/workflows/observability-pages.yml"
    assert wf_path.is_file(), "Pages workflow missing"
    data = yaml.safe_load(wf_path.read_text())
    assert data["concurrency"]["cancel-in-progress"] is False
    deploy_job = data["jobs"]["deploy"]
    assert deploy_job["permissions"]["pages"] == "write"
    assert deploy_job["permissions"]["id-token"] == "write"
    assert deploy_job["permissions"].get("contents") in ("read", None)
