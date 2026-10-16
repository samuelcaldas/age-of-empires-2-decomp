"""Native regressions for unit_action_movement_ops movement reset and stream updates."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026B550 movement reset and flags",
    "func_0026B710 and func_0026BA00 stream update",
]


@pytest.fixture(scope="module")
def movement_ops_test(tmp_path_factory):
    """Compile the actual movement_ops source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("movement_ops regressions require g++")
    fixture = tmp_path_factory.mktemp("action-movement-ops")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "movement-ops-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_movement_ops.cpp",
            "tests/native/unit_action_movement_ops_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_movement_ops_behavior(movement_ops_test, case):
    """Verify movement resets, flags clearing, and stream serialization."""
    result = subprocess.run([str(movement_ops_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
