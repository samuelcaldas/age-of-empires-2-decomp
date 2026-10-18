"""Native regressions for unit_action_build_7b700 (Milestone 136)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027B700 early exit on zero count",
    "func_0027B700 early exit on no free slot in event pool",
    "func_0027B700 successful event node insertion and type 0xB dispatch",
]


@pytest.fixture(scope="module")
def build_7b700_test(tmp_path_factory):
    """Compile unit_action_build_7b700 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7b700 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7b700")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7b700-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_7b700.cpp",
            "tests/native/unit_action_build_7b700_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7b700_behavior(build_7b700_test, case):
    """Verify CombatManager event insertion and dispatch."""
    result = subprocess.run([str(build_7b700_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
