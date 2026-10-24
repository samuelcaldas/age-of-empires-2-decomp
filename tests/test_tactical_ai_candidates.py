"""Native regressions for tactical_ai_candidates (`0x142680`–`0x142830`).

Reconciled function extents:
- func_00142680: [0x142680, 0x14272C) (0xAC code), padding [0x14272C, 0x142730) (4 B NOP)
- func_00142730: [0x142730, 0x14279C) (0x6C code), padding [0x14279C, 0x1427A0) (4 B NOP)
- func_001427A0: [0x1427A0, 0x142824) (0x84 code), padding [0x142824, 0x142830) (12 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_candidates func_2680 cached",
    "tactical_ai_candidates func_2680 alloc success",
    "tactical_ai_candidates func_2680 alloc fail",
    "tactical_ai_candidates func_2730 first hit",
    "tactical_ai_candidates func_2730 second call",
    "tactical_ai_candidates func_27a0 success",
    "tactical_ai_candidates func_27a0 invalid 19c",
    "tactical_ai_candidates func_27a0 status 1",
    "tactical_ai_candidates func_27a0 status 0",
    "tactical_ai_candidates layout",
]

MARKERS = [
    "TACTICAL_AI_CANDIDATES_TEST_0_2680_CACHED_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_1_2680_ALLOC_SUCCESS_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_2_2680_ALLOC_FAIL_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_3_2730_FIRST_HIT_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_4_2730_SECOND_CALL_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_5_27A0_SUCCESS_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_6_27A0_INVALID_19C_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_7_27A0_STATUS_1_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_8_27A0_STATUS_0_PASSED",
    "TACTICAL_AI_CANDIDATES_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_candidates_test(tmp_path_factory):
    """Compile tactical_ai_candidates source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_candidates regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-candidates")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-candidates-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_candidates.cpp",
            "tests/native/tactical_ai_candidates_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_candidates_behavior(tactical_ai_candidates_test, case):
    """Verify tactical_ai_candidates functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_candidates_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_candidates_missing_selector(tactical_ai_candidates_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_candidates_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_candidates_invalid_selector(tactical_ai_candidates_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_candidates_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_candidates_nonnumeric_selector(tactical_ai_candidates_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_candidates_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
