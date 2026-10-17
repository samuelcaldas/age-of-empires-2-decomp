"""Native semantic regressions for zone_free_spatial_grid."""

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
    ("teardown", "Iterates 4 search bucket levels, deallocates sub-buffers, frees table, and clears flag"),
    ("uninit", "When grid is not initialized (flag 0), immediately returns without freeing memory"),
]


@pytest.fixture(scope="module")
def zone_free_grid_test_binary(tmp_path_factory):
    """Compile production zone_free_spatial_grid source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-free-grid-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-free-grid-test"
    sources = [
        "src/zone_free_spatial_grid.cpp",
        "tests/native/zone_free_spatial_grid_test.cpp",
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
def test_zone_free_spatial_grid_cases(zone_free_grid_test_binary, case, description):
    """Verify spatial search grid deallocation, bucket buffer release, and state clearing."""
    result = subprocess.run(
        [str(zone_free_grid_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
