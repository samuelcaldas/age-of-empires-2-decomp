"""Native regressions for tactical_ai_matrix (`0x141500`–`0x1418E0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_matrix func_1500 success",
    "tactical_ai_matrix func_1500 capacity full",
    "tactical_ai_matrix func_1630 invalid index",
    "tactical_ai_matrix func_1630 success reset",
    "tactical_ai_matrix func_1760 invalid index",
    "tactical_ai_matrix func_1760 scan nodes",
    "tactical_ai_matrix func_1760 null out",
    "tactical_ai_matrix func_18b0 active",
    "tactical_ai_matrix func_18b0 inactive",
    "tactical_ai_matrix layout",
]

MARKERS = [
    "TACTICAL_AI_MATRIX_TEST_0_FUNC_1500_SUCCESS_PASSED",
    "TACTICAL_AI_MATRIX_TEST_1_FUNC_1500_CAPACITY_FULL_PASSED",
    "TACTICAL_AI_MATRIX_TEST_2_FUNC_1630_INVALID_INDEX_PASSED",
    "TACTICAL_AI_MATRIX_TEST_3_FUNC_1630_SUCCESS_RESET_PASSED",
    "TACTICAL_AI_MATRIX_TEST_4_FUNC_1760_INVALID_INDEX_PASSED",
    "TACTICAL_AI_MATRIX_TEST_5_FUNC_1760_SCAN_NODES_PASSED",
    "TACTICAL_AI_MATRIX_TEST_6_FUNC_1760_NULL_OUT_PASSED",
    "TACTICAL_AI_MATRIX_TEST_7_FUNC_18B0_ACTIVE_PASSED",
    "TACTICAL_AI_MATRIX_TEST_8_FUNC_18B0_INACTIVE_PASSED",
    "TACTICAL_AI_MATRIX_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_matrix_test(tmp_path_factory):
    """Compile tactical_ai_matrix source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_matrix regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-matrix")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-matrix-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_matrix.cpp",
            "tests/native/tactical_ai_matrix_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_matrix_behavior(tactical_ai_matrix_test, case):
    """Verify tactical_ai_matrix functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_matrix_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_matrix_missing_selector(tactical_ai_matrix_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_matrix_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_matrix_invalid_selector(tactical_ai_matrix_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_matrix_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_matrix_nonnumeric_selector(tactical_ai_matrix_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_matrix_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
