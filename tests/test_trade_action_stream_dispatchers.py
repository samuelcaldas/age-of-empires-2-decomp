"""Native semantic regressions for trade_action_stream_dispatchers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00159500 4-byte stream dispatch loop"),
    ("1", "func_00159580 byte 1 dispatch + loop"),
    ("2", "func_00159620 bytes 0,1 dispatch + loop"),
    ("3", "func_001596E0 bytes 0,1,2 dispatch + loop"),
    ("4", "func_001597B0 byte 2 dispatch + loop"),
    ("5", "func_001599D0 bytes 1,2,3 dispatch + loop"),
]


@pytest.fixture(scope="module")
def dispatchers_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("dispatchers") / "trade-action-stream-dispatchers-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_stream_dispatchers.cpp",
         "tests/native/trade_action_stream_dispatchers_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_dispatchers_behavior(dispatchers_test_binary, case, description):
    """Check stream dispatch behavior in isolated native process."""
    result = subprocess.run([str(dispatchers_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"
