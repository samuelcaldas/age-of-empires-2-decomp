"""Native semantic regressions for zone_setup_spatial_buckets."""

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
    ("setup_flow", "Allocates 251-byte lookup table, sets thresholds, and initializes 4 search bucket levels"),
]


@pytest.fixture(scope="module")
def zone_setup_buckets_test_binary(tmp_path_factory):
    """Compile production zone_setup_spatial_buckets source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-setup-buckets-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-setup-buckets-test"
    sources = [
        "src/zone/zone_setup_spatial_buckets.cpp",
        "tests/native/zone_setup_spatial_buckets_test.cpp",
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
def test_zone_setup_spatial_buckets_cases(zone_setup_buckets_test_binary, case, description):
    """Verify spatial search grid allocation, bucket array initialization, and flag setting."""
    result = subprocess.run(
        [str(zone_setup_buckets_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
