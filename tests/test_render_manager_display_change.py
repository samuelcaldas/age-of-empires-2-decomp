"""Native regressions for render_manager_display_change."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "boolean stub func_00187470 returns 1",
    "func_001873a0 early exit when a3 is 1",
    "func_001873a0 when field_6C is null only calls Method114",
    "func_001873a0 propagates dimensions to field_28 and screen",
]


@pytest.fixture(scope="module")
def render_manager_display_change_test(tmp_path_factory):
    """Compile render_manager_display_change source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_display_change regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-display-change")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-display-change-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_display_change.cpp",
            "tests/native/render_manager_display_change_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_display_change_behavior(render_manager_display_change_test, case):
    """Verify render manager display change behavior."""
    result = subprocess.run([str(render_manager_display_change_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
