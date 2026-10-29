"""Native semantic regressions for trade_action_destination."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0014BEF0 returns -1"),
    ("1", "func_0014BEE0 notifies 0"),
    ("2", "func_0014BE10 computes randomized destination interval"),
    ("3", "func_0014BE70 clamps value < 1000"),
    ("4", "func_0014BE70 processes value > 1000"),
]


@pytest.fixture(scope="module")
def destination_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("dest") / "trade-action-destination-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_destination.cpp",
         "tests/native/trade_action_destination_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_destination_behavior(destination_test_binary, case, description):
    """Check destination calculation in isolated native process."""
    result = subprocess.run([str(destination_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"
