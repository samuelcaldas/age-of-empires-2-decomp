"""Native regressions for unit_action_advance animation frames and timer ticking."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00268EB0 weighted table sum",
    "func_00268F00 frame modulo wrapping",
    "func_00268F40 and func_00268F50 progress setters and clamps",
    "func_00268FB0 timer advancement and cycle completion",
    "func_00268DE0 tick update and waypoint routing",
]


@pytest.fixture(scope="module")
def advance_test(tmp_path_factory):
    """Compile the actual advance source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("advance regressions require g++")
    fixture = tmp_path_factory.mktemp("action-advance")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "advance-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_advance.cpp",
            "tests/native/unit_action_advance_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_advance_behavior(advance_test, case):
    """Verify animation frames, progress clamps, and timer tick transitions."""
    result = subprocess.run([str(advance_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
