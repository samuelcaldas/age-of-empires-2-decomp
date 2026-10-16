"""Native regressions for unit_action_combat_timing interval accumulation and combat range checks."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026C3C0 interval accumulator and timer reset",
    "func_0026C480 combat range verification",
]


@pytest.fixture(scope="module")
def combat_timing_test(tmp_path_factory):
    """Compile the actual combat_timing source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("combat_timing regressions require g++")
    fixture = tmp_path_factory.mktemp("action-combat-timing")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "combat-timing-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_combat_timing.cpp",
            "tests/native/unit_action_combat_timing_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_combat_timing_behavior(combat_timing_test, case):
    """Verify combat timing intervals and range checks."""
    result = subprocess.run([str(combat_timing_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
