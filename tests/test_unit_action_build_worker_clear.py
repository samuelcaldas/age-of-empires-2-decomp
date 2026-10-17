"""Native regressions for unit_action_build_worker_clear."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270530 clears total, increments generation, frees list, and calls func_0026FF60 on empty action",
    "func_00270530 releases all workers across multiple slots and reduces rates",
    "func_00270530 dispatches Method17 notification when m_field154 is active",
]


@pytest.fixture(scope="module")
def build_worker_clear_test(tmp_path_factory):
    """Compile the actual build_worker_clear source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_worker_clear regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-worker-clear")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-worker-clear-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_worker_clear.cpp",
            "tests/native/unit_action_build_worker_clear_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_worker_clear_behavior(build_worker_clear_test, case):
    """Verify complete worker release, list freeing, stat clearing, and notification."""
    result = subprocess.run([str(build_worker_clear_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
