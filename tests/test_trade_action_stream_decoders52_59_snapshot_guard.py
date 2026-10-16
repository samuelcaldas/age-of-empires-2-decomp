"""Exercise the snapshot proof's fail-closed root boundary."""

import importlib.util
from pathlib import Path

import pytest


ENVIRONMENT_PATH = Path(__file__).with_name("trade_action_stream_decoders52_59_environment.py")


def load_environment():
    spec = importlib.util.spec_from_file_location("decoder52_59_environment", ENVIRONMENT_PATH)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_rejects_explicit_root_different_from_working_directory(tmp_path, monkeypatch):
    monkeypatch.chdir(tmp_path)
    with pytest.raises(AssertionError, match="explicit snapshot root must equal cwd"):
        load_environment().require_root(tmp_path / "other")


def test_rejects_missing_external_snapshot_marker(tmp_path, monkeypatch):
    monkeypatch.chdir(tmp_path)
    (tmp_path / "configure.py").touch()
    with pytest.raises(AssertionError, match="requires disposable Docker snapshot"):
        load_environment().require_root(tmp_path)


def test_refuses_git_directory_even_with_snapshot_marker(tmp_path, monkeypatch):
    monkeypatch.chdir(tmp_path)
    (tmp_path / ".decoder52_59_snapshot").touch()
    (tmp_path / ".git").mkdir()
    with pytest.raises(AssertionError, match="refusing a Git worktree"):
        load_environment().require_root(tmp_path)
