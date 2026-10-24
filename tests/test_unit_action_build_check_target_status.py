"""Native regressions for unit_action_build_check_target_status."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00271500 master field E not equal to 39 returns 0 immediately",
    "func_00271500 master field 1A2 equal to -1 returns 0 immediately",
    "func_00271500 flag 2000 active returns 0",
    "func_00271500 actor targeting check failure returns 0",
    "func_00271500 successful mutual target player validation returns 1",
]


@pytest.fixture(scope="module")
def build_check_target_status_test(tmp_path_factory):
    """Compile the actual build_check_target_status source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_check_target_status regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-check-target-status")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-check-target-status-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_check_target_status.cpp",
            "tests/native/unit_action_build_check_target_status_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_check_target_status_behavior(build_check_target_status_test, case):
    """Verify master field E/1A2 filters, flag 2000, and mutual player targeting check."""
    result = subprocess.run([str(build_check_target_status_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
