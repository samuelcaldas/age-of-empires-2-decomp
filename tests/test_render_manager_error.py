"""Native behavioral fixtures for render_manager_error."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "constructor initializes device and clears error code",
    "format_error tail calls func_2265E0 with capacity 0x400",
    "translate_error ignores zero HRESULT",
    "translate_error formats DDERR_SURFACELOST as 0x17B7",
    "translate_error records error code without formatting for no-op codes",
    "deleting destructor deallocates heap instance",
]


@pytest.fixture(scope="module")
def render_manager_error_test(tmp_path_factory):
    """Compile production source and native fixtures as 32-bit binary."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_error regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-error")
    probe_binary = fixture / "probe"
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(probe_binary)],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    probe_run = subprocess.run([str(probe_binary)], capture_output=True, text=True)
    if probe_run.returncode:
        pytest.skip(f"native 32-bit g++ probe failed: {probe_run.stderr.strip()}")
    binary = fixture / "render-manager-error-test"
    compilation = subprocess.run(
        [
            compiler, "-m32", "-Iinclude",
            "src/render_manager_error.cpp",
            "tests/native/render_manager_error_test.cpp",
            "-o", str(binary),
        ],
        cwd=PROJECT_ROOT, capture_output=True, text=True,
    )
    assert compilation.returncode == 0, (
        "production error compilation failed after 32-bit probe passed:\n"
        + compilation.stderr
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_error_behavior(render_manager_error_test, case):
    """Run one numbered render_manager_error behavioral fixture."""
    result = subprocess.run(
        [str(render_manager_error_test), str(case)],
        capture_output=True, text=True,
    )
    assert result.returncode == 0, f"case {case}: {result.stderr}"
