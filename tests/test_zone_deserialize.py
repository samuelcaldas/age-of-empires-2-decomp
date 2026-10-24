"""Native semantic regressions for zone_deserialize."""

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
    ("full_flow", "Deserializes dimensions, AI state, grid cells, coordinates, raster, and fires callbacks"),
    ("below_grid", "Version below 7.0f skips grid cell loading and raster/callback invocations"),
]


@pytest.fixture(scope="module")
def zone_deserialize_test_binary(tmp_path_factory):
    """Compile production zone_deserialize source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-deserialize-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-deserialize-test"
    sources = [
        "src/zone/zone_deserialize.cpp",
        "tests/native/zone_deserialize_test.cpp",
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
def test_zone_deserialize_cases(zone_deserialize_test_binary, case, description):
    """Verify zone deserialization flow, versioning gates, and coordinate math."""
    result = subprocess.run(
        [str(zone_deserialize_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
