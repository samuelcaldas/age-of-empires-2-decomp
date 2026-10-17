"""Native semantic regressions for zone_find_cell_item_by_attr."""

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
    ("match", "Searches cell items list and returns item matching target attribute at offset 0xE"),
    ("not_found", "When target attribute is absent or cell is empty, immediately returns nullptr"),
]


@pytest.fixture(scope="module")
def zone_find_attr_test_binary(tmp_path_factory):
    """Compile production zone_find_cell_item_by_attr source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-find-attr-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-find-attr-test"
    sources = [
        "src/zone_find_cell_item_by_attr.cpp",
        "tests/native/zone_find_cell_item_by_attr_test.cpp",
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
def test_zone_find_cell_item_by_attr_cases(zone_find_attr_test_binary, case, description):
    """Verify cell item attribute search and null returns on missing attribute."""
    result = subprocess.run(
        [str(zone_find_attr_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
