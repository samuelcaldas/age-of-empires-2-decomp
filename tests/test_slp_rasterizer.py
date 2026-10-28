"""Native semantic regressions for SLP line rasterizer."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "lesser and greater block copy"),
    ("1", "lesser and greater transparent skips"),
    ("2", "player color remap"),
    ("3", "shadow and dither"),
    ("4", "bounds and left padding overflow guard"),
    ("5", "multi-scanline frame rasterization"),
]


@pytest.fixture(scope="module")
def slp_rasterizer_test(tmp_path_factory):
    """Compile slp_rasterizer with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("slp_rasterizer_test requires g++")
    fixture = tmp_path_factory.mktemp("slp-rasterizer")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "slp-rasterizer-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/slp_rasterizer.cpp",
         "tests/native/slp_rasterizer_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_slp_rasterizer_behavior(slp_rasterizer_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(slp_rasterizer_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
