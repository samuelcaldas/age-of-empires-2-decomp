"""Native semantic regressions for zone_spawn_terrain_objects."""

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
    ("multi_center", "Spawns centered objects via mode 1 and multi-spawn density loop"),
    ("single_jitter", "Spawns jittered objects via mode 0 and flag_single_spawn = 1"),
    ("collision_skip", "Skips entity spawn when placement collision check fails"),
]


@pytest.fixture(scope="module")
def zone_spawn_objects_test_binary(tmp_path_factory):
    """Compile production zone_spawn_terrain_objects source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-spawn-obj-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-spawn-obj-test"
    sources = [
        "src/zone_spawn_terrain_objects.cpp",
        "tests/native/zone_spawn_terrain_objects_test.cpp",
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
def test_zone_spawn_terrain_objects_cases(zone_spawn_objects_test_binary, case, description):
    """Verify terrain object spawning, mode calculations, density looping, and collision check."""
    result = subprocess.run(
        [str(zone_spawn_objects_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
