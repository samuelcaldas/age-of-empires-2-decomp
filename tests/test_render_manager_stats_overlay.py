"""Native regressions for render_manager_stats_overlay."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00187b40 when field_518 is zero normalizes divisor to 1",
    "func_00187b40 when field_518 is nonzero divides timers by field_518",
    "stubs and func_00187c70 saves config when field_1AC is valid",
]


@pytest.fixture(scope="module")
def render_manager_stats_overlay_test(tmp_path_factory):
    """Compile render_manager_stats_overlay source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_stats_overlay regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-stats-overlay")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-stats-overlay-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_stats_overlay.cpp",
            "tests/native/render_manager_stats_overlay_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_stats_overlay_behavior(render_manager_stats_overlay_test, case):
    """Verify render manager stats overlay behavior."""
    result = subprocess.run([str(render_manager_stats_overlay_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
