"""Native semantic regressions for zone_screen_to_world."""

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
    ("case0_flat", "Transforms flat terrain screen coordinates to isometric world space"),
    ("case1_case5", "Calculates distinct slope-adjusted elevation offsets for cases 1 and 5"),
    ("case9_case13", "Calculates distinct slope-adjusted elevation offsets for cases 9 and 13"),
    ("invalid_cmd", "When command byte exceeds 16, immediately aborts without modifying outputs"),
]


@pytest.fixture(scope="module")
def zone_screen_world_test_binary(tmp_path_factory):
    """Compile production zone_screen_to_world source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-s2w-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-s2w-test"
    sources = [
        "src/zone_screen_to_world.cpp",
        "tests/native/zone_screen_to_world_test.cpp",
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
def test_zone_screen_to_world_cases(zone_screen_world_test_binary, case, description):
    """Verify screen to world de-rotation, scale factors, jump table cases, and bounds guard."""
    result = subprocess.run(
        [str(zone_screen_world_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
