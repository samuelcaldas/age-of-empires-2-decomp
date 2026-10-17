"""Native semantic regressions for trade_action_helper_21A190."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021A190 and func_0021A1C0 open and close slot on D_01DC8000"),
    ("1", "func_0021A1E0, func_0021A210 and func_0021A240 slot buffer and capacity access"),
    ("2", "func_0021A260 append data up to limit and overflow prevention"),
]


@pytest.fixture(scope="module")
def helper_21A190_test(tmp_path_factory):
    """Compile trade_action_helper_21A190 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_21A190 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21A190")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21A190-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_21A190.cpp",
         "tests/native/trade_action_helper_21A190_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21A190_behavior(helper_21A190_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21A190_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
