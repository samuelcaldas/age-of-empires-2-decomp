"""Native regressions for render_manager_coords."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00185e50 returns field_84 when a1 is 0 and func_00185e70 bounds-checks field_90",
    "func_00185ec0 sets sub-object field_30 and func_00185f00 evaluates field_B20",
    "func_00185f80 unpacks packed coordinates and extracts bitmask flags",
]


@pytest.fixture(scope="module")
def render_manager_coords_test(tmp_path_factory):
    """Compile render_manager_coords source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_coords regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-coords")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-coords-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_coords.cpp",
            "tests/native/render_manager_coords_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_coords_behavior(render_manager_coords_test, case):
    """Verify render manager coords behavior."""
    result = subprocess.run([str(render_manager_coords_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
