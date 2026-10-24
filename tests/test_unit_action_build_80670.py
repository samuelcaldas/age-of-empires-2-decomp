"""Native regressions for unit_action_build_80670 (Milestone 150)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00280670 clears flag byte through pointer",
    "func_00280670 clears various initial byte values",
    "func_00280670 does not overwrite neighboring bytes",
    "func_280670 alias verification",
]


@pytest.fixture(scope="module")
def build_80670_test(tmp_path_factory):
    """Compile unit_action_build_80670 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_80670 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-80670")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-80670-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_80670.cpp",
            "tests/native/unit_action_build_80670_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_80670_behavior(build_80670_test, case):
    """Verify byte clear behavior per case."""
    result = subprocess.run([str(build_80670_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
