"""Native regressions for unit_action_build_7da10 (Milestone 144)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027DA10 exhaustive verification of all 66 action code mappings",
    "func_0027DA10 verification of unhandled action codes returning 0",
    "func_27DA10 alias verification",
]


@pytest.fixture(scope="module")
def build_7da10_test(tmp_path_factory):
    """Compile unit_action_build_7da10 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7da10 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7da10")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7da10-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_7da10.cpp",
            "tests/native/unit_action_build_7da10_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7da10_behavior(build_7da10_test, case):
    """Verify exhaustive action code mappings per case."""
    result = subprocess.run([str(build_7da10_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
