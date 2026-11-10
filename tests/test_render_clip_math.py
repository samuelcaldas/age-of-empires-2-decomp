"""Native semantic regressions for 2D rectangle clipper and viewport math."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "rectangle empty and point containment check"),
    ("1", "rectangle intersection and overlap"),
    ("2", "rectangle bounding box union"),
    ("3", "rectangle in-place clipping to viewport dimensions"),
    ("4", "sprite clipping with partial off-screen coordinates"),
    ("5", "sprite clipping complete rejection"),
]


@pytest.fixture(scope="module")
def render_clip_test(tmp_path_factory):
    """Compile render_clip_math with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_clip_test requires g++")
    fixture = tmp_path_factory.mktemp("render-clip")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-clip-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_clip_math.cpp",
         "tests/native/render_clip_math_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_render_clip_math_behavior(render_clip_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(render_clip_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
