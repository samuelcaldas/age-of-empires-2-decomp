"""Native regressions for zone_raster_untag."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_001CA430 returns early when x0 == x1 and y0 == y1",
    "func_001CA430 returns 0 when coordinates are completely out of bounds",
    "func_001CA430 swaps reversed coordinates and clears flags in range",
    "func_001CA430 clamps coordinates to grid boundaries and clears flags",
]


@pytest.fixture(scope="module")
def raster_untag_test(tmp_path_factory):
    """Compile the actual zone_raster_untag source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("zone_raster_untag regressions require g++")
    fixture = tmp_path_factory.mktemp("raster-untag")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "raster-untag-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/zone/zone_raster_untag.cpp",
            "tests/native/zone_raster_untag_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_raster_untag_behavior(raster_untag_test, case):
    """Verify raster untag bounds checking, coordinate swapping, and bitmasking."""
    result = subprocess.run([str(raster_untag_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
