"""Native regressions for tactical_ai_scoring (`0x142830`–`0x142980`).

Reconciled function extents:
- func_00142830: [0x142830, 0x1428AC) (0x7C code), padding [0x1428AC, 0x1428B0) (4 B NOP)
- func_001428B0: [0x1428B0, 0x142978) (0xC8 code), padding [0x142978, 0x142980) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_scoring func_2830 success",
    "tactical_ai_scoring func_2830 invalid 19c",
    "tactical_ai_scoring func_2830 res 1",
    "tactical_ai_scoring func_2830 res 0",
    "tactical_ai_scoring func_28b0 newline",
    "tactical_ai_scoring func_28b0 words and newline",
    "tactical_ai_scoring func_28b0 eof",
    "tactical_ai_scoring layout",
]

MARKERS = [
    "TACTICAL_AI_SCORING_TEST_0_2830_SUCCESS_PASSED",
    "TACTICAL_AI_SCORING_TEST_1_2830_INVALID_19C_PASSED",
    "TACTICAL_AI_SCORING_TEST_2_2830_RES_1_PASSED",
    "TACTICAL_AI_SCORING_TEST_3_2830_RES_0_PASSED",
    "TACTICAL_AI_SCORING_TEST_4_28B0_NEWLINE_PASSED",
    "TACTICAL_AI_SCORING_TEST_5_28B0_WORDS_AND_NEWLINE_PASSED",
    "TACTICAL_AI_SCORING_TEST_6_28B0_EOF_PASSED",
    "TACTICAL_AI_SCORING_TEST_7_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_scoring_test(tmp_path_factory):
    """Compile tactical_ai_scoring source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_scoring regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-scoring")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-scoring-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_scoring.cpp",
            "tests/native/tactical_ai_scoring_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_scoring_behavior(tactical_ai_scoring_test, case):
    """Verify tactical_ai_scoring functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_scoring_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_scoring_missing_selector(tactical_ai_scoring_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scoring_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_scoring_invalid_selector(tactical_ai_scoring_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scoring_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_scoring_nonnumeric_selector(tactical_ai_scoring_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scoring_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
