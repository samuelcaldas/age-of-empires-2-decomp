"""Native regressions for unit_action_build_task_remove."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026FFB0 returns early without loop when count is zero",
    "func_0026FFB0 partially decrements slot amount and total without removal",
    "func_0026FFB0 completely removes slot, shifts remaining slots left, and decrements count",
    "func_0026FFB0 removal of slot zero dispatches Method17 and frees list 0x14C",
]


@pytest.fixture(scope="module")
def build_task_remove_test(tmp_path_factory):
    """Compile the actual build_task_remove source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_task_remove regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-task-remove")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-task-remove-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_task_remove.cpp",
            "tests/native/unit_action_build_task_remove_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_task_remove_behavior(build_task_remove_test, case):
    """Verify task decrement, slot removal, list shifting, and slot zero notifications."""
    result = subprocess.run([str(build_task_remove_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
