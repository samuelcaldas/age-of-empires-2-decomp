"""Native regressions for unit_action_build_7e4a0 (Milestone 146)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_27E4A0 exhaustive verification of all 113 action configurations",
    "func_27E4A0 verification of unhandled category",
    "func_0027E4A0 alias verification",
]


@pytest.fixture(scope="module")
def build_7e4a0_test(tmp_path_factory):
    """Compile unit_action_build_7e4a0 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7e4a0 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7e4a0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7e4a0-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "-I.",
            "src/unit/unit_action_build_7e4a0.cpp",
            "tests/native/unit_action_build_7e4a0_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7e4a0_behavior(build_7e4a0_test, case):
    """Verify action descriptor registration per case."""
    result = subprocess.run([str(build_7e4a0_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
