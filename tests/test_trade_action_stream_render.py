"""Native regressions for trade_action_stream_render."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00182890 renders nodes and preserves active chain",
    "func_00182890 unlinks node and returns to pool when render returns zero",
    "func_001829f0 executes clipped draw traversal",
    "func_00182b60 executes simple draw traversal",
]


@pytest.fixture(scope="module")
def trade_action_stream_render_test(tmp_path_factory):
    """Compile the actual stream render source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_render regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-render")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-render-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade/trade_action_stream_render.cpp",
            "tests/native/trade_action_stream_render_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_render_behavior(trade_action_stream_render_test, case):
    """Verify render loop, pool reclamation, clipped draw, and simple draw operations."""
    result = subprocess.run([str(trade_action_stream_render_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
