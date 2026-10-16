"""Native semantic regressions for trade_action_getters7."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "out of bounds negative index returns early"),
    ("1", "out of bounds high index returns early"),
    ("2", "ID 5 negative and positive store"),
    ("3", "BEC == 1 limits execution on negative input"),
    ("4", "ID 0x68 increment resolution with pointer chain"),
    ("5", "ID 0x10 mode 2 scale factor 0.75 yielding 75.0f scaled"),
    ("6", "ID 0xE3 mode 1 scale factor 1.0 yielding 100.0f scaled"),
    ("7", "ID 0x68 increment resolution with mode 2 flag 0 yielding 240"),
]


@pytest.fixture(scope="module")
def getters7_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("getters7") / "trade-action-getters7-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade_action_getters7.cpp",
         "tests/native/trade_action_getters7_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_getters7_behavior(getters7_test_binary, case, description):
    """Check trade_action_getters7 execution in isolated native process."""
    result = subprocess.run(
        [str(getters7_test_binary), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"{description}: {result.stderr}"
