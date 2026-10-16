"""Native regressions for unit_action_resolve boundary resolution and helper dispatch."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "collision resolution, coordinate rounding, and helper invocation",
    "all 50 attempts fail due to obstacles and retain trailing candidate",
    "boundary rand 32767 side 4 preserves coordinates",
    "asymmetric full-integer arg1 comparison with arg1 > 255",
]


@pytest.fixture(scope="module")
def resolve_test(tmp_path_factory):
    """Compile the actual resolve source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("resolve regressions require g++")
    fixture = tmp_path_factory.mktemp("action-resolve")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "resolve-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_resolve.cpp",
            "tests/native/unit_action_resolve_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_resolve_behavior(resolve_test, case):
    """Verify coordinate rounding, helper dispatches, and boundary behavior."""
    result = subprocess.run([str(resolve_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
