"""Native semantic regressions for render_helper_217DD0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00217DD0 switch case 1 updates field 0x124 and invokes helpers"),
]


@pytest.fixture(scope="module")
def helper_217DD0_test(tmp_path_factory):
    """Compile render_helper_217DD0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_helper_217DD0 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-217DD0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-217DD0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_helper_217DD0.cpp",
         "tests/native/render_helper_217DD0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_217DD0_behavior(helper_217DD0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_217DD0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
