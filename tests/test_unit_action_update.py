"""Native regressions for unit_action_update methods, state machine, and edge cases."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00268500 negative/zero/positive fields 1C and 20",
    "func_002683F0 state query boundary",
    "func_00268410 routing with field10 and fieldC",
    "func_00268200 state update and Method29/Method30 dispatch",
    "func_00268200 state transitions (0->1, 0->2, descending rejection, 0 reset)",
    "func_00268200 Method61 and Method62 visibility callbacks",
]


@pytest.fixture(scope="module")
def update_test(tmp_path_factory):
    """Compile the actual update source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("update regressions require g++")
    fixture = tmp_path_factory.mktemp("action-update")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "update-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_update.cpp",
            "tests/native/unit_action_update_test.cpp",
            "tests/native/unit_action_update_test_cases.cpp",
            "tests/native/unit_action_update_test_support.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_update_behavior(update_test, case):
    """Verify state transitions, vtable slots, and signed/unsigned field checks."""
    result = subprocess.run([str(update_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
