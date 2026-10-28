"""Native semantic regressions for kt_iop_init_220dd0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "reboot IOP and load primary IRX modules"),
    ("1", "load secondary audio and network modules and initialize sound DSP"),
]


@pytest.fixture(scope="module")
def iop_init_test(tmp_path_factory):
    """Compile kt_iop_init_220dd0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("kt_iop_init tests require g++")
    fixture = tmp_path_factory.mktemp("kt-iop-init")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "kt-iop-init-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/kcet/kt_iop_init_220dd0.cpp",
         "tests/native/kt_iop_init_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_kt_iop_init_behavior(iop_init_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(iop_init_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
