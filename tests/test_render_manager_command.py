"""Native regressions for render_manager_command."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00186db0 returns 1",
    "func_00186c20 command 6076 player methodD8 invocation with flag 1",
    "func_00186c20 command 6077 player methodD8 invocation with flag 0",
    "func_00186c20 switch commands 6050, 6051 and 6074 sub-object dispatch",
]


@pytest.fixture(scope="module")
def render_manager_command_test(tmp_path_factory):
    """Compile render_manager_command source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_command regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-command")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-command-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render_manager_command.cpp",
            "tests/native/render_manager_command_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_command_behavior(render_manager_command_test, case):
    """Verify render manager command behavior."""
    result = subprocess.run([str(render_manager_command_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
