"""Native regressions for unit_action_build_save."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026DAC0 guard checks on null inputs",
    "func_0026DAC0 stream serialization writes header, state, and trailing fields",
    "func_0026DAC0 BaseList item serialization when items present",
]


@pytest.fixture(scope="module")
def build_save_test(tmp_path_factory):
    """Compile the actual build_save source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_save regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-save")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-save-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_save.cpp",
            "tests/native/unit_action_build_save_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_save_behavior(build_save_test, case):
    """Verify stream serialization, field offsets, and BaseList saves."""
    result = subprocess.run([str(build_save_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
