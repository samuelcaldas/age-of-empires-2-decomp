"""Native semantic regressions for zone_generate_terrain_objects."""

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
    ("mode1_center_del0", "Places centered objects via mode 1 and deletes invalid items via func_1D09C0"),
    ("jitter_delete1", "Places jittered objects via mode 0 and deletes invalid items via vtable[31]"),
    ("filter_skip", "When existing item matches filter table entry, skips item deletion"),
]


@pytest.fixture(scope="module")
def zone_gen_objects_test_binary(tmp_path_factory):
    """Compile production zone_generate_terrain_objects source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-gen-obj-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-gen-obj-test"
    sources = [
        "src/zone/zone_generate_terrain_objects.cpp",
        "tests/native/zone_generate_terrain_objects_test.cpp",
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
def test_zone_generate_terrain_objects_cases(zone_gen_objects_test_binary, case, description):
    """Verify object filtering, placement check, random jitter, and spawning."""
    result = subprocess.run(
        [str(zone_gen_objects_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
