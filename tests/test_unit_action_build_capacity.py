"""Native regressions for unit_action_build_capacity."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00271460 returns 0 when func_00268500 returns 0",
    "func_00271460 computes difference between func_00268530 and field 366",
    "func_00271460 handles exact match resulting in zero delta",
]


@pytest.fixture(scope="module")
def build_capacity_test(tmp_path_factory):
    """Compile actual build_capacity source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_capacity regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-capacity")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-capacity-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_capacity.cpp",
            "tests/native/unit_action_build_capacity_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_capacity_behavior(build_capacity_test, case):
    """Verify guard check and field 366 capacity subtraction."""
    result = subprocess.run([str(build_capacity_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
