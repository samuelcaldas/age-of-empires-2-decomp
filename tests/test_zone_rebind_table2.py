"""Native semantic regressions for zone_rebind_table2."""

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
    ("rebind_flow", "Parses active table 2 entries with .shp, clears f_B0, frees temp string, skips inactive"),
    ("deactivate", "Checks flag bit 1 and preserves active status when set while clearing f_B0"),
    ("no_active", "When all entries are inactive, skips parse, alloc, ctor, and free calls"),
]


@pytest.fixture(scope="module")
def zone_rebind_table2_test_binary(tmp_path_factory):
    """Compile production zone_rebind_table2 source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-rebind2-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-rebind2-test"
    sources = [
        "src/zone/zone_rebind_table2.cpp",
        "tests/native/zone_rebind_table2_test.cpp",
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
def test_zone_rebind_table2_cases(zone_rebind_table2_test_binary, case, description):
    """Verify table 2 parsing, item allocation, flag bit check, and field clearing."""
    result = subprocess.run(
        [str(zone_rebind_table2_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
