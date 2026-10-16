"""Native semantic regressions for zone_level_elevation."""

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
    ("flat_no_saddle", "Flat terrain without orthogonal saddles leaves all cell elevations untouched"),
    ("saddle_upward", "Orthogonal saddle with elev < limit raises cell elevation by +1"),
    ("downward_leveling", "Orthogonal saddle with elev >= limit levels higher neighbors down to elev"),
    ("iterative_expansion", "Bounding box expands outward iteratively until terrain reaches stability"),
    ("truncation_andi_ff", "max_slope truncation with andi 0xFF preserves equivalence and mask mutation behavior"),
]


@pytest.fixture(scope="module")
def zone_level_test_binary(tmp_path_factory):
    """Compile production zone_level_elevation source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-level-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-level-elevation-test"
    sources = [
        "src/zone_level_elevation.cpp",
        "tests/native/zone_level_elevation_test.cpp",
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
def test_zone_level_elevation_cases(zone_level_test_binary, case, description):
    """Verify terrain saddle leveling, upward raising, and neighbor leveling."""
    result = subprocess.run(
        [str(zone_level_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
