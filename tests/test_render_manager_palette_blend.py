"""Native behavioral fixtures for render_manager_palette_blend."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "0, 50, and 100 percent with signed truncation and alpha preservation",
    "six RGB permutations, black/white, and zero/full channel boundaries",
    "skip endpoints, equal indices, and out-of-range sentinels",
    "all 256 entries and destination canaries",
    "in-place source and destination aliasing",
    "200 and -50 percent preserve extrapolation and byte wrapping",
]


@pytest.fixture(scope="module")
def render_manager_palette_blend_test(tmp_path_factory):
    """Compile the production source and palette fixtures as 32-bit native code."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_palette_blend regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-palette-blend")
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
    binary = fixture / "render-manager-palette-blend-test"
    compilation = subprocess.run(
        [
            compiler, "-m32", "-Iinclude",
            "src/render_manager_palette_blend.cpp",
            "tests/native/render_manager_palette_blend_test.cpp",
            "-o", str(binary),
        ],
        cwd=PROJECT_ROOT, capture_output=True, text=True,
    )
    assert compilation.returncode == 0, (
        "production palette source compilation failed after the 32-bit probe passed:\n"
        + compilation.stderr
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_palette_blend_behavior(render_manager_palette_blend_test, case):
    """Run one numbered palette behavior fixture."""
    result = subprocess.run(
        [str(render_manager_palette_blend_test), str(case)], capture_output=True, text=True
    )
    assert result.returncode == 0, f"case {case}: {result.stderr}"
