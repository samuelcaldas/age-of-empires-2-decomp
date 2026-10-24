"""Native regressions for unit_action_build_notify_state."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270900 extracts state from item 102 via func_347880 and returns 1",
    "func_00270900 extracts primary slot 0 task_id when count is positive and returns 1",
    "func_00270900 returns 0 and resets output values when no active tasks exist",
]


@pytest.fixture(scope="module")
def build_notify_state_test(tmp_path_factory):
    """Compile the actual build_notify_state source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_notify_state regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-notify-state")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-notify-state-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_notify_state.cpp",
            "tests/native/unit_action_build_notify_state_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_notify_state_behavior(build_notify_state_test, case):
    """Verify task state queries, item 102 dispatch, and slot 0 fallback."""
    result = subprocess.run([str(build_notify_state_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
