"""Native semantic regressions for zone_calc_subtile_screen_coords."""

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
    ("projection_flow", "Projects world sub-tile coordinates (x, y, z) into screen pixel coordinates"),
    ("flat", "Flat origin coordinates (0, 0, 0) project cleanly to origin screen offsets"),
]


@pytest.fixture(scope="module")
def zone_calc_coords_test_binary(tmp_path_factory):
    """Compile production zone_calc_subtile_screen_coords source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-calc-coords-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-calc-coords-test"
    sources = [
        "src/zone_calc_subtile_screen_coords.cpp",
        "tests/native/zone_calc_subtile_screen_coords_test.cpp",
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
def test_zone_calc_subtile_screen_coords_cases(zone_calc_coords_test_binary, case, description):
    """Verify subtile screen coordinate projection, tile half dimensions, and rounding."""
    result = subprocess.run(
        [str(zone_calc_coords_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
