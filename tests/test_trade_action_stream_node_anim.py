"""Native regressions for trade_action_stream_node_anim."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "animated node lifecycle, frame advancement, and draw operations",
    "animation mode, trigger flag, and query handlers",
]


@pytest.fixture(scope="module")
def trade_action_stream_node_anim_test(tmp_path_factory):
    """Compile the actual stream node anim source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_node_anim regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-node-anim")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-node-anim-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade/trade_action_stream_node_anim.cpp",
            "tests/native/trade_action_stream_node_anim_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_node_anim_behavior(trade_action_stream_node_anim_test, case):
    """Verify animated node frame advancement, draw dispatch, and properties."""
    result = subprocess.run([str(trade_action_stream_node_anim_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
