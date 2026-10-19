"""Native regression tests for trade_action_plan_evaluator."""

from pathlib import Path
import shutil
import subprocess

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def plan_evaluator_binary(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("plan_eval") / "trade-action-plan-eval-test"
    result = subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade_action_plan_evaluator.cpp",
            "tests/native/trade_action_plan_evaluator_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, result.stderr
    return binary


def test_plan_evaluator_behavior(plan_evaluator_binary):
    result = subprocess.run(
        [str(plan_evaluator_binary)],
        capture_output=True,
        text=True,
        cwd=PROJECT_ROOT,
    )
    assert result.returncode == 0, f"Plan evaluator test failed: {result.stderr}\n{result.stdout}"
    assert "TRADE ACTION PLAN EVALUATOR TEST PASSED" in result.stdout
