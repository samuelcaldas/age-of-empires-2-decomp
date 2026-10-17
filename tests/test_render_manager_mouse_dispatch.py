"""Native regressions for render_manager_mouse_dispatch."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00186a20 returns 1",
    "func_00186950 inactive guard skips processing",
    "func_00186950 active state with field_1E8 sets subsystem",
    "func_00186950 coordinate unpacking and virtual method dispatch",
]


@pytest.fixture(scope="module")
def render_manager_mouse_dispatch_test(tmp_path_factory):
    """Compile render_manager_mouse_dispatch source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_mouse_dispatch regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-mouse-dispatch")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-mouse-dispatch-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_mouse_dispatch.cpp",
            "tests/native/render_manager_mouse_dispatch_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_mouse_dispatch_behavior(render_manager_mouse_dispatch_test, case):
    """Verify render manager mouse dispatch behavior."""
    result = subprocess.run([str(render_manager_mouse_dispatch_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
