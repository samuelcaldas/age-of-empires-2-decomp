"""Native regressions for unit_action_build_dispatch."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270F80 flag57 non-zero skips world check and completes dispatch",
    "func_00270F80 f368 non-zero skips world check and completes dispatch",
    "func_00270F80 world check null return aborts before retry reset and dispatch",
    "func_00270F80 successful dual world check completes reset and dispatch",
]


@pytest.fixture(scope="module")
def build_dispatch_test(tmp_path_factory):
    """Compile actual build_dispatch source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_dispatch regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-dispatch")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-dispatch-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_dispatch.cpp",
            "tests/native/unit_action_build_dispatch_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_dispatch_behavior(build_dispatch_test, case):
    """Verify flag guards, dual method36 world validation, and delegating dispatch."""
    result = subprocess.run([str(build_dispatch_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
