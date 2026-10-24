"""Native semantic regressions for trade_action_helper_21AE90."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021AE90 target flags and type checks"),
    ("1", "func_0021AE90 bounding and overlap validation"),
    ("2", "func_0021AE90 clipping and dispatch to func_0021B130"),
]


@pytest.fixture(scope="module")
def helper_21AE90_test(tmp_path_factory):
    """Compile trade_action_helper_21AE90 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_21AE90 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21AE90")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21AE90-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_helper_21AE90.cpp",
         "tests/native/trade_action_helper_21AE90_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21AE90_behavior(helper_21AE90_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21AE90_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
