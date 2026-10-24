"""Native regressions for unit_action_build_progress."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026EC90 and func_0026ED90 guard checks on null inputs",
    "func_0026EC90 execution with item 0x67 vs standard",
    "func_0026ED90 percentage calculation",
]


@pytest.fixture(scope="module")
def build_progress_test(tmp_path_factory):
    """Compile the actual build_progress source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_progress regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-progress")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-progress-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_progress.cpp",
            "tests/native/unit_action_build_progress_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_progress_behavior(build_progress_test, case):
    """Verify item retrieval, resource checks, and progress percentages."""
    result = subprocess.run([str(build_progress_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
