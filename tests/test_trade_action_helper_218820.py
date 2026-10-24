"""Native semantic regressions for trade_action_helper_218820."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "zero state skips begin dispatch cleanup"),
    ("1", "state 1 dispatches its complete handler contract"),
    ("2", "state 2 dispatches its complete handler contract"),
    ("3", "state 3 dispatches its complete handler contract"),
    ("4", "state 4 dispatches its complete handler contract"),
    ("5", "state 5 dispatches its complete handler contract"),
    ("6", "state 6 dispatches its complete handler contract"),
    ("7", "state 7 dispatches its complete handler contract"),
    ("8", "state 8 triggers cleanup only"),
    ("9", "state 9 triggers cleanup only"),
    ("10", "coordinates and computed extents are passed exactly"),
    ("11", "begin returning zero triggers cleanup without dispatch"),
    ("12", "a null manager is passed through all phases"),
    ("13", "state is reloaded after begin changes it to seven"),
    ("14", "state changed to zero after begin skips dispatch"),
    ("15", "state changed to eight after begin skips dispatch"),
    ("16", "manager is reloaded for dispatch and cleanup"),
    ("17", "negative state triggers cleanup without dispatch"),
    ("18", "INT_MIN state triggers cleanup without dispatch"),
]


@pytest.fixture(scope="module")
def helper_218820_test(tmp_path_factory):
    """Compile the production source and native contract harness as 32-bit code."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_218820 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-218820")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-218820-test"
    subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/trade/trade_action_helper_218820.cpp",
            "tests/native/trade_action_helper_218820_support.cpp",
            "tests/native/trade_action_helper_218820_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_218820_behavior(helper_218820_test, case, description):
    """Run each contract case in an isolated 32-bit process."""
    result = subprocess.run(
        [str(helper_218820_test), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
