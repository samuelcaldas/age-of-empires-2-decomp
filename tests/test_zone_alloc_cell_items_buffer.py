"""Native semantic regressions for zone_alloc_cell_items_buffer."""

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
    ("free_list", "Allocates buffer by popping free node from bucket free list in O(1) time"),
    ("chunk", "Carves contiguous slot from current chunk buffer when free list is empty"),
    ("replenish", "Invokes func_1D08E0 to allocate a new bucket buffer block when bucket is exhausted"),
]


@pytest.fixture(scope="module")
def zone_alloc_buf_test_binary(tmp_path_factory):
    """Compile production zone_alloc_cell_items_buffer source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-alloc-buf-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-alloc-buf-test"
    sources = [
        "src/zone_alloc_cell_items_buffer.cpp",
        "tests/native/zone_alloc_cell_items_buffer_test.cpp",
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
def test_zone_alloc_cell_items_buffer_cases(zone_alloc_buf_test_binary, case, description):
    """Verify bucket slab allocation, free list pop, slot carving, and replenishment call."""
    result = subprocess.run(
        [str(zone_alloc_buf_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
