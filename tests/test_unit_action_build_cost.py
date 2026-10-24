"""Native regressions for unit_action_build_cost."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026EDF0 and func_0026EE70 guard checks on null inputs",
    "func_0026EDF0 Method19 dispatch, state notification, and frame update",
    "func_0026EE70 master type dispatch",
]


@pytest.fixture(scope="module")
def build_cost_test(tmp_path_factory):
    """Compile the actual build_cost source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_cost regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-cost")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-cost-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_cost.cpp",
            "tests/native/unit_action_build_cost_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_cost_behavior(build_cost_test, case):
    """Verify Method19 target updates, state notifications, and master type checks."""
    result = subprocess.run([str(build_cost_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
