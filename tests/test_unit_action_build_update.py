"""Native regressions for unit_action_build_update."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026D010 guard checks on null inputs",
    "func_0026D010 execution flow, footprint update, and completion",
    "func_0026D010 cleanup and notification callbacks",
]


@pytest.fixture(scope="module")
def build_update_test(tmp_path_factory):
    """Compile the actual build_update source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_update regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-update")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-update-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_update.cpp",
            "tests/native/unit_action_build_update_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_update_behavior(build_update_test, case):
    """Verify build update logic, footprint calculation, and cleanup."""
    result = subprocess.run([str(build_update_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
