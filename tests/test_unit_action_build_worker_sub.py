"""Native regressions for unit_action_build_worker_sub."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026F4E0 non-matching target invokes func_278E20 without decrements",
    "func_0026F4E0 target unit_class 70 decrements building count at offset 366",
    "func_0026F4E0 target worker_type 42 decrements worker count and subtracts rate",
    "func_0026F4E0 combined matching target decrements both counters and rate",
]


@pytest.fixture(scope="module")
def build_worker_sub_test(tmp_path_factory):
    """Compile the actual build_worker_sub source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_worker_sub regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-worker-sub")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-worker-sub-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_worker_sub.cpp",
            "tests/native/unit_action_build_worker_sub_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_worker_sub_behavior(build_worker_sub_test, case):
    """Verify worker counter decrements, flag evaluation, and rate reduction."""
    result = subprocess.run([str(build_worker_sub_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
