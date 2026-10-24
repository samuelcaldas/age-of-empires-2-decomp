"""Native semantic regressions for zone_dispatch child teardown and NULL-hole safety."""

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
    ("slot_null_and_sequence", "Child slot null hole skipped; strict call sequence 1D16D0->25DE30->1D06A0"),
    ("subarray_null", "Child subarray pointer itself null safely handled without calls"),
]


@pytest.fixture(scope="module")
def zone_dispatch_test_binary(tmp_path_factory):
    """Compile production zone_dispatch source with native cleanup driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-dispatch-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-dispatch-cleanup-test"
    sources = [
        "src/zone/zone_dispatch.cpp",
        "src/zone/zone_dispatch_grid.cpp",
        "tests/native/zone_dispatch_fixture_support.cpp",
        "tests/native/zone_dispatch_cleanup_test.cpp",
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
def test_zone_dispatch_cleanup_cases(zone_dispatch_test_binary, case, description):
    """Verify child teardown, sequence ordering, subarray null, and argument assertions."""
    result = subprocess.run(
        [str(zone_dispatch_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
