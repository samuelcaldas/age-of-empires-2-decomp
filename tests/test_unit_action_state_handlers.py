"""Native regressions for unit_action_state_handlers state transition and exit handlers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026B130 state transition dispatch and flag resets",
    "func_0026B360 state exit handler and sight notification",
]


@pytest.fixture(scope="module")
def state_handlers_test(tmp_path_factory):
    """Compile the actual state_handlers source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("state_handlers regressions require g++")
    fixture = tmp_path_factory.mktemp("action-state-handlers")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "state-handlers-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_state_handlers.cpp",
            "tests/native/unit_action_state_handlers_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_state_handlers_behavior(state_handlers_test, case):
    """Verify state transition dispatch, flag clearing, and sight notifications."""
    result = subprocess.run([str(state_handlers_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
