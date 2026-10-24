"""Native semantic regressions for trade_action_helper_217930."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "no allocation when arg2 is -1 and arg1 is null"),
    ("1", "allocation returns null still calls df80"),
    ("2", "successful allocation and delta calculation"),
    ("3", "cleanup callback mutates arg1 before bypass check"),
]


@pytest.fixture(scope="module")
def helper_217930_test(tmp_path_factory):
    """Compile trade_action_helper_217930 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_217930 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-217930")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-217930-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_helper_217930.cpp",
         "tests/native/trade_action_helper_217930_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_217930_behavior(helper_217930_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_217930_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
