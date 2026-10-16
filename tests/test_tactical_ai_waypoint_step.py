"""Native regressions for tactical_ai_waypoint_step (0x307A00)."""

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
def waypoint_step_test(tmp_path_factory):
    """Compile waypoint step test fixture with native 32-bit assertions."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_waypoint_step regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("waypoint-step")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "waypoint-step-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/tactical_ai_waypoint_step.cpp",
            "tests/native/tactical_ai_waypoint_step_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_waypoint_step_evaluation(waypoint_step_test):
    """Verify waypoint step rendering, fallback logic, and circular index wrap."""
    result = subprocess.run([str(waypoint_step_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
