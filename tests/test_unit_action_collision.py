"""Native regressions for unit_action_collision target checking, positioning, and waypoint updates."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "guard conditions (null, zero counts, early exits)",
    "multi-child reverse traversal and full ABI arguments",
    "candidate retry mechanism on previous coordinate",
    "all candidates fail returns 0 with no dispatch",
    "double Method87 distinct targets and second target write",
    "integrated state+collision with real linked children",
]


@pytest.fixture(scope="module")
def collision_test(tmp_path_factory):
    """Compile the actual collision source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("collision regressions require g++")
    fixture = tmp_path_factory.mktemp("action-collision")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "collision-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_collision.cpp",
            "src/unit_action_state.cpp",
            "tests/native/unit_action_collision_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_collision_behavior(collision_test, case):
    """Verify collision checks, vtable dispatch, and coordinate updates."""
    result = subprocess.run([str(collision_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
