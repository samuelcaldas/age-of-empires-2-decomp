"""Native regressions for unit_action_build_7ba90 (Milestone 139)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027BA90 base constructor invocation",
    "func_0027BAD0 full 14-descriptor and 14-code table initialization",
    "func_0027BAC0 tail-call delegation to func_0027BAD0",
]


@pytest.fixture(scope="module")
def build_7ba90_test(tmp_path_factory):
    """Compile unit_action_build_7ba90 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7ba90 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7ba90")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7ba90-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_7ba90.cpp",
            "tests/native/unit_action_build_7ba90_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7ba90_behavior(build_7ba90_test, case):
    """Verify CombatManager table initialization and constructor delegation."""
    result = subprocess.run([str(build_7ba90_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
