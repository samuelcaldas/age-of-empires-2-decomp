"""Native semantic regressions for app_dispatch_21bfb0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def app_dispatch_21bfb0_test(tmp_path_factory):
    """Compile app_dispatch_21bfb0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("app_dispatch_21bfb0 tests require g++")
    fixture = tmp_path_factory.mktemp("app-dispatch-21bfb0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "app-dispatch-21bfb0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/core/app_dispatch_21bfb0.cpp",
         "tests/native/app_dispatch_21bfb0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


def test_app_dispatch_21bfb0_behavior(app_dispatch_21bfb0_test):
    """Run virtual call dispatch in an isolated native process."""
    result = subprocess.run(
        [str(app_dispatch_21bfb0_test)], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
