"""Native semantic regressions for trade_action_helper_2194D0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_002194D0 empty list returns -1 without calling 219430"),
    ("1", "func_002194D0 match at index 0 returns 0 and calls 219430"),
    ("2", "func_002194D0 match at index 2 returns 2 and calls 219430"),
    ("3", "func_002194D0 no match found returns -1 without calling 219430"),
]


@pytest.fixture(scope="module")
def helper_2194D0_test(tmp_path_factory):
    """Compile trade_action_helper_2194D0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_2194D0 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-2194D0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-2194D0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_helper_2194D0.cpp",
         "tests/native/trade_action_helper_2194D0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_2194D0_behavior(helper_2194D0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_2194D0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
