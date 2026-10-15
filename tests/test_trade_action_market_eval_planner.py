"""Native regressions for the planner's object ABI and candidate state machine."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "target object layout",
    "virtual call arguments",
    "unlimited allied search resets target",
    "limited allied search visits both targets",
    "candidate below limit is accepted",
    "candidate at limit is rejected",
    "visited history stops at one hundred",
    "failed dispatch stops at thirty",
    "retry flag changes after failed dispatch",
]


@pytest.fixture(scope="module")
def planner_test(tmp_path_factory):
    """Build the actual planner with 32-bit native call-recording doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("planner regressions require g++")
    binary = tmp_path_factory.mktemp("market-planner") / "planner-test"
    subprocess.run(
        [compiler, "-m32", "-Wno-invalid-offsetof",
         "-Iinclude", "tests/native/trade_action_market_eval_planner_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_planner_behavior(planner_test, case):
    """Run each reference-derived behavior in its own process."""
    result = subprocess.run(
        [str(planner_test), str(case)], capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stderr
