"""Native semantic regressions for zone_insert_spatial_item."""

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
    ("nearest", "Searches cell items and returns pointer to nearest matching entity by squared distance"),
    ("filter", "Filters candidate entities by item type and mode flag byte"),
    ("fallback", "When query coordinates are (-1.0f, -1.0f), returns first matching entity directly"),
]


@pytest.fixture(scope="module")
def zone_insert_item_test_binary(tmp_path_factory):
    """Compile production zone_insert_spatial_item source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-insert-item-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-insert-item-test"
    sources = [
        "src/zone/zone_insert_spatial_item.cpp",
        "tests/native/zone_insert_spatial_item_test.cpp",
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
def test_zone_insert_spatial_item_cases(zone_insert_item_test_binary, case, description):
    """Verify nearest entity spatial distance calculation, type matching, and mode filtering."""
    result = subprocess.run(
        [str(zone_insert_item_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
