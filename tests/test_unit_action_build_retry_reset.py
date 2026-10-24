"""Native regressions for unit_action_build_retry_reset."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270E30 status 0xFF skips dispatch and preserves field 15A",
    "func_00270E30 status 8 dispatches func_270BA0 and resets field 15A to 0xFF",
    "func_00270E30 status 27 dispatches func_270BA0 and resets field 15A to 0xFF",
]


@pytest.fixture(scope="module")
def build_retry_reset_test(tmp_path_factory):
    """Compile the actual build_retry_reset source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_retry_reset regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-retry-reset")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-retry-reset-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_retry_reset.cpp",
            "tests/native/unit_action_build_retry_reset_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_retry_reset_behavior(build_retry_reset_test, case):
    """Verify status consumption, dispatch to func_270BA0, and 0xFF reset."""
    result = subprocess.run([str(build_retry_reset_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
