"""Native regressions for render_manager_window_proc."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "active screen message handling and bypass rules",
    "mouse and keyboard message dispatching",
    "user, command, and paint message workflows",
    "activate state, size query, and status screen cancel sequence",
]


@pytest.fixture(scope="module")
def render_manager_window_proc_test(tmp_path_factory):
    """Compile render_manager_window_proc source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_window_proc regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-window-proc")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-manager-window-proc-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/render/render_manager_window_proc.cpp",
            "tests/native/render_manager_window_proc_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_window_proc_behavior(render_manager_window_proc_test, case):
    """Verify render manager window proc behavior."""
    result = subprocess.run([str(render_manager_window_proc_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
