"""Native regressions for tactical_ai_grid_marker (0x308A70)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""


@pytest.fixture(scope="module")
def grid_marker_test(tmp_path_factory):
    """Compile grid marker test fixture with native 32-bit assertions."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_grid_marker regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("grid-marker")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "grid-marker-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/tactical_ai_grid_marker.cpp",
            "tests/native/tactical_ai_grid_marker_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_grid_marker_evaluation(grid_marker_test):
    """Verify grid tile projection and diagonal box marker drawing."""
    result = subprocess.run([str(grid_marker_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
