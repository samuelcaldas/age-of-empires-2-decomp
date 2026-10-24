"""Native semantic regressions for zone_paint_elevation_line."""

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
    ("math_3_4_5", "Verifies 3-4-5 triangle math sequence, float sqrt conversion, and dynamic vtable reloading"),
    ("directions_clipping", "Verifies 4 diagonal directions and boundary clipping to map limits"),
]


@pytest.fixture(scope="module")
def zone_paint_elevation_line_test_binary(tmp_path_factory):
    """Compile production zone_paint_elevation_line source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-paint-elevation-line-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-paint-elevation-line-test"
    sources = [
        "src/zone/zone_paint_elevation_line.cpp",
        "tests/native/zone_paint_elevation_line_test.cpp",
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
def test_zone_paint_elevation_line_cases(zone_paint_elevation_line_test_binary, case, description):
    """Verify elevation line rasterization, math helpers, vtable reload, and clipping."""
    result = subprocess.run(
        [str(zone_paint_elevation_line_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
