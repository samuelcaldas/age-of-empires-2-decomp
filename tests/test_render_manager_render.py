"""Native regressions for render_manager_render."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "early exit for display mode 1 returning field_34",
    "abort render when preparation func_00185c70 fails",
    "render frame with active screen and timer statistics",
    "render frame fallback when screen is null and period timers",
]


@pytest.fixture(scope="module")
def render_manager_render_test(tmp_path_factory):
    """Compile render_manager_render source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_render regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-render")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-render-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_render.cpp",
            "tests/native/render_manager_render_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_render_behavior(render_manager_render_test, case):
    """Verify render manager frame rendering behavior."""
    result = subprocess.run([str(render_manager_render_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
