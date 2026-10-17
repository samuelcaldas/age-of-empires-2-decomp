"""Native regressions for unit_action_build_worker_task."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026FCC0 triggers Method17 notification and returns 0 when total >= 15",
    "func_0026FCC0 clamps requested amount to 15 - total when sum exceeds 15",
    "func_0026FCC0 merges amount into existing slot when task_id matches previous",
    "func_0026FCC0 expands buffer by 15 slots and appends new task slot",
]


@pytest.fixture(scope="module")
def build_worker_task_test(tmp_path_factory):
    """Compile the actual build_worker_task source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_worker_task regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-worker-task")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-worker-task-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_worker_task.cpp",
            "tests/native/unit_action_build_worker_task_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_worker_task_behavior(build_worker_task_test, case):
    """Verify task capacity enforcement, allocation clamping, slot merging, and dynamic growth."""
    result = subprocess.run([str(build_worker_task_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
