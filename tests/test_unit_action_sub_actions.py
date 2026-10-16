"""Native regressions for unit_action_sub_actions."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026CF30 bypass when game inactive",
    "func_0026CF30 execution and loop update",
    "func_0026CF30 type 39 suppression",
]


@pytest.fixture(scope="module")
def sub_actions_test(tmp_path_factory):
    """Compile the actual sub_actions source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_actions regressions require g++")
    fixture = tmp_path_factory.mktemp("action-sub-actions")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-actions-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_sub_actions.cpp",
            "tests/native/unit_action_sub_actions_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_actions_behavior(sub_actions_test, case):
    """Verify sub_actions lifecycle, branching, and memory stores."""
    result = subprocess.run([str(sub_actions_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
