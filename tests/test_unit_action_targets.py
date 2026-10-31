"""Native regressions for unit_action_targets."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00267380 sets or clamps m_z based on field4 flag",
    "func_002673D0 switches target and dispatches notifications",
    "func_002674C0 notifies fieldC with target and code",
    "func_00267500 notifies fieldC with target release",
    "func_00267530 returns early when entity is null",
    "func_00267530 executes full target binding chain and method dispatch",
]


@pytest.fixture(scope="module")
def targets_test(tmp_path_factory):
    """Compile the actual unit_action_targets source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("unit_action_targets regressions require g++")
    fixture = tmp_path_factory.mktemp("action-targets")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "action-targets-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_targets.cpp",
            "tests/native/unit_action_targets_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_targets_behavior(targets_test, case):
    """Verify target manipulation, bound checks, and notification dispatch."""
    result = subprocess.run([str(targets_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
