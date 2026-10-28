"""Native semantic regressions for kt_thread_spawn_220ba0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "vsync worker thread semaphore init, spawn, and start"),
]


@pytest.fixture(scope="module")
def thread_spawn_220ba0_test(tmp_path_factory):
    """Compile kt_thread_spawn_220ba0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("kt_thread_spawn_220ba0 tests require g++")
    fixture = tmp_path_factory.mktemp("kt-thread-spawn-220ba0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "kt-thread-spawn-220ba0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/kcet/kt_thread_spawn_220ba0.cpp",
         "tests/native/kt_thread_spawn_220ba0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_kt_thread_spawn_220ba0_behavior(thread_spawn_220ba0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(thread_spawn_220ba0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
