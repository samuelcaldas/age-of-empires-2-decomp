"""Native regressions for unit_action_build_task_compact."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_002701D0 returns early without loop when count is zero",
    "func_002701D0 decrements worker in slot 0 and updates total",
    "func_002701D0 locates and decrements worker in slot 1 across cumulative count",
    "func_002701D0 worker 0 slot depletion dispatches Method17 and frees list 0x14C",
]


@pytest.fixture(scope="module")
def build_task_compact_test(tmp_path_factory):
    """Compile the actual build_task_compact source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_task_compact regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-task-compact")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-task-compact-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_task_compact.cpp",
            "tests/native/unit_action_build_task_compact_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_task_compact_behavior(build_task_compact_test, case):
    """Verify cumulative worker lookup, slot decrement, slot removal, and slot 0 notification."""
    result = subprocess.run([str(build_task_compact_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
