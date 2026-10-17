"""Native semantic regressions for zone_update_tile_transitions."""

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
    ("transitions_3x3", "Iterates center cell and 3x3 surrounding tiles triggering transition update"),
    ("oob", "Out-of-bounds tile coordinates immediately return without modifying cells"),
    ("fallback", "Resolves terrain fallback index when table specifies alternate terrain"),
]


@pytest.fixture(scope="module")
def zone_update_trans_test_binary(tmp_path_factory):
    """Compile production zone_update_tile_transitions source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-update-trans-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-update-trans-test"
    sources = [
        "src/zone_update_tile_transitions.cpp",
        "tests/native/zone_update_tile_transitions_test.cpp",
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
def test_zone_update_tile_transitions_cases(zone_update_trans_test_binary, case, description):
    """Verify tile transition updates across 3x3 neighborhood, fallback resolution, and OOB guard."""
    result = subprocess.run(
        [str(zone_update_trans_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
