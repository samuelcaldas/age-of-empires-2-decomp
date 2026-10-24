"""Native regressions for trade_action_stream_pool."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "pool initialization, allocation, and free operations",
    "pool overflow diagnostic handler",
]


@pytest.fixture(scope="module")
def trade_action_stream_pool_test(tmp_path_factory):
    """Compile the actual stream pool source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_pool regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-pool")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-pool-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade/trade_action_stream_pool.cpp",
            "tests/native/trade_action_stream_pool_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_pool_behavior(trade_action_stream_pool_test, case):
    """Verify pool initialization, freelist operations, and overflow diagnostics."""
    result = subprocess.run([str(trade_action_stream_pool_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
