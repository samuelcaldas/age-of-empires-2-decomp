"""Native semantic regressions for zone_set_tile_terrain."""

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
    ("terrain_flow", "Updates tile terrain byte, fires raster/LOS, unlinks old entities and spawns new entities"),
    ("same_terrain", "When target terrain matches existing terrain, immediately returns without side effects"),
]


@pytest.fixture(scope="module")
def zone_set_terrain_test_binary(tmp_path_factory):
    """Compile production zone_set_tile_terrain source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-set-terrain-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-set-terrain-test"
    sources = [
        "src/zone/zone_set_tile_terrain.cpp",
        "tests/native/zone_set_tile_terrain_test.cpp",
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
def test_zone_set_tile_terrain_cases(zone_set_terrain_test_binary, case, description):
    """Verify single tile terrain mutation, entity re-generation, and early return guards."""
    result = subprocess.run(
        [str(zone_set_terrain_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
