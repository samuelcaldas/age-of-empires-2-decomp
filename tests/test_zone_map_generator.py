"""Native semantic regressions for zone_map_generator."""

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
    ("mode_guard", "World mode scoped guard restores mode, allocates handle, runs generator lifecycle"),
    ("handle_reuse", "Valid handle is reused without allocation and negative dimensions default to zone layout"),
]


@pytest.fixture(scope="module")
def zone_map_generator_test_binary(tmp_path_factory):
    """Compile production zone_map_generator source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-map-gen-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-map-generator-test"
    sources = [
        "src/zone_map_generator.cpp",
        "tests/native/zone_map_generator_test.cpp",
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
def test_zone_map_generator_cases(zone_map_generator_test_binary, case, description):
    """Verify world mode scoped guard, handle allocation/reuse, generator lifecycle."""
    result = subprocess.run(
        [str(zone_map_generator_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
