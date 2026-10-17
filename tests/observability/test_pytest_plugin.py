"""Exercise actual pytest collection and skip reporting in a subprocess."""

import json
import os
from pathlib import Path
import subprocess
import sys


def test_plugin_reports_actual_nodes_and_phases(tmp_path):
    (tmp_path / "test_candidate.py").write_text(
        'import pytest\ndef test_one(): assert 1 == 1\n'
        '@pytest.mark.skip(reason="fixture prerequisite")\ndef test_two(): assert False\n')
    output = tmp_path / "outcomes.json"
    environment = dict(os.environ, PYTHONPATH=str(Path(__file__).resolve().parents[2]))
    command = [sys.executable, "-m", "pytest", "-q", "-p",
               "scripts.observability.pytest_plugin", "--observability-report", str(output)]
    result = subprocess.run(command, cwd=tmp_path, env=environment,
                            capture_output=True, text=True, timeout=30)
    assert result.returncode == 0, result.stderr
    data = json.loads(output.read_text())
    assert data["collected"] == ["test_candidate.py::test_one", "test_candidate.py::test_two"]
    first = [item for item in data["outcomes"] if item["nodeid"].endswith("test_one")]
    assert {item["when"] for item in first} == {"setup", "call", "teardown"}
    assert any(item["outcome"] == "skipped" for item in data["outcomes"])
