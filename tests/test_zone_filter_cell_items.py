"""Native semantic regressions for zone_filter_cell_items."""

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
    ("filter_flow", "Filters cell items, checks flags against GP masks, dispatches render method 6"),
    ("type_skip", "When item info type is below 50, immediately skips entity processing"),
    ("filter_mode_f", "Filter mode 0xF bypasses the item type threshold and dispatches render"),
    ("filter_mode_80", "Filter mode 0x80 dispatches eligible non-special items without flags"),
]


@pytest.fixture(scope="module")
def zone_filter_items_test_binary(tmp_path_factory):
    """Compile production zone_filter_cell_items source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-filter-items-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-filter-items-test"
    sources = [
        "src/zone/zone_filter_cell_items.cpp",
        "tests/native/zone_filter_cell_items_test.cpp",
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
def test_zone_filter_cell_items_cases(zone_filter_items_test_binary, case, description):
    """Verify entity type threshold filtering, mask checks, and virtual method 6 dispatch."""
    result = subprocess.run(
        [str(zone_filter_items_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
