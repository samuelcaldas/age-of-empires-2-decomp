"""Native semantic regressions for zone_clean_tile_objects."""

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
    ("filter_neg1", "Deletes in-range items via func_1D09C0 when filter < 0 and returns val"),
    ("placement_valid", "When item matches filter table and placement check passes, item is preserved"),
    ("placement_invalid", "When item matches filter table but placement check fails, item is deleted via vtable[31]"),
    ("out_of_range", "Out of range items or empty cells are skipped and return -1"),
]


@pytest.fixture(scope="module")
def zone_clean_objects_test_binary(tmp_path_factory):
    """Compile production zone_clean_tile_objects source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-clean-obj-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-clean-obj-test"
    sources = [
        "src/zone_clean_tile_objects.cpp",
        "tests/native/zone_clean_tile_objects_test.cpp",
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
def test_zone_clean_tile_objects_cases(zone_clean_objects_test_binary, case, description):
    """Verify tile object filtering, range matching, placement checks, and item deletions."""
    result = subprocess.run(
        [str(zone_clean_objects_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
