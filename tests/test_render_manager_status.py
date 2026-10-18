"""Native regressions for render_manager_status (0x189C80)."""

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
def render_manager_status_test(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_status regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("render-manager-status")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "render-manager-status-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/render_manager_status.cpp",
            "tests/native/render_manager_status_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_render_manager_status_behavior(render_manager_status_test):
    result = subprocess.run([str(render_manager_status_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
