"""Native semantic regressions for zone_stub_1cd3c0."""

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
    ("null_pointer", "Passing nullptr returns 0"),
    ("valid_pointer", "Passing valid object pointer returns 0"),
]


@pytest.fixture(scope="module")
def zone_stub_test_binary(tmp_path_factory):
    """Compile production zone_stub_1cd3c0 source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-stub-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-stub-test"
    sources = [
        "src/zone_stub_1cd3c0.cpp",
        "tests/native/zone_stub_1cd3c0_test.cpp",
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
def test_zone_stub_1cd3c0_cases(zone_stub_test_binary, case, description):
    """Verify zone stub 001CD3C0 returns 0 under null and valid pointers."""
    result = subprocess.run(
        [str(zone_stub_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
