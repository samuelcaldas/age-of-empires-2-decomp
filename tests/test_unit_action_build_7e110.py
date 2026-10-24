"""Native regressions for unit_action_build_7e110 (Milestone 145)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027E110 null pointer handling and initial category search",
    "func_0027E110 exhaustive category search and not-found fallbacks",
    "func_27E110 alias verification",
]


@pytest.fixture(scope="module")
def build_7e110_test(tmp_path_factory):
    """Compile unit_action_build_7e110 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7e110 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7e110")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7e110-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_7e110.cpp",
            "tests/native/unit_action_build_7e110_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7e110_behavior(build_7e110_test, case):
    """Verify action code reverse lookup and category search."""
    result = subprocess.run([str(build_7e110_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
