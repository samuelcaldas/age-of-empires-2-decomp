"""Behavioral regression tests for trade_action_navigation."""
import shutil
import subprocess
from pathlib import Path
import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_trade_action_navigation_behavior(tmp_path):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path / "test_bin"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "tests/native/trade_action_navigation_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True
    )
    res = subprocess.run([str(binary)], cwd=PROJECT_ROOT, check=True, capture_output=True, text=True)
    assert "All trade_action_navigation tests passed!" in res.stdout
