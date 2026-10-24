"""Native regressions for unit_action_build_pos_update."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026F9E0 skips map grid calls when m_field18 is zero",
    "func_0026F9E0 skips map grid calls when subaction m_p304 is present",
    "func_0026F9E0 executes map grid removal, movement, addition, and validation",
]


@pytest.fixture(scope="module")
def build_pos_update_test(tmp_path_factory):
    """Compile the actual build_pos_update source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_pos_update regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-pos-update")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-pos-update-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_pos_update.cpp",
            "tests/native/unit_action_build_pos_update_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_pos_update_behavior(build_pos_update_test, case):
    """Verify building movement, map grid removal, addition, and validation."""
    result = subprocess.run([str(build_pos_update_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
