"""Native semantic regressions for zone_grid_getters and zone_deserialize_grid."""

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
    ("getters_exact", "Zone grid getters return exact cells_ptr, width, and height"),
    ("grid_deserialize", "Grid deserialize reads stream, calls 1C98A0, writes cells, and fires 1CF3E0/1CF9B0"),
]


@pytest.fixture(scope="module")
def zone_grid_test_binary(tmp_path_factory):
    """Compile production zone_grid_getters and zone_deserialize_grid with native driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-grid-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-grid-getters-test"
    sources = [
        "src/zone/zone_grid_getters.cpp",
        "src/zone/zone_deserialize_grid.cpp",
        "tests/native/zone_grid_getters_test.cpp",
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
def test_zone_grid_getters_and_deserialize_cases(zone_grid_test_binary, case, description):
    """Verify field getters and grid stream deserialization with post-load callbacks."""
    result = subprocess.run(
        [str(zone_grid_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
