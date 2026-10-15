"""Native semantic regressions for the reconstructed route buffers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "empty buffer"),
    ("1", "nonzero payload still appends"),
    ("2", "growth copies fields without padding"),
    ("3", "allocation failure leaves state unchanged"),
    ("4", "primary wrapper preserves every field"),
    ("5", "primary forward shift matches binary"),
    ("6", "primary allocation failure leaves state unchanged"),
    ("7", "byte counter overflow matches binary"),
]


@pytest.fixture(scope="module")
def route_buffer_test(tmp_path_factory):
    """Compile the real source with deterministic allocator test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native route tests require g++")
    binary = tmp_path_factory.mktemp("route-buffer") / "route-buffer-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_route_finish.cpp",
         "tests/native/trade_action_route_finish_test.cpp",
         "tests/native/trade_action_route_finish_stubs.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_route_buffer_behavior(route_buffer_test, case, description):
    """Check one observed binary behavior in an isolated native process."""
    result = subprocess.run(
        [str(route_buffer_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"{description}: {result.stderr}"
