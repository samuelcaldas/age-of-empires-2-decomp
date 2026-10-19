"""Exercise DE90 and DF50 together with the same declared C++98 ABI."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def trade_packet_chain(tmp_path_factory):
    """Compile both production helpers against argument-complete SDK test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade packet chain tests require g++")
    fixture = tmp_path_factory.mktemp("trade-packet-chain")
    binary = fixture / "chain-test"
    subprocess.run(
        [compiler, "-m32", "-std=c++98", "-fsanitize=undefined",
         "-fno-sanitize-recover=undefined", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_21DE90.cpp", "src/trade_action_helper_21DF50.cpp",
         "tests/native/trade_packet_chain_test.cpp", "-o", str(binary)],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    return binary


@pytest.mark.parametrize("allocate", [0, 1], ids=["reserved_packet", "fallback_allocation"])
def test_trade_packet_chain(trade_packet_chain, allocate):
    """Verify a real palette pointer, all ten writer arguments, and nested call order."""
    result = subprocess.run(
        [str(trade_packet_chain), str(allocate)], capture_output=True, text=True, timeout=10,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
