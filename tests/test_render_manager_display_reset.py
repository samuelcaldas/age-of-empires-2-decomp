"""Native behavioral fixtures for render_manager_display_reset."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00189b40 tears down display surfaces and resets field_10C8 to zero",
    "func_00189ba0 activates field_152C when zero",
    "func_00189ba0 preserves field_152C when already active",
    "func_00189bc0 deactivates field_152C, cleans up field_164C, and invokes func_193190",
    "func_00189bc0 invokes func_193190 even when field_152C is zero",
    "func_00189c10 formats id, subsystem string, and detail string into buffer_FC5",
]


@pytest.fixture(scope="module")
def render_manager_display_reset_test(tmp_path_factory):
    """Compile production source and native fixtures as 32-bit binary."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_display_reset regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-display-reset")
    probe_binary = fixture / "probe"
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(probe_binary)],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    probe_run = subprocess.run([str(probe_binary)], capture_output=True, text=True)
    if probe_run.returncode:
        pytest.skip(f"native 32-bit g++ probe failed: {probe_run.stderr.strip()}")
    binary = fixture / "render-manager-display-reset-test"
    compilation = subprocess.run(
        [
            compiler, "-m32", "-Iinclude",
            "src/render_manager_display_reset.cpp",
            "tests/native/render_manager_display_reset_test.cpp",
            "-o", str(binary),
        ],
        cwd=PROJECT_ROOT, capture_output=True, text=True,
    )
    assert compilation.returncode == 0, (
        "production display_reset compilation failed after 32-bit probe passed:\n"
        + compilation.stderr
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_display_reset_behavior(render_manager_display_reset_test, case):
    """Run one numbered render_manager_display_reset behavioral fixture."""
    result = subprocess.run(
        [str(render_manager_display_reset_test), str(case)],
        capture_output=True, text=True,
    )
    assert result.returncode == 0, f"case {case}: {result.stderr}"
