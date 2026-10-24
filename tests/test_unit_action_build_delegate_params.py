"""Native regressions for unit_action_build_delegate_params."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00271150 flag57 non-zero skips world check and completes delegation",
    "func_00271150 f368 non-zero skips world check and completes delegation",
    "func_00271150 world check null return aborts before delegation",
    "func_00271150 successful dual world check completes delegation",
]


@pytest.fixture(scope="module")
def build_delegate_params_test(tmp_path_factory):
    """Compile actual build_delegate_params source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_delegate_params regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-delegate-params")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-delegate-params-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_delegate_params.cpp",
            "tests/native/unit_action_build_delegate_params_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_delegate_params_behavior(build_delegate_params_test, case):
    """Verify flag guards, dual method36 world validation, and delegating dispatch."""
    result = subprocess.run([str(build_delegate_params_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
