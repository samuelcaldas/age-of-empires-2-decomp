"""Native semantic regressions for HUD resource bar presenter and hit testing."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "standard player resource formatting"),
    ("1", "boundary values and resource limits clamping"),
    ("2", "hit testing top system buttons"),
    ("3", "hit testing non-button areas"),
    ("4", "canonical age string naming"),
    ("5", "null pointer safety guards"),
]


@pytest.fixture(scope="module")
def hud_resource_test(tmp_path_factory):
    """Compile hud_resource_bar with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("hud_resource_test requires g++")
    fixture = tmp_path_factory.mktemp("hud-resource")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "hud-resource-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_clip_math.cpp",
         "src/render/hud_panel_layout.cpp",
         "src/render/hud_resource_bar.cpp",
         "tests/native/hud_resource_bar_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_hud_resource_bar_behavior(hud_resource_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(hud_resource_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
