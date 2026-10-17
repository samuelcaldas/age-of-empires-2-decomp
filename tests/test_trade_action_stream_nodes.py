"""Native regressions for trade_action_stream_nodes."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_001825d0 clears list and sets new items pointer",
    "func_00182610 inserts new node into empty list",
    "func_00182610 increments ref count on duplicate texture match",
    "func_001827b0 decrements ref count on existing texture match",
    "func_001827b0 unlinks and frees node when ref count reaches zero",
    "func_00182550 replays all active nodes through insert_or_increment",
]


@pytest.fixture(scope="module")
def trade_action_stream_nodes_test(tmp_path_factory):
    """Compile the actual stream nodes source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_nodes regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-nodes")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-nodes-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade_action_stream_nodes.cpp",
            "tests/native/trade_action_stream_nodes_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_nodes_behavior(trade_action_stream_nodes_test, case):
    """Verify set_items, insert_or_increment, remove_or_decrement, and replay operations."""
    result = subprocess.run([str(trade_action_stream_nodes_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
