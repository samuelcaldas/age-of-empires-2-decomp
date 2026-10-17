"""Native regressions for render_manager_present."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00185bc0 with field_88 nonzero returns 1 immediately",
    "func_00185bc0 with field_88 zero dispatches items and helpers",
    "func_00185c60 stub returns 1",
    "func_00185c70 with field_30 zero calls stub and returns 0",
    "func_00185c70 with field_34 nonzero returns 1 without refresh",
    "func_00185c70 refresh calls func_225F80 and func_1AB1C0",
    "func_00185cf0 stub returns cleanly",
]


@pytest.fixture(scope="module")
def render_manager_present_test(tmp_path_factory):
    """Compile render_manager_present source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_present regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-present")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-present-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_present.cpp",
            "tests/native/render_manager_present_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_present_behavior(render_manager_present_test, case):
    """Verify render manager display surface presentation, refresh, and stubs."""
    result = subprocess.run([str(render_manager_present_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
