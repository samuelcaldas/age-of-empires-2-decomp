"""Native semantic regressions for zone_filter_elevation."""

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
    ("flat_no_mod", "Flat terrain without corner saddles invokes callback once and leaves elevations unchanged"),
    ("corner_saddle_upward", "Corner saddle with elev < limit raises cell elevation upward"),
    ("corner_saddle_downward", "Corner saddle with elev >= limit levels higher neighbors down to elev"),
    ("bounds_clamping", "Out-of-bounds input coords are safely clamped to map boundaries and passed to callback"),
    ("truncation_andi_ff", "max_slope truncation with andi 0xFF preserves equivalence and mutation behavior"),
]


@pytest.fixture(scope="module")
def zone_filter_test_binary(tmp_path_factory):
    """Compile production zone_filter_elevation source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-filter-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-filter-elevation-test"
    sources = [
        "src/zone/zone_filter_elevation.cpp",
        "src/zone/zone_level_elevation.cpp",
        "src/zone/zone_smooth_elevation.cpp",
        "tests/native/zone_filter_elevation_test.cpp",
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
def test_zone_filter_elevation_cases(zone_filter_test_binary, case, description):
    """Verify integrated terrain filter pipeline, corner saddles, and callback propagation."""
    result = subprocess.run(
        [str(zone_filter_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
