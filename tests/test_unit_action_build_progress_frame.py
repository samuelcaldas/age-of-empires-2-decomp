"""Native regressions for unit_action_build_progress_frame."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270E70 clamps to max_progress and decrements positive result",
    "func_00270E70 clamps to max_frame when progress exceeds frame count",
    "func_00270E70 zero progress returns zero frame without decrement",
    "func_00270E70 progress within bounds decrements by 1",
]


@pytest.fixture(scope="module")
def build_progress_frame_test(tmp_path_factory):
    """Compile actual build_progress_frame source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_progress_frame regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-progress-frame")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-progress-frame-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_progress_frame.cpp",
            "tests/native/unit_action_build_progress_frame_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_progress_frame_behavior(build_progress_frame_test, case):
    """Verify progress clamping, max frame bounds, and frame decrement logic."""
    result = subprocess.run([str(build_progress_frame_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
