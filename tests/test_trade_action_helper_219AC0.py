"""Native semantic regressions for trade_action_helper_219AC0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00219AC0 get current index or -1 if empty"),
    ("1", "func_00219AF0 find node index by id"),
    ("2", "func_00219B30 find node index by string"),
    ("3", "func_00219BA0 vtable dispatch and func_00219BC0 get text at index"),
]


@pytest.fixture(scope="module")
def helper_219AC0_test(tmp_path_factory):
    """Compile trade_action_helper_219AC0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_219AC0 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-219AC0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-219AC0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_219AC0.cpp",
         "tests/native/trade_action_helper_219AC0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_219AC0_behavior(helper_219AC0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_219AC0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
