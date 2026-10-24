"""Native regressions for trade_action_stream_list."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_001820d0 initializes vtable, head pointer, and context param",
    "func_001820f0 clears list and deletes object on positive flag",
    "func_001824a0 frees all items back to pool and zeroes list head",
    "func_001821f0 dispatches opcode mode 1 and links allocated node",
    "func_001823e0 serializes list items and appends zero terminator",
]


@pytest.fixture(scope="module")
def trade_action_stream_list_test(tmp_path_factory):
    """Compile the actual stream list source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_list regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-list")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-list-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade/trade_action_stream_list.cpp",
            "tests/native/trade_action_stream_list_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_list_behavior(trade_action_stream_list_test, case):
    """Verify constructor, destructor, pool teardown, opcode parsing, and serialization."""
    result = subprocess.run([str(trade_action_stream_list_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
