"""Native regressions for render_manager_palette."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "boolean stub func_00187650 returns 1 and early exit on a3 == a1",
    "func_00187480 dispatches MethodE0 or func_1AB370 depending on flags",
    "func_00187560 queries palette and forwards to func_1AB1B0",
    "func_001875d0 updates palette when Method118 is enabled",
]


@pytest.fixture(scope="module")
def render_manager_palette_test(tmp_path_factory):
    """Compile render_manager_palette source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_palette regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-palette")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-palette-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_palette.cpp",
            "tests/native/render_manager_palette_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_palette_behavior(render_manager_palette_test, case):
    """Verify render manager palette behavior."""
    result = subprocess.run([str(render_manager_palette_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
