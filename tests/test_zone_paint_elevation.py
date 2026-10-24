"""Native semantic regressions for zone_paint_elevation."""

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
    ("box_normal", "Paints rectangular elevation box with radius 1 centered at (3,3) returning 1"),
    ("corner_clamping", "Paints elevation box at corner (0,0) clamped safely within map boundaries"),
    ("single_tile", "Radius 0 paints exactly one tile elevation returning 1"),
    ("full_map", "Large radius paints entire map clamped to bounds returning 1"),
    ("negative_center", "Negative center with sufficient radius paints overlapping region returning 1"),
]


@pytest.fixture(scope="module")
def zone_paint_elevation_test_binary(tmp_path_factory):
    """Compile production zone_paint_elevation source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-paint-elevation-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-paint-elevation-test"
    sources = [
        "src/zone/zone_paint_elevation.cpp",
        "tests/native/zone_paint_elevation_test.cpp",
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
def test_zone_paint_elevation_cases(zone_paint_elevation_test_binary, case, description):
    """Verify elevation rectangle painting, boundary clamping, and single-tile painting."""
    result = subprocess.run(
        [str(zone_paint_elevation_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
