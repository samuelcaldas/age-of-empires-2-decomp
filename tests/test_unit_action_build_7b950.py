"""Native regressions for unit_action_build_7b950 (Milestone 138)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027B950 quota check and event insertion when under 4 nodes",
    "func_0027B950 event pruning of lowest candidate when at quota",
    "func_0027B950 new event purge when no lower candidate found",
]


@pytest.fixture(scope="module")
def build_7b950_test(tmp_path_factory):
    """Compile unit_action_build_7b950 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7b950 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7b950")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7b950-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_7b950.cpp",
            "tests/native/unit_action_build_7b950_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7b950_behavior(build_7b950_test, case):
    """Verify CombatManager event pruning and quota enforcement."""
    result = subprocess.run([str(build_7b950_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
