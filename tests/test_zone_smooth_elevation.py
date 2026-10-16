"""Native semantic regressions for zone_smooth_elevation."""

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
    ("flat_no_mod", "Flat terrain without slope violations returns modified=0 with elevations unchanged"),
    ("eight_neighbors", "Smoothing upward (+1) is triggered across all 8 cardinal and diagonal neighbors"),
    ("downward", "Smoothing downward (-1) is triggered when neighboring elevation is too steep downward"),
    ("corners_expansion", "Bounding box expands outward by 1 tile correctly smoothing grid corners and borders"),
]


@pytest.fixture(scope="module")
def zone_smooth_test_binary(tmp_path_factory):
    """Compile production zone_smooth_elevation source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-smooth-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-smooth-elevation-test"
    sources = [
        "src/zone_smooth_elevation.cpp",
        "tests/native/zone_smooth_elevation_test.cpp",
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
def test_zone_smooth_elevation_cases(zone_smooth_test_binary, case, description):
    """Verify terrain slope smoothing across 8 directions, corners, and both up/down deltas."""
    result = subprocess.run(
        [str(zone_smooth_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
