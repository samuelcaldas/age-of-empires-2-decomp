"""Native regressions for unit_action_build_80680 (Milestone 151)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00280680 handles empty action list",
    "func_00280680 active count and status 1/3 removal with cleanup order",
    "func_00280680 removes head node correctly",
    "func_280680 alias verification",
]


@pytest.fixture(scope="module")
def build_80680_test(tmp_path_factory):
    """Compile unit_action_build_80680 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_80680 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-80680")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-80680-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_80680.cpp",
            "tests/native/unit_action_build_80680_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_80680_behavior(build_80680_test, case):
    """Verify action list update and cleanup behavior per case."""
    result = subprocess.run([str(build_80680_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
