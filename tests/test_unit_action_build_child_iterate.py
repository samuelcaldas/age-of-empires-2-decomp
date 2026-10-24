"""Native regressions for unit_action_build_child_iterate."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026F910 returns early without child iteration when a2 is zero",
    "func_0026F910 iterates children in reverse from count-1 down to zero",
    "func_0026F910 calls func_0026F590 with negative coordinates on matching player",
    "func_0026F910 dispatches Method58 and Method31 when child m_field1C is nonzero",
]


@pytest.fixture(scope="module")
def build_child_iterate_test(tmp_path_factory):
    """Compile the actual build_child_iterate source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_child_iterate regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-child-iterate")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-child-iterate-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_child_iterate.cpp",
            "tests/native/unit_action_build_child_iterate_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_child_iterate_behavior(build_child_iterate_test, case):
    """Verify child enumeration, reverse ordering, player filtering, and method dispatch."""
    result = subprocess.run([str(build_child_iterate_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
