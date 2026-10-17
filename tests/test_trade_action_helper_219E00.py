"""Native semantic regressions for trade_action_helper_219E00."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00219E00 and func_00219F00 field setters with vtable method28 notification"),
    ("1", "func_00219E20 directional setter and func_00219F20 byte_24 query"),
    ("2", "func_00219E90 scroll wheel delta dispatch to func_00217DD0"),
]


@pytest.fixture(scope="module")
def helper_219E00_test(tmp_path_factory):
    """Compile trade_action_helper_219E00 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_219E00 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-219E00")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-219E00-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_219E00.cpp",
         "tests/native/trade_action_helper_219E00_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_219E00_behavior(helper_219E00_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_219E00_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
