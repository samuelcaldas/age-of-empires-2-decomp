"""Native regressions for unit_action_build_target_validate."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270EF0 master types 50, 199, and 276 return early without side-effects",
    "func_00270EF0 head item present calls Method13 and frees target list",
    "func_00270EF0 head item null triggers func_00270530 worker clear",
]


@pytest.fixture(scope="module")
def build_target_validate_test(tmp_path_factory):
    """Compile actual build_target_validate source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_target_validate regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-target-validate")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-target-validate-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_target_validate.cpp",
            "tests/native/unit_action_build_target_validate_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_target_validate_behavior(build_target_validate_test, case):
    """Verify master type exclusions, head item check, and worker list detachment."""
    result = subprocess.run([str(build_target_validate_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
