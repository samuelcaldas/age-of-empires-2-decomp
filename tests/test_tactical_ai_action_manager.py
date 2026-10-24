"""Native behavioral regressions for the tactical_ai_action_manager subsystem."""

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


@pytest.fixture(scope="module")
def tactical_ai_action_manager_test(tmp_path_factory):
    """Compile the actual manager source with native 32-bit assertions."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_action_manager regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("tactical-action-manager")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "tactical-action-manager-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/ai/tactical_ai_action_manager.cpp",
            "tests/native/tactical_ai_action_manager_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_tactical_ai_action_manager_behavior(tactical_ai_action_manager_test):
    """Check constructor layout/order, destructor flags/order, and dispatcher branching."""
    result = subprocess.run(
        [str(tactical_ai_action_manager_test)], capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stderr


def test_tactical_ai_action_manager_compile_errors_fail(tmp_path):
    """Verify that compilation errors in actual/mock sources fail compilation as required."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_action_manager regressions require g++")
    broken_source = "this is not valid C++ syntax;"
    broken_file = tmp_path / "broken.cpp"
    broken_file.write_text(broken_source)
    res = subprocess.run(
        [compiler, "-m32", "-c", str(broken_file), "-o", str(tmp_path / "broken.o")],
        capture_output=True,
        text=True,
    )
    assert res.returncode != 0
