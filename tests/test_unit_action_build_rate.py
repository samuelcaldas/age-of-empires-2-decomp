"""Native regressions for unit_action_build_rate."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026EF50 subactions early exit invokes method84 without world updates",
    "func_0026EF50 time <= 0 early return",
    "func_0026EF50 matching unit type 42 calculates rate from resource slots and emits stats",
    "func_0026EF50 non-matching unit type emits alternate stat sequence",
]


@pytest.fixture(scope="module")
def build_rate_test(tmp_path_factory):
    """Compile the actual build_rate source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_rate regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-rate")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-rate-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_rate.cpp",
            "tests/native/unit_action_build_rate_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_rate_behavior(build_rate_test, case):
    """Verify subaction exit, resource rate calculations, and stat dispatch."""
    result = subprocess.run([str(build_rate_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
