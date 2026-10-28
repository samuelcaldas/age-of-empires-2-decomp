"""Native semantic regressions for 8bpp to 16/32bpp surface blitter and converter."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "palette LUT generation for RGB565 and ARGB8888"),
    ("1", "8bpp to 16bpp RGB565 opaque blit"),
    ("2", "8bpp to 16bpp RGB565 color key transparency"),
    ("3", "8bpp to 32bpp ARGB8888 color key transparency"),
    ("4", "blit clipping against destination viewport"),
    ("5", "blit complete rejection out of bounds"),
]


@pytest.fixture(scope="module")
def render_blit_test(tmp_path_factory):
    """Compile render_blit_converter with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_blit_test requires g++")
    fixture = tmp_path_factory.mktemp("render-blit")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-blit-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_blit_converter.cpp",
         "tests/native/render_blit_converter_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_render_blit_converter_behavior(render_blit_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(render_blit_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
