"""Native semantic regressions for HUD panel layout geometry."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "PC 640x480 resolution layout geometry"),
    ("1", "PC 800x600 resolution layout geometry"),
    ("2", "PS2 640x448 NTSC resolution layout geometry"),
    ("3", "PS2 640x512 PAL resolution layout geometry"),
    ("4", "Custom resolution scaling and clamping"),
    ("5", "Invalid parameters error handling"),
]


@pytest.fixture(scope="module")
def hud_layout_test(tmp_path_factory):
    """Compile hud_panel_layout with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("hud_layout_test requires g++")
    fixture = tmp_path_factory.mktemp("hud-layout")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "hud-layout-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_clip_math.cpp",
         "src/render/hud_panel_layout.cpp",
         "tests/native/hud_panel_layout_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_hud_panel_layout_behavior(hud_layout_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(hud_layout_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
