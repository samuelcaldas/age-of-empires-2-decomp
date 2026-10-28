"""Native semantic regressions for HUD panel renderer and composite blits."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "solid rectangle fill with boundary clipping"),
    ("1", "one-pixel outline border rectangle"),
    ("2", "beveled button frame states (normal, pressed, disabled)"),
    ("3", "proportional HP bar rendering with color themes"),
    ("4", "complete out-of-bounds rejection"),
    ("5", "null pointer and invalid dimension guards"),
]


@pytest.fixture(scope="module")
def hud_renderer_test(tmp_path_factory):
    """Compile hud_panel_renderer with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("hud_renderer_test requires g++")
    fixture = tmp_path_factory.mktemp("hud-renderer")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "hud-renderer-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_clip_math.cpp",
         "src/render/hud_panel_layout.cpp",
         "src/render/hud_command_bar.cpp",
         "src/render/hud_panel_renderer.cpp",
         "tests/native/hud_panel_renderer_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_hud_panel_renderer_behavior(hud_renderer_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(hud_renderer_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
