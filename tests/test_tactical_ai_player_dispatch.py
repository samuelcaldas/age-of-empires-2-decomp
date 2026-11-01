"""Native behavioral tests for tactical_ai_player_dispatch (0x305CB0)."""

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
def player_dispatch_test(tmp_path_factory):
    """Compile tactical_ai_player_dispatch test fixture with native 32-bit assertions."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_player_dispatch regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("player-dispatch")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "player-dispatch-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/ai/tactical_ai_player_dispatch.cpp",
            "tests/native/tactical_ai_player_dispatch_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_player_dispatch_evaluation(player_dispatch_test):
    """Verify player command dispatch, item flag updates, and mode routing."""
    result = subprocess.run([str(player_dispatch_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
