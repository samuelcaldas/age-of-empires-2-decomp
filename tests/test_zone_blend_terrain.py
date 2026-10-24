"""Native semantic regressions for zone_blend_terrain."""

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
    ("matching_no_op", "Cells already matching target terrain produce zero replacements"),
    ("orthogonal_saddle", "Orthogonal saddle of target terrain triggers replacement via func_1CF830"),
    ("corner_diagonal", "Corner diagonal notch triggers replacement via func_1CF830"),
    ("bounds_clamping", "Out-of-bounds bounding box coordinates are safely clamped to map boundaries"),
    ("truncation_andi_ff", "terrain_param truncation with andi 0xFF preserves bit-identical behavior"),
]


@pytest.fixture(scope="module")
def zone_blend_test_binary(tmp_path_factory):
    """Compile production zone_blend_terrain source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-blend-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-blend-terrain-test"
    sources = [
        "src/zone/zone_blend_terrain.cpp",
        "tests/native/zone_blend_terrain_test.cpp",
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
def test_zone_blend_terrain_cases(zone_blend_test_binary, case, description):
    """Verify terrain blending smoothing across orthogonal bottlenecks and diagonal notches."""
    result = subprocess.run(
        [str(zone_blend_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
