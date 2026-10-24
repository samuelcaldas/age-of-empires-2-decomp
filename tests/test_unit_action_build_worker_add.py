"""Native regressions for unit_action_build_worker_add."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026F430 non-matching target invokes func_278D50 without increments",
    "func_0026F430 target unit_class 70 increments building count at offset 366",
    "func_0026F430 target worker_type 42 increments worker count and accumulates rate",
    "func_0026F430 combined matching target increments both counters and rate",
]


@pytest.fixture(scope="module")
def build_worker_add_test(tmp_path_factory):
    """Compile the actual build_worker_add source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_worker_add regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-worker-add")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-worker-add-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_worker_add.cpp",
            "tests/native/unit_action_build_worker_add_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_worker_add_behavior(build_worker_add_test, case):
    """Verify worker counter increments, flag evaluation, and rate accumulation."""
    result = subprocess.run([str(build_worker_add_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
