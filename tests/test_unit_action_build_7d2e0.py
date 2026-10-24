"""Native regressions for unit_action_build_7d2e0 (Milestone 143)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027D2E0 exhaustive verification of all 44 action code mappings",
    "func_0027D2E0 verification of unhandled action codes returning 0",
    "func_27D2E0 alias verification",
]


@pytest.fixture(scope="module")
def build_7d2e0_test(tmp_path_factory):
    """Compile unit_action_build_7d2e0 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7d2e0 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7d2e0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7d2e0-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_7d2e0.cpp",
            "tests/native/unit_action_build_7d2e0_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7d2e0_behavior(build_7d2e0_test, case):
    """Verify exhaustive action code mappings per case."""
    result = subprocess.run([str(build_7d2e0_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
