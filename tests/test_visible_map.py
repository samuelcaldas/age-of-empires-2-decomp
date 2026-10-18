"""Native regressions for visible_map (0x138760)."""

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

MARKERS = [
    "VISIBLE_MAP_TEST_0_INIT_PASSED",
    "VISIBLE_MAP_TEST_1_CLEAR_PASSED",
    "VISIBLE_MAP_TEST_2_NONPOSITIVE_PASSED",
    "VISIBLE_MAP_TEST_3_MODE_PASSED",
    "VISIBLE_MAP_TEST_4_GUARDS_PASSED",
    "VISIBLE_MAP_TEST_5_LOAD_SAVE_PASSED",
]


@pytest.fixture(scope="module")
def visible_map_test(tmp_path_factory):
    """Compile visible map test fixture with native 32-bit assertions."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("visible_map regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("visible-map")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "visible-map-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/visible_map.cpp",
            "tests/native/visible_map_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_visible_map_lifecycle(visible_map_test):
    """Verify VisibleMap initialization, grid setup, mode setting, and clearing."""
    result = subprocess.run([str(visible_map_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
