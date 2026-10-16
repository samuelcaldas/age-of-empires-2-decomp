"""Native regressions for unit_action_build_finish."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026E750 and func_0026E940 guard checks on null inputs",
    "func_0026E750 audio notification with zero, one, and many active slots",
    "func_0026E940 work completion and flag mutations",
]


@pytest.fixture(scope="module")
def build_finish_test(tmp_path_factory):
    """Compile the actual build_finish source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_finish regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-finish")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-finish-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_finish.cpp",
            "tests/native/unit_action_build_finish_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_finish_behavior(build_finish_test, case):
    """Verify audio slot iteration, ratio clamping, and completion flags."""
    result = subprocess.run([str(build_finish_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
