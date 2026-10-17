"""Native regressions for trade_action_stream_props."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "draw, param mutation, and broadcast operations",
    "property getters and minimum priority computation",
]


@pytest.fixture(scope="module")
def trade_action_stream_props_test(tmp_path_factory):
    """Compile the actual stream props source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_stream_props regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream-props")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-props-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/trade_action_stream_props.cpp",
            "tests/native/trade_action_stream_props_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_props_behavior(trade_action_stream_props_test, case):
    """Verify stream property operations, draw loops, broadcasts, and getters."""
    result = subprocess.run([str(trade_action_stream_props_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
