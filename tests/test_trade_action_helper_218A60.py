"""Native semantic regressions for trade_action_helper_218A60."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00218A60 selector 0 and 1 field loading and sub-routine execution"),
    ("1", "func_00218A60 both local120 and s3 null triggers early return"),
]


@pytest.fixture(scope="module")
def helper_218A60_test(tmp_path_factory):
    """Compile trade_action_helper_218A60 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_218A60 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-218A60")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-218A60-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_218A60.cpp",
         "tests/native/trade_action_helper_218A60_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_218A60_behavior(helper_218A60_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_218A60_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
