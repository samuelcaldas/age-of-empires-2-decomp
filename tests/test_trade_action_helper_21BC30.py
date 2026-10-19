"""Native semantic regressions for trade_action_helper_21BC30."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021BDD0 and func_0021BDE0 helpers"),
    ("1", "func_0021BC30 direct read without staging"),
    ("2", "func_0021BC30 staging mode with intra-sector offset"),
    ("3", "func_0021BC30 skip read when debug flag set"),
    ("4", "func_0021BC30 count zero default size and multi-sector offset"),
    ("5", "func_0021BC30 just-over sector size forces staging and copies all bytes"),
    ("6", "func_0021BC30 exact sector with unaligned offset copies all bytes"),
    ("7", "func_0021BC30 multi-chunk 1MiB staging boundary copies full payload"),
]


@pytest.fixture(scope="module")
def helper_21BC30_test(tmp_path_factory):
    """Compile trade_action_helper_21BC30 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_21BC30 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21BC30")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21BC30-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_21BC30.cpp",
         "tests/native/trade_action_helper_21BC30_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21BC30_behavior(helper_21BC30_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21BC30_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
