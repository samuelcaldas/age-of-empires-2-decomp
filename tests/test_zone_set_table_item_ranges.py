"""Native semantic regressions for zone_set_table_item_ranges."""

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
    ("index0", "Sets range values at index 0 (offsets 0x18, 0x1A, 0x1C)"),
    ("stride", "Computes 6-byte stride per entry index and sets range values"),
]


@pytest.fixture(scope="module")
def zone_set_ranges_test_binary(tmp_path_factory):
    """Compile production zone_set_table_item_ranges source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-set-ranges-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-set-ranges-test"
    sources = [
        "src/zone_set_table_item_ranges.cpp",
        "tests/native/zone_set_table_item_ranges_test.cpp",
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
def test_zone_set_table_item_ranges_cases(zone_set_ranges_test_binary, case, description):
    """Verify table entry stride math and field assignments."""
    result = subprocess.run(
        [str(zone_set_ranges_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
