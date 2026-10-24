"""Native semantic regressions for zone_update_elevation_rect."""

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
    ("elevation_flow", "Clamps bounds, modifies cell elevation, re-elevates entities, updates LOS and raster"),
    ("clamp_bounds", "Clamps elevation strictly within [0, 8] range on underflow and overflow"),
    ("mode3_skip", "When world mode is 3 (map generator / editor), skips player LOS visibility update"),
]


@pytest.fixture(scope="module")
def zone_update_elev_test_binary(tmp_path_factory):
    """Compile production zone_update_elevation_rect source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-update-elev-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-update-elev-test"
    sources = [
        "src/zone/zone_update_elevation_rect.cpp",
        "tests/native/zone_update_elevation_rect_test.cpp",
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
def test_zone_update_elevation_rect_cases(zone_update_elev_test_binary, case, description):
    """Verify elevation rect update, bounds clamping, slope recalculation, and entity adjustments."""
    result = subprocess.run(
        [str(zone_update_elev_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
