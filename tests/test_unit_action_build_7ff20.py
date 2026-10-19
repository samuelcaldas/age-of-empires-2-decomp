"""Native regressions for unit_action_build_7ff20 (Milestone 149)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027FF20 action factory dispatch with arg2",
    "func_0027FF20 action factory dispatch with floats",
    "func_0027FF20 null factory return handling",
    "func_0027FF20 fallback delegation to BaseList::CreateAction",
    "func_27FF20 alias verification",
]


@pytest.fixture(scope="module")
def build_7ff20_test(tmp_path_factory):
    """Compile unit_action_build_7ff20 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7ff20 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7ff20")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { sizeof(void *); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7ff20-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_7ff20.cpp",
            "tests/native/unit_action_build_7ff20_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7ff20_behavior(build_7ff20_test, case):
    """Verify action factory creation and initialization per case."""
    result = subprocess.run([str(build_7ff20_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
