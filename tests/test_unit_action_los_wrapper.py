"""Native regressions for unit_action_los_wrapper."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026D960 with flag 0x4000 clear overrides a2 = 1",
    "func_0026D960 with flag 0x4000 set and even extents overrides a4 = 1",
    "func_0026DA20 remove LOS with flag clear preserves a4",
    "func_0026DA20 remove LOS with flag set and even extents overrides a4 = 1",
]


@pytest.fixture(scope="module")
def los_wrapper_test(tmp_path_factory):
    """Compile the actual los_wrapper source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("los_wrapper regressions require g++")
    fixture = tmp_path_factory.mktemp("action-los-wrapper")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "los-wrapper-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_los_wrapper.cpp",
            "tests/native/unit_action_los_wrapper_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_los_wrapper_behavior(los_wrapper_test, case):
    """Verify LOS add/remove wrappers, flag 0x4000 handling, and extent parity."""
    result = subprocess.run([str(los_wrapper_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
