"""Native semantic regressions for zone_paint_terrain_rect."""

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
    ("paint_rect", "Paints rectangular terrain region, triggers entity generation, and updates raster"),
    ("oob_terrain", "When terrain type index exceeds max_terrain, immediately aborts without side effects"),
]


@pytest.fixture(scope="module")
def zone_paint_rect_test_binary(tmp_path_factory):
    """Compile production zone_paint_terrain_rect source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-paint-rect-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-paint-rect-test"
    sources = [
        "src/zone/zone_paint_terrain_rect.cpp",
        "tests/native/zone_paint_terrain_rect_test.cpp",
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
def test_zone_paint_terrain_rect_cases(zone_paint_rect_test_binary, case, description):
    """Verify rectangular terrain painting, bounds clamping, entity regeneration, and raster update."""
    result = subprocess.run(
        [str(zone_paint_rect_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
