"""Native semantic regressions for trade_action_getters6."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "INT_MIN index returns -1"),
    ("1", "-1 index returns -1"),
    ("2", "index 0 returns correct table entry"),
    ("3", "index 238 returns correct table entry"),
    ("4", "index 239 out of bounds returns -1"),
    ("5", "INT_MAX index returns -1"),
]


@pytest.fixture(scope="module")
def getters6_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("getters6") / "trade-action-getters6-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade_action_getters6.cpp",
         "tests/native/trade_action_getters6_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_getters6_behavior(getters6_test_binary, case, description):
    """Check bounds checking and table lookup behavior in isolated native process."""
    result = subprocess.run(
        [str(getters6_test_binary), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"{description}: {result.stderr}"
