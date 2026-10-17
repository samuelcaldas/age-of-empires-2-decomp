"""Native semantic regressions for trade_action_helper_21A780."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021A780 flag 0x800 overrides arg5 from func_0021AE90"),
    ("1", "func_0021A780 default flags with arg2 calls func_0021ACD0 and func_0021AD70"),
    ("2", "func_0021A780 default flags with null arg2 skips func_0021ACD0"),
]


@pytest.fixture(scope="module")
def helper_21A780_test(tmp_path_factory):
    """Compile trade_action_helper_21A780 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_21A780 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21A780")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21A780-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_21A780.cpp",
         "tests/native/trade_action_helper_21A780_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21A780_behavior(helper_21A780_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21A780_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
