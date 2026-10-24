"""Native semantic regressions for zone_get_tile_terrain."""

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
    ("active_entry", "Returns terrain type when table entry is marked active"),
    ("fallback_valid", "Returns terrain type when table entry is inactive but has valid fallback (>= 0)"),
    ("fallback_neg", "Returns 0 when table entry is inactive and fallback is negative (< 0)"),
    ("bounds_ge_33", "Returns 0 when tile terrain index is >= 33"),
]


@pytest.fixture(scope="module")
def zone_get_terrain_test_binary(tmp_path_factory):
    """Compile production zone_get_tile_terrain source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-terrain-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-terrain-test"
    sources = [
        "src/zone/zone_get_tile_terrain.cpp",
        "tests/native/zone_get_tile_terrain_test.cpp",
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
def test_zone_get_tile_terrain_cases(zone_get_terrain_test_binary, case, description):
    """Verify tile terrain lookup, table entry active flags, fallbacks, and boundary clamp."""
    result = subprocess.run(
        [str(zone_get_terrain_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
