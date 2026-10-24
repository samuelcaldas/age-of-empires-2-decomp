"""Native regressions for render_manager_state."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "stub function returns 1",
    "engine flags both 1 sets global and field_7C",
    "engine flag 5C not 1 skips field_7C but sets global",
    "engine flag 54 not 1 skips field_7C but sets global",
    "factory registration passes func_001842f0 callback",
    "renderer setup sets field_2C and global, calls func_1F32D0",
]


@pytest.fixture(scope="module")
def render_manager_state_test(tmp_path_factory):
    """Compile render_manager_state source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_state regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-state")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-state-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_state.cpp",
            "tests/native/render_manager_state_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_state_behavior(render_manager_state_test, case):
    """Verify render manager state stub, flag checks, factory registration, and setup."""
    result = subprocess.run([str(render_manager_state_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
