"""Native semantic regressions for HUD command bar matrix and unit status."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "initialization of command bar state"),
    ("1", "slot property assignment with PC and PS2 mappings"),
    ("2", "hit testing active command slots"),
    ("3", "hit testing hidden or background slots"),
    ("4", "unit HP ratio and color classification"),
    ("5", "error guards and parameter bounds"),
]


@pytest.fixture(scope="module")
def hud_command_test(tmp_path_factory):
    """Compile hud_command_bar with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("hud_command_test requires g++")
    fixture = tmp_path_factory.mktemp("hud-command")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "hud-command-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_clip_math.cpp",
         "src/render/hud_panel_layout.cpp",
         "src/render/hud_command_bar.cpp",
         "tests/native/hud_command_bar_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_hud_command_bar_behavior(hud_command_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(hud_command_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
