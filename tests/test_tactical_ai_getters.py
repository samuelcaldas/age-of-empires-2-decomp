"""Native regressions for tactical_ai_getters (`0x142C80`–`0x142D10`).

Reconciled function extents:
- func_00142C80: [0x142C80, 0x142C90) (0x10 code), padding [0x142C90, 0x142C90) (0 B NOP)
- func_00142C90: [0x142C90, 0x142CA0) (0x10 code), padding [0x142CA0, 0x142CA0) (0 B NOP)
- func_00142CA0: [0x142CA0, 0x142CB4) (0x14 code), padding [0x142CB4, 0x142CC0) (12 B NOP)
- func_00142CC0: [0x142CC0, 0x142D08) (0x48 code), padding [0x142D08, 0x142D10) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_getters func_2c80",
    "tactical_ai_getters func_2c90",
    "tactical_ai_getters func_2ca0",
    "tactical_ai_getters func_2cc0 success",
    "tactical_ai_getters func_2cc0 overflow",
    "tactical_ai_getters layout",
]

MARKERS = [
    "TACTICAL_AI_GETTERS_TEST_0_2C80_PASSED",
    "TACTICAL_AI_GETTERS_TEST_1_2C90_PASSED",
    "TACTICAL_AI_GETTERS_TEST_2_2CA0_PASSED",
    "TACTICAL_AI_GETTERS_TEST_3_2CC0_SUCCESS_PASSED",
    "TACTICAL_AI_GETTERS_TEST_4_2CC0_OVERFLOW_PASSED",
    "TACTICAL_AI_GETTERS_TEST_5_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_getters_test(tmp_path_factory):
    """Compile tactical_ai_getters source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_getters regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-getters")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-getters-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_getters.cpp",
            "tests/native/tactical_ai_getters_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_getters_behavior(tactical_ai_getters_test, case):
    """Verify tactical_ai_getters functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_getters_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_getters_missing_selector(tactical_ai_getters_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_getters_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_getters_invalid_selector(tactical_ai_getters_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_getters_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_getters_nonnumeric_selector(tactical_ai_getters_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_getters_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
