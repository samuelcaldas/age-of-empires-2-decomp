"""Native regressions for render_manager_loop."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "empty queue resets field_1C, executes OnIdle and end callback",
    "WM_QUIT with D_004E89C4 zero exits message loop immediately",
    "WM_QUIT with D_004E89C4 nonzero resets flag and continues loop",
    "PreTranslateMessage returning zero skips translation and dispatch",
    "normal message invokes TranslateMessage and DispatchMessage",
]


@pytest.fixture(scope="module")
def render_manager_loop_test(tmp_path_factory):
    """Compile render_manager_loop source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_loop regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-loop")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-loop-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_loop.cpp",
            "tests/native/render_manager_loop_test.cpp",
            "tests/native/render_manager_loop_virtual_fixture.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_loop_behavior(render_manager_loop_test, case):
    """Verify render manager message pump loop behavior across queue conditions."""
    result = subprocess.run([str(render_manager_loop_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
