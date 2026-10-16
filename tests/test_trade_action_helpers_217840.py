"""Native behavioral regressions for the 0x217840 trade-action helpers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
#include <cstring>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""


@pytest.fixture(scope="module")
def trade_action_helpers_test(tmp_path_factory):
    """Compile the actual helper source with native 32-bit assertions."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade-action helper regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("trade-action-helpers-217840")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "trade-action-helpers-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_217840.cpp",
         "tests/native/trade_action_helpers_217840_test.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_trade_action_helpers_preserve_stores_and_callbacks(trade_action_helpers_test):
    """Check exact object writes, callback timing, truncation, and no-call entry."""
    result = subprocess.run(
        [str(trade_action_helpers_test)], capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stderr
