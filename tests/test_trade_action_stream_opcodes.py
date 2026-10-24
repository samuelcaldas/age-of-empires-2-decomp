"""Native regressions for trade_action_stream_opcodes."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00181e40 decodes opcode 0 payload and advances stream pointer",
    "func_00181e40 decodes opcode 2 extended length payload",
    "func_001820a0 configures step parameter D_004E3088",
    "func_001820c0 stores direct parameter D_004E3084",
]


@pytest.fixture(scope="module")
def trade_action_stream_opcodes_test(tmp_path_factory):
    """Compile the actual stream opcodes source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_opcodes regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-opcodes")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-opcodes-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade/trade_action_stream_opcodes.cpp",
            "tests/native/trade_action_stream_opcodes_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_opcodes_behavior(trade_action_stream_opcodes_test, case):
    """Verify opcode decoding, stream cursor advancement, and global helper settings."""
    result = subprocess.run([str(trade_action_stream_opcodes_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
