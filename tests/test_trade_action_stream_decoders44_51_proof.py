"""Snapshot-boundary tests for the decoder44–51 proof tools."""

import importlib.util
from pathlib import Path
import subprocess
import sys

import pytest


ROOT = Path(__file__).resolve().parents[1]


def load_environment():
    path = Path(__file__).with_name("trade_action_stream_decoders44_51_environment.py")
    spec = importlib.util.spec_from_file_location("decoder44_51_environment", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def test_environment_requires_disposable_snapshot_marker():
    environment = load_environment()
    marker = ROOT / ".decoder44_51_snapshot"
    existed = marker.exists()
    marker.unlink(missing_ok=True)
    try:
        with pytest.raises(AssertionError, match="disposable Docker snapshot"):
            environment.require_root(ROOT)
    finally:
        if existed:
            marker.write_text("disposable Docker verification snapshot\n")


def test_checker_does_not_authorize_its_own_snapshot(tmp_path):
    marker = tmp_path / ".decoder44_51_snapshot"
    (tmp_path / "configure.py").touch()
    checker = Path(__file__).with_name("check_trade_action_stream_decoders44_51.py")
    result = subprocess.run(
        [sys.executable, "-I", checker, "--root", tmp_path],
        cwd=tmp_path, capture_output=True, text=True, check=False,
    )
    assert result.returncode != 0
    assert not marker.exists(), "checker must not create the external runner marker"
