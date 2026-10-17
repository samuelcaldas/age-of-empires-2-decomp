"""Execute the real command entry point against disposable Git repositories."""

import json
from pathlib import Path
import subprocess
import sys

import pytest

from .test_identity import make_repository

ROOT = Path(__file__).resolve().parents[2]


def invoke(root, *arguments):
    return subprocess.run([sys.executable, "-m", "scripts.observability", "--repo", str(root),
                           *arguments], cwd=ROOT, capture_output=True, text=True, timeout=30)


def configure_fixture(root):
    (root / "config/observability").mkdir(parents=True)
    (root / "config/observability/registry.json").write_text('{"schema_version":1,"entries":[]}')
    (root / "schemas/observability").mkdir(parents=True)
    (root / "schemas/observability/snapshot-v1.schema.json").write_text('{}')
    return root


def test_empty_status_is_json_without_creating_store(tmp_path):
    root = make_repository(tmp_path / "repo")
    result = invoke(root, "status", "--json")
    assert result.returncode == 0, result.stderr
    assert result.stdout.strip()
    value = json.loads(result.stdout)
    assert value["state"] == "unavailable"
    assert value["verified_cpp_bytes"] is None
    assert not (root / ".git/observability").exists()


def test_interrupt_returns_cleanly_without_swallowing_other_failures(tmp_path, monkeypatch):
    from scripts.observability import cli

    def interrupted(args):
        raise KeyboardInterrupt

    monkeypatch.setattr(cli, "watch_command", interrupted)
    root = make_repository(tmp_path / "repo")
    assert cli.main(["--repo", str(root), "watch"]) == 0


def test_missing_repository_is_error(tmp_path):
    assert invoke(tmp_path, "status").returncode != 0


@pytest.mark.parametrize("interval", ["0", "-1", "nan", "inf"])
def test_invalid_watch_interval_is_error(tmp_path, interval):
    root = make_repository(tmp_path / "repo")
    assert invoke(root, "watch", "--once", "--interval", interval).returncode != 0


def test_enqueue_creates_pending_local_state_without_network(tmp_path):
    root = configure_fixture(make_repository(tmp_path / "repo"))
    first = invoke(root, "enqueue")
    assert first.returncode == 0, first.stderr
    status = invoke(root, "status", "--json")
    assert status.stdout.strip()
    value = json.loads(status.stdout)
    assert value["state"] == "pending"
    assert value["verified_cpp_bytes"] is None
    second = invoke(root, "enqueue")
    assert json.loads(second.stdout)["attempt_id"] == json.loads(first.stdout)["attempt_id"]


def test_explicit_retry_creates_new_attempt_without_duplicate_default_enqueue(tmp_path):
    root = configure_fixture(make_repository(tmp_path / "repo"))
    first = invoke(root, "enqueue")
    retry = invoke(root, "enqueue", "--retry")
    assert retry.returncode == 0, retry.stderr
    assert first.stdout.strip() and retry.stdout.strip()
    assert json.loads(first.stdout)["attempt_id"] != json.loads(retry.stdout)["attempt_id"]


def test_worker_accepts_explicit_watch_mode_and_once_smoke(tmp_path):
    root = make_repository(tmp_path / "repo")
    result = invoke(root, "work", "--watch", "--once")
    assert result.returncode == 0, result.stderr


def test_watch_once_supports_non_tty_no_color(tmp_path):
    root = make_repository(tmp_path / "repo")
    result = invoke(root, "watch", "--once", "--no-color")
    assert result.returncode == 0, result.stderr
    assert "unavailable" in result.stdout
    assert "\x1b[" not in result.stdout
