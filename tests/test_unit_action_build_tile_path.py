"""Native regressions for unit_action_build_tile_path."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00271220 class 80 unit with flag 800 within bounding radius invokes func_0026E750",
    "func_00271220 non-80 unit class is ignored even if overlapping",
    "func_00271220 class 80 unit lacking flag 800 is ignored",
    "func_00271220 distance exceeding combined radius threshold is ignored",
    "func_00271220 empty tiles and coordinate clamping operate safely",
]


@pytest.fixture(scope="module")
def build_tile_path_test(tmp_path_factory):
    """Compile the actual build_tile_path source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_tile_path regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-tile-path")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-tile-path-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_tile_path.cpp",
            "tests/native/unit_action_build_tile_path_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_tile_path_behavior(build_tile_path_test, case):
    """Verify 5-tile radius expansion, class 80 filtering, flag 0x800 check, and neighbor notification."""
    result = subprocess.run([str(build_tile_path_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
