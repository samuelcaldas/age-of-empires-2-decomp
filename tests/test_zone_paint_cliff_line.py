"""Native semantic regressions for zone_paint_cliff_line."""

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
    ("zero_length", "Line with start == end paints single point via Method 8 and returns 1"),
    ("single_step", "Line with single step paints start and end in correct order returning 1"),
    ("multiple_dirs", "Line across all four diagonal directions paints points from start to end returning 1"),
    ("clipping", "Out-of-bounds line endpoints are clamped strictly within map dimensions returning 1"),
    ("order_vtable", "Callback points follow monotonic order and dynamic vtable swap is honored"),
]


@pytest.fixture(scope="module")
def zone_paint_cliff_line_test_binary(tmp_path_factory):
    """Compile production zone_paint_cliff_line source with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-paint-cliff-line-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-paint-cliff-line-test"
    sources = [
        "src/zone_paint_cliff_line.cpp",
        "tests/native/zone_paint_cliff_line_test.cpp",
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
def test_zone_paint_cliff_line_cases(zone_paint_cliff_line_test_binary, case, description):
    """Verify cliff line rasterization, boundary clipping, directions, vtable reload, and ordering."""
    result = subprocess.run(
        [str(zone_paint_cliff_line_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
