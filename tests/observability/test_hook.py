"""The opt-in hook is local-only and cannot fail commits."""

import os
import subprocess
import sys

from .test_cli import ROOT, configure_fixture, invoke
from .test_identity import make_repository


def test_hook_enqueues_locally_when_invoked(tmp_path):
    root = configure_fixture(make_repository(tmp_path / "repo"))
    environment = dict(os.environ, OBSERVABILITY_PYTHON=sys.executable, PYTHONPATH=str(ROOT))
    result = subprocess.run(["sh", str(ROOT / "hooks/observability/post-commit.example")],
                            cwd=root, env=environment, capture_output=True, timeout=30)
    assert result.returncode == 0
    status = invoke(root, "status", "--json")
    assert '"state": "pending"' in status.stdout


def test_missing_python_does_not_fail_hook(tmp_path):
    root = make_repository(tmp_path / "repo")
    environment = dict(os.environ, OBSERVABILITY_PYTHON="/missing/python")
    result = subprocess.run(["sh", str(ROOT / "hooks/observability/post-commit.example")],
                            cwd=root, env=environment, capture_output=True, timeout=10)
    assert result.returncode == 0
