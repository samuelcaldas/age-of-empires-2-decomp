"""Native semantic regressions for trade_action_helper_219C00."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00219C00 node info extraction and func_00219C90 extra text extraction"),
    ("1", "func_00219CD0, func_00219CE0 and func_00219D20 ID query and vtable dispatch"),
]


@pytest.fixture(scope="module")
def helper_219C00_test(tmp_path_factory):
    """Compile trade_action_helper_219C00 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("trade_action_helper_219C00 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-219C00")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-219C00-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/trade_action_helper_219C00.cpp",
         "tests/native/trade_action_helper_219C00_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_219C00_behavior(helper_219C00_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_219C00_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
