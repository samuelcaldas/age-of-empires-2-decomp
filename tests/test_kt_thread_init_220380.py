"""Native semantic regressions for kt_thread_init_220380."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "thread create and priority setup sequence"),
    ("1", "vblank handler register and container initialize sequence"),
]


@pytest.fixture(scope="module")
def thread_init_220380_test(tmp_path_factory):
    """Compile kt_thread_init_220380 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("kt_thread_init_220380 tests require g++")
    fixture = tmp_path_factory.mktemp("kt-thread-init-220380")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "kt-thread-init-220380-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/kcet/kt_thread_init_220380.cpp",
         "tests/native/kt_thread_init_220380_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_kt_thread_init_220380_behavior(thread_init_220380_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(thread_init_220380_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
