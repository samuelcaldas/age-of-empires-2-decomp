"""Native regressions for unit_action_state child filtering, indexing, and capacity checks."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00268590 child index traversal",
    "func_002687C0 capacity check at field4 + 1",
    "func_00268610 filter child actions by state, entity attributes, and bounds",
    "func_002685C0 while loop calling Method58 until child list empty",
    "func_00268530 guard behavior (0 returns 0, nonzero counts)",
]


@pytest.fixture(scope="module")
def state_test(tmp_path_factory):
    """Compile the actual state source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("state regressions require g++")
    fixture = tmp_path_factory.mktemp("action-state")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "state-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_state.cpp",
            "tests/native/unit_action_state_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_state_behavior(state_test, case):
    """Verify child index traversal, capacity comparison at field4+1, and child filtering."""
    result = subprocess.run([str(state_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
