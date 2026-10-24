"""Native behavioral fixtures for render_manager_status."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00189c80 chooses 0x4B1 first and skips func_190FF0",
    "func_00189c80 chooses 0x4B2 before field thresholds",
    "field_2038 value 0 selects 0x4B3",
    "field_2038 value 3 selects 0x4B3",
    "field_2038 value 4 reaches field_10C8 comparison",
    "field_2038 below field_10C8 selects 0x4B4",
    "field_2038 equal to field_10C8 selects 0x4B0",
    "field_2038 above field_10C8 selects 0x4B0",
    "field_2038 high bit compares as unsigned",
    "field_10C8 high bit compares as unsigned",
    "GetString receives exact arguments and keeps shared buffer return",
    "func_00189e00 and func_00189e40 preserve call order and arguments",
    "func_00189e00 reloads field_1600 after its first callback",
    "func_00189e00 and func_00189e40 forward null field_1600",
    "func_00189e50 and func_00189e60 return cleanly",
]


@pytest.fixture(scope="module")
def render_manager_status_test(tmp_path_factory):
    """Compile production source and native fixtures as 32-bit binary."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_status regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-status")
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
    binary = fixture / "render-manager-status-test"
    compilation = subprocess.run(
        [
            compiler, "-m32", "-Iinclude",
            "src/render/render_manager_status.cpp",
            "tests/native/render_manager_status_test.cpp",
            "tests/native/render_manager_status_test_support.cpp",
            "tests/native/render_manager_status_selection_test.cpp",
            "tests/native/render_manager_status_threshold_test.cpp",
            "tests/native/render_manager_status_string_test.cpp",
            "tests/native/render_manager_status_dispatch_test.cpp",
            "-o", str(binary),
        ],
        cwd=PROJECT_ROOT, capture_output=True, text=True,
    )
    assert compilation.returncode == 0, (
        "production status compilation failed after 32-bit probe passed:\n"
        + compilation.stderr
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_status_behavior(render_manager_status_test, case):
    """Run one numbered render_manager_status behavioral fixture."""
    result = subprocess.run(
        [str(render_manager_status_test), str(case)],
        capture_output=True, text=True,
    )
    assert result.returncode == 0, f"case {case}: {result.stderr}"
