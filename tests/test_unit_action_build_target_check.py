"""Native regressions for unit_action_build_target_check."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270F80 field39 non-zero bypasses visibility checks and dispatches",
    "func_00270F80 field170 non-zero bypasses visibility checks and dispatches",
    "func_00270F80 actor visibility check failure aborts without dispatch",
    "func_00270F80 target view visibility check failure aborts without dispatch",
    "func_00270F80 successful mutual visibility checks execute retry reset and dispatch",
]


@pytest.fixture(scope="module")
def build_target_check_test(tmp_path_factory):
    """Compile the actual build_target_check source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_target_check regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-target-check")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-target-check-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_target_check.cpp",
            "tests/native/unit_action_build_target_check_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_target_check_behavior(build_target_check_test, case):
    """Verify field 39/170 gates, dual visibility checks, and forwarding to func_264450."""
    result = subprocess.run([str(build_target_check_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
