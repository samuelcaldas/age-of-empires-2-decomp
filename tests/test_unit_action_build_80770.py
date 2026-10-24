"""Native regressions for unit_action_build_80770 (Milestone 152)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00280770 null self returns NULL without calls",
    "func_00280770 non-null positive count initializes vtable and calls __vec_ctor",
    "func_00280770 non-null zero/negative count skips __vec_ctor",
    "func_280770 alias verification",
]


@pytest.fixture(scope="module")
def build_80770_test(tmp_path_factory):
    """Compile unit_action_build_80770 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_80770 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-80770")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-80770-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_80770.cpp",
            "tests/native/unit_action_build_80770_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_80770_behavior(build_80770_test, case):
    """Verify constructor initialization and boundary behavior per case."""
    result = subprocess.run([str(build_80770_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
