"""Native regressions for unit_action_build_target_check4."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00271150 field39 non-zero bypasses visibility checks and forwards 4 args",
    "func_00271150 field170 non-zero bypasses visibility checks and forwards 4 args",
    "func_00271150 actor visibility check failure aborts without forwarding",
    "func_00271150 target view visibility check failure aborts without forwarding",
    "func_00271150 successful mutual visibility checks forward 4 args to func_2647C0",
]


@pytest.fixture(scope="module")
def build_target_check4_test(tmp_path_factory):
    """Compile the actual build_target_check4 source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_target_check4 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-target-check4")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-target-check4-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_target_check4.cpp",
            "tests/native/unit_action_build_target_check4_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_target_check4_behavior(build_target_check4_test, case):
    """Verify field 39/170 gates, dual visibility checks, and forwarding to func_2647C0."""
    result = subprocess.run([str(build_target_check4_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
