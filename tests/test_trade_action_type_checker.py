"""Native regression tests for trade_action_type_checker."""

from pathlib import Path
import shutil
import subprocess

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def type_checker_binary(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("type_checker") / "trade-action-type-checker-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade_action_type_checker.cpp",
            "tests/native/trade_action_type_checker_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


def test_type_checker_behavior(type_checker_binary):
    result = subprocess.run(
        [str(type_checker_binary)],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"type checker failed:\nstdout:\n{result.stdout}\nstderr:\n{result.stderr}"
    assert "TRADE ACTION TYPE CHECKER TEST PASSED" in result.stdout
