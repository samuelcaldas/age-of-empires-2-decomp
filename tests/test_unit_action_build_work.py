"""Native regressions for unit_action_build_work."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00271640 invalid master field1A2 returns early",
    "func_00271640 non-working state returns early",
    "func_00271640 flag 2000 active and positive 3675D0 returns early",
    "func_00271640 positive 3675D0 triggers Method140 and resets timer",
    "func_00271640 non-positive timer resets to 0.5s",
    "func_00271640 timer countdown triggers Method13C on expiry",
    "func_00271640 timer countdown decrements without triggering Method13C",
]


@pytest.fixture(scope="module")
def build_work_test(tmp_path_factory):
    """Compile unit_action_build_work with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_work regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-work")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-work-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_work.cpp",
            "tests/native/unit_action_build_work_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_work_behavior(build_work_test, case):
    """Verify build work state handling, timer logic, and callback dispatches."""
    result = subprocess.run([str(build_work_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
