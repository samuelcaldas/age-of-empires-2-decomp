"""Native regressions for unit_action_build_stage."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026EEA0 non-70 unit class forwards to func_001DF340",
    "func_0026EEA0 null m_field10 forwards to func_001DF340",
    "func_0026EEA0 increments step when below max and updates method36",
    "func_0026EEA0 wraps step to zero when reaching or exceeding max",
]


@pytest.fixture(scope="module")
def build_stage_test(tmp_path_factory):
    """Compile the actual build_stage source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_stage regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-stage")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-stage-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_stage.cpp",
            "tests/native/unit_action_build_stage_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_stage_behavior(build_stage_test, case):
    """Verify step calculation, wraparound, and forwarding behavior."""
    result = subprocess.run([str(build_stage_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
