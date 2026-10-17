"""Native semantic regressions for zone_init_bucket_arrays."""

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
    ("add_array", "Appends new array to bucket level, allocates sub-buffer, and updates tracking fields"),
    ("grow", "Grows bucket capacity via func_1D07D0 when count equals capacity before appending"),
]


@pytest.fixture(scope="module")
def zone_init_arrays_test_binary(tmp_path_factory):
    """Compile production zone_init_bucket_arrays source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-init-arrays-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-init-arrays-test"
    sources = [
        "src/zone_init_bucket_arrays.cpp",
        "tests/native/zone_init_bucket_arrays_test.cpp",
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
def test_zone_init_bucket_arrays_cases(zone_init_arrays_test_binary, case, description):
    """Verify bucket array allocation, index tracking, buffer registration, and capacity expansion."""
    result = subprocess.run(
        [str(zone_init_arrays_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
