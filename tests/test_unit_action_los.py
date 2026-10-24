"""Native regressions for unit_action_los sight calculations and mode switching."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "null world and non-positive radius guards",
    "circle LOS mode routing and diff calculations",
    "rect LOS mode bounds and routing",
    "entity field8 == 0x70 mode override",
]


@pytest.fixture(scope="module")
def los_test(tmp_path_factory):
    """Compile the actual LOS source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("LOS regressions require g++")
    fixture = tmp_path_factory.mktemp("action-los")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "los-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_los.cpp",
            "tests/native/unit_action_los_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_los_behavior(los_test, case):
    """Verify circle and rect sight additions and subtractions."""
    result = subprocess.run([str(los_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
