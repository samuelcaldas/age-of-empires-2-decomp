"""Native contract regressions for the zone grid operations."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
int main() { static_assert(sizeof(void *) == 4, "requires 32-bit pointers"); }
"""
CASES = ("rectangle", "zero_width", "reset", "update")


@pytest.fixture(scope="module")
def grid_test_binary(tmp_path_factory):
    """Compile the production grid unit with its native contract driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    build_dir = tmp_path_factory.mktemp("zone-dispatch-grid")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(build_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = build_dir / "zone-dispatch-grid-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", "src/zone_dispatch_grid.cpp",
         "tests/native/zone_dispatch_grid_test.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.mark.parametrize("case", CASES)
def test_grid_production_contracts(grid_test_binary, case):
    """Check the actual grid operation for the selected contract case."""
    result = subprocess.run([str(grid_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"{case} contract failed: {result.stderr}"
