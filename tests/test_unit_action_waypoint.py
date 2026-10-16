"""Native regressions for unit_action_waypoint tile queries, coordinate vectors, and rotation angles."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026AC30 radius getter (100% exact match)",
    "func_0026A9E0 3D coordinate vector copy",
    "func_0026A700 tile coords and world query",
    "func_0026AA00 angle calculation and frame update",
]


@pytest.fixture(scope="module")
def waypoint_test(tmp_path_factory):
    """Compile the actual waypoint source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("waypoint regressions require g++")
    fixture = tmp_path_factory.mktemp("action-waypoint")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "waypoint-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_waypoint.cpp",
            "tests/native/unit_action_waypoint_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_waypoint_behavior(waypoint_test, case):
    """Verify tile coordinate resolution, 3D vector stores, and rotation angles."""
    result = subprocess.run([str(waypoint_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
