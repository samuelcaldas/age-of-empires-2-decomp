"""Native semantic regressions for zone_paint_terrain."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
#include <cstring>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""

CASES = [
    ("box_normal", "Paint centered box with radius 1 replaces 3x3 region with target terrain"),
    ("corner_clamping", "Paint centered at (0,0) clamps bounding box safely to map corner"),
    ("single_cell", "Radius 0 paints exactly one cell"),
    ("full_map", "Large radius paints entire map clamped to boundaries"),
    ("negative_center", "Negative center with sufficient radius paints clamped overlapping region"),
]


@pytest.fixture(scope="module")
def zone_paint_test_binary(tmp_path_factory):
    """Compile production zone_paint_terrain source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-paint-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-paint-terrain-test"
    sources = [
        "src/zone/zone_paint_terrain.cpp",
        "tests/native/zone_paint_terrain_test.cpp",
    ]
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude"] + sources + ["-o", str(binary)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[c[0] for c in CASES])
def test_zone_paint_terrain_cases(zone_paint_test_binary, case, description):
    """Verify terrain rectangle painting, boundary clamping, and single-tile painting."""
    result = subprocess.run(
        [str(zone_paint_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
