"""Native semantic regressions for trade_action_helper_218350."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00218350 early guards return early when fields are null and clear 0x38"),
    ("1", "func_00218350 exact chronological event sequence, fn120 args, and multi-iteration loops"),
    ("2", "func_00218350 flag80 single iteration branch with param4=0"),
    ("3", "func_00218350 null aba00 result skips aba70 cleanup"),
    ("4", "func_00218350 callback manager mutation and reload propagation"),
    ("5", "func_00218350 dynamic mutation of limit during loop iteration"),
    ("6", "func_00218350 dynamic vtable and flags mutation during loop iteration"),
]


@pytest.fixture(scope="module")
def helper_218350_test(tmp_path_factory):
    """Compile trade_action_helper_218350 with test harness, support, extra, more, and header."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_218350 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-218350")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-218350-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", "-Itests/native",
         "src/trade/trade_action_helper_218350.cpp",
         "tests/native/trade_action_helper_218350_support.cpp",
         "tests/native/trade_action_helper_218350_test.cpp",
         "tests/native/trade_action_helper_218350_test_extra.cpp",
         "tests/native/trade_action_helper_218350_test_more.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_218350_behavior(helper_218350_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_218350_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
