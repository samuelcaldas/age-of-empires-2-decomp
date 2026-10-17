"""Native semantic regressions for trade_action_helper_21ACD0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021ACD0 setup context with flags 0x800 and 0x200 branching"),
    ("1", "func_0021AD70 begin frame setup with flags 0x200 and 0x800 overrides"),
    ("2", "func_0021AE10 end frame reset with flag 0x200"),
]


@pytest.fixture(scope="module")
def helper_21ACD0_test(tmp_path_factory):
    """Compile trade_action_helper_21ACD0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_21ACD0 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21ACD0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21ACD0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_21ACD0.cpp",
         "tests/native/trade_action_helper_21ACD0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21ACD0_behavior(helper_21ACD0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21ACD0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
