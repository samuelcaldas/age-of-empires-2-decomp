"""Native regressions for render_manager_activate."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "boolean stubs func_00187300, func_00187310, func_00187350, func_00187390 return 1",
    "func_00187320 and func_00187360 dispatch methods 10c and 110",
    "func_00187170 activates window resetting field_B1C and calling Method104",
    "func_00187170 deactivates window updating field_B1C and calling Method108",
]


@pytest.fixture(scope="module")
def render_manager_activate_test(tmp_path_factory):
    """Compile render_manager_activate source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_activate regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-activate")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-activate-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_activate.cpp",
            "tests/native/render_manager_activate_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_activate_behavior(render_manager_activate_test, case):
    """Verify render manager activation dispatch behavior."""
    result = subprocess.run([str(render_manager_activate_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
