"""Native regressions for unit_action_build_worker_pop."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270450 returns early when task count is zero",
    "func_00270450 decrements slot 0 amount and total without shifting when amount > 1",
    "func_00270450 shifts slots left and calls func_0026FF60 when slot 0 is depleted",
]


@pytest.fixture(scope="module")
def build_worker_pop_test(tmp_path_factory):
    """Compile the actual build_worker_pop source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_worker_pop regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-worker-pop")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-worker-pop-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_worker_pop.cpp",
            "tests/native/unit_action_build_worker_pop_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_worker_pop_behavior(build_worker_pop_test, case):
    """Verify single worker pop from slot 0, rate subtraction, and slot shifting."""
    result = subprocess.run([str(build_worker_pop_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
