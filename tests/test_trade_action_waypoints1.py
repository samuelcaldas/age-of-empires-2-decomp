"""Behavioral tests for trade_action_waypoints1."""
import shutil
import subprocess
from pathlib import Path
import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_trade_action_waypoints1_behavior(tmp_path):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path / "test_bin"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/trade/trade_action_waypoints1.cpp",
            "tests/native/trade_action_waypoints1_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True
    )
    res = subprocess.run([str(binary)], cwd=PROJECT_ROOT, check=True, capture_output=True, text=True)
    assert "All tests passed!" in res.stdout
