"""Native semantic regressions for zone_unlink_entity."""

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
    ("unlink_by_ptr", "Searches cell items list for matching pointer, removes and shifts tail item"),
    ("last_item", "When last remaining item is removed by pointer, frees list buffer via func_1D0EC0"),
    ("not_found", "When target pointer is not in cell, immediately returns without modifying cell"),
]


@pytest.fixture(scope="module")
def zone_unlink_ent_test_binary(tmp_path_factory):
    """Compile production zone_unlink_entity source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-unlink-ent-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-unlink-ent-test"
    sources = [
        "src/zone_unlink_entity.cpp",
        "tests/native/zone_unlink_entity_test.cpp",
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
def test_zone_unlink_entity_cases(zone_unlink_ent_test_binary, case, description):
    """Verify pointer search removal, array compaction, and buffer freeing."""
    result = subprocess.run(
        [str(zone_unlink_ent_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
