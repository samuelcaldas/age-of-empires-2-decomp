"""Native regressions for unit_action_coords position setters, offset calculation, and rendering."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_002697B0 SetPosition direct 3D vector stores",
    "func_00269290 CalculateOffset sprite frame and coordinate resolution",
    "func_00269450 RenderFrame sprite update and visibility sync",
]


@pytest.fixture(scope="module")
def coords_test(tmp_path_factory):
    """Compile the actual coords source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("coords regressions require g++")
    fixture = tmp_path_factory.mktemp("action-coords")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "coords-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_coords.cpp",
            "tests/native/unit_action_coords_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_coords_behavior(coords_test, case):
    """Verify position coordinates, sprite offsets, and frame dispatch."""
    result = subprocess.run([str(coords_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
