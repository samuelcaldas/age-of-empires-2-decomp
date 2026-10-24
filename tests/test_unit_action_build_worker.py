"""Native regressions for unit_action_build_worker."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026E9C0 and func_0026EAB0 guard checks on null inputs",
    "func_0026E9C0 tile queries, world notifications, and flag mutations",
    "func_0026EAB0 subaction recursion and worker update",
]


@pytest.fixture(scope="module")
def build_worker_test(tmp_path_factory):
    """Compile the actual build_worker source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_worker regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-worker")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-worker-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_worker.cpp",
            "tests/native/unit_action_build_worker_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_worker_behavior(build_worker_test, case):
    """Verify tile updates, world notifications, and subaction recursion."""
    result = subprocess.run([str(build_worker_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
