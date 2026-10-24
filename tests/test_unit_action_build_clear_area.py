"""Native regressions for unit_action_build_clear_area."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00271220 clears overlapping type 80 obstruction within bounding extents",
    "func_00271220 ignores non-type-80 entities",
    "func_00271220 ignores entities failing flag 2048 query",
    "func_00271220 ignores entities beyond combined radius",
]


@pytest.fixture(scope="module")
def build_clear_area_test(tmp_path_factory):
    """Compile actual build_clear_area source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_clear_area regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-clear-area")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-clear-area-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_clear_area.cpp",
            "tests/native/unit_action_build_clear_area_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_clear_area_behavior(build_clear_area_test, case):
    """Verify spatial cell query, entity filtering, and repulsion invocation."""
    result = subprocess.run([str(build_clear_area_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
