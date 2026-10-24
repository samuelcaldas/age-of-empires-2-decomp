"""Native regressions for tactical_ai_parser (`0x142D10`–`0x143020`).

Reconciled function extents:
- func_00142D10: [0x142D10, 0x143018) (0x308 code), padding [0x143018, 0x143020) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_parser success",
    "tactical_ai_parser eof first",
    "tactical_ai_parser invalid first tok",
    "tactical_ai_parser unknown action",
    "tactical_ai_parser invalid param type",
    "tactical_ai_parser string intern fail",
    "tactical_ai_parser symbol lookup fail",
    "tactical_ai_parser closing fail",
    "tactical_ai_parser layout",
    "tactical_ai_parser param loop eof",
    "tactical_ai_parser invalid param type strict",
    "tactical_ai_parser string intern fail strict",
]

MARKERS = [
    "TACTICAL_AI_PARSER_TEST_0_SUCCESS_PASSED",
    "TACTICAL_AI_PARSER_TEST_1_EOF_FIRST_PASSED",
    "TACTICAL_AI_PARSER_TEST_2_INVALID_FIRST_TOK_PASSED",
    "TACTICAL_AI_PARSER_TEST_3_UNKNOWN_ACTION_PASSED",
    "TACTICAL_AI_PARSER_TEST_4_INVALID_PARAM_TYPE_PASSED",
    "TACTICAL_AI_PARSER_TEST_5_STRING_INTERN_FAIL_PASSED",
    "TACTICAL_AI_PARSER_TEST_6_SYMBOL_LOOKUP_FAIL_PASSED",
    "TACTICAL_AI_PARSER_TEST_7_CLOSING_FAIL_PASSED",
    "TACTICAL_AI_PARSER_TEST_8_LAYOUT_PASSED",
    "TACTICAL_AI_PARSER_TEST_9_PARAM_LOOP_EOF_PASSED",
    "TACTICAL_AI_PARSER_TEST_10_INVALID_PARAM_TYPE_STRICT_PASSED",
    "TACTICAL_AI_PARSER_TEST_11_STRING_INTERN_FAIL_STRICT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_parser_test(tmp_path_factory):
    """Compile tactical_ai_parser source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_parser regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-parser")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-parser-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_parser.cpp",
            "tests/native/tactical_ai_parser_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_parser_behavior(tactical_ai_parser_test, case):
    """Verify tactical_ai_parser functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_parser_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_parser_missing_selector(tactical_ai_parser_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_parser_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_parser_invalid_selector(tactical_ai_parser_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_parser_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_parser_nonnumeric_selector(tactical_ai_parser_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_parser_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
