"""Native semantic regressions for zone_calc_tile_slope."""

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
    ("flat", "Flat terrain tile surrounded by equal elevations returns slope 0"),
    ("cardinal", "Evaluates cardinal slope indices 5 (W), 6 (N), 7 (S), 8 (E)"),
    ("corner", "Evaluates corner slope indices 13 (W+S), 14 (N+E), 15 (E+S), 16 (N+W)"),
    ("oob", "Out-of-bounds coordinates immediately return slope index 0"),
]


@pytest.fixture(scope="module")
def zone_calc_slope_test_binary(tmp_path_factory):
    """Compile production zone_calc_tile_slope source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-calc-slope-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-calc-slope-test"
    sources = [
        "src/zone_calc_tile_slope.cpp",
        "tests/native/zone_calc_tile_slope_test.cpp",
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
def test_zone_calc_tile_slope_cases(zone_calc_slope_test_binary, case, description):
    """Verify tile slope evaluation across cardinal, corner, and boundary conditions."""
    result = subprocess.run(
        [str(zone_calc_slope_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
