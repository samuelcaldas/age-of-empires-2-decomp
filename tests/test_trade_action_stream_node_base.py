"""Native regressions for trade_action_stream_node_base."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "lifecycle, initialization, and draw operations",
    "property getters and texture query handlers",
]


@pytest.fixture(scope="module")
def trade_action_stream_node_base_test(tmp_path_factory):
    """Compile the actual stream node base source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_node_base regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-node-base")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-node-base-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade_action_stream_node_base.cpp",
            "tests/native/trade_action_stream_node_base_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_node_base_behavior(trade_action_stream_node_base_test, case):
    """Verify node initialization, pos, draw dispatch, and query handlers."""
    result = subprocess.run([str(trade_action_stream_node_base_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
