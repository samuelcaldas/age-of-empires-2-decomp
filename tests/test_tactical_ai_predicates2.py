"""Native regressions for tactical_ai_predicates2 (`0x143860`–`0x143AD0`).

Reconciled function extents:
- func_143860: [0x143860, 0x143AC4) (0x264 code), padding [0x143AC4, 0x143AD0) (12 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_predicates2 load if defined hit",
    "tactical_ai_predicates2 load if defined miss",
    "tactical_ai_predicates2 load if not defined hit",
    "tactical_ai_predicates2 load if not defined miss",
    "tactical_ai_predicates2 nesting limit",
    "tactical_ai_predicates2 syntax fail",
    "tactical_ai_predicates2 else success",
    "tactical_ai_predicates2 else no open if",
    "tactical_ai_predicates2 endif success",
    "tactical_ai_predicates2 endif no open if",
    "tactical_ai_predicates2 unknown directive",
    "tactical_ai_predicates2 layout",
]

MARKERS = [
    "TACTICAL_AI_PREDICATES2_TEST_0_LOAD_IF_DEF_HIT_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_1_LOAD_IF_DEF_MISS_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_2_LOAD_IF_NOT_DEF_HIT_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_3_LOAD_IF_NOT_DEF_MISS_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_4_NESTING_LIMIT_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_5_SYNTAX_FAIL_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_6_ELSE_SUCCESS_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_7_ELSE_NO_OPEN_IF_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_8_ENDIF_SUCCESS_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_9_ENDIF_NO_OPEN_IF_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_10_UNKNOWN_DIRECTIVE_PASSED",
    "TACTICAL_AI_PREDICATES2_TEST_11_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_predicates2_test(tmp_path_factory):
    """Compile tactical_ai_predicates2 source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_predicates2 regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-predicates2")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-predicates2-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_predicates2.cpp",
            "tests/native/tactical_ai_predicates2_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_predicates2_behavior(tactical_ai_predicates2_test, case):
    """Verify tactical_ai_predicates2 functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_predicates2_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_predicates2_missing_selector(tactical_ai_predicates2_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_predicates2_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_predicates2_invalid_selector(tactical_ai_predicates2_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_predicates2_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_predicates2_nonnumeric_selector(tactical_ai_predicates2_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_predicates2_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
