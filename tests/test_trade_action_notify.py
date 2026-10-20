"""Native regression tests for trade_action_notify."""

from pathlib import Path
import shutil
import subprocess

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def notify_test_binary(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("notify") / "trade-action-notify-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade_action_notify.cpp",
            "tests/native/trade_action_notify_test.cpp",
            "tests/native/trade_action_notify_support.cpp",
            "src/trade_action_candidates.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


def test_notify_behavior(notify_test_binary):
    result = subprocess.run(
        [str(notify_test_binary)],
        capture_output=True,
        text=True,
        cwd=PROJECT_ROOT,
    )
    assert result.returncode == 0, f"Notify test failed: {result.stderr}\n{result.stdout}"
    assert "TRADE ACTION NOTIFY TEST PASSED" in result.stdout
