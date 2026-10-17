"""Native regressions for trade_action_stream_raster."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0017e350 returns early when vertical bounds exceed top clip",
    "func_0017e350 returns early when vertical bounds exceed bottom clip",
    "func_0017e350 returns early when horizontal bounds exceed right clip",
    "func_0017e350 performs scanline row lookup and dispatches within valid viewport",
]


@pytest.fixture(scope="module")
def trade_action_stream_raster_test(tmp_path_factory):
    """Compile the actual stream raster source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_raster regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-raster")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-raster-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade_action_stream_raster.cpp",
            "tests/native/trade_action_stream_raster_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_raster_behavior(trade_action_stream_raster_test, case):
    """Verify viewport clipping and rasterizer row dispatch."""
    result = subprocess.run([str(trade_action_stream_raster_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
