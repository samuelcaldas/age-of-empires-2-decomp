"""Native regressions for tactical_ai_scanner (`0x142980`–`0x142C80`).

Reconciled function extents:
- func_142980: [0x142980, 0x142C7C) (0x2FC code), padding [0x142C7C, 0x142C80) (4 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_scanner identifier",
    "tactical_ai_scanner lparen",
    "tactical_ai_scanner rparen",
    "tactical_ai_scanner quote",
    "tactical_ai_scanner quote err nl",
    "tactical_ai_scanner quote err eof",
    "tactical_ai_scanner comment refill",
    "tactical_ai_scanner refill eof",
    "tactical_ai_scanner whitespace",
    "tactical_ai_scanner layout",
]

MARKERS = [
    "TACTICAL_AI_SCANNER_TEST_0_IDENTIFIER_PASSED",
    "TACTICAL_AI_SCANNER_TEST_1_LPAREN_PASSED",
    "TACTICAL_AI_SCANNER_TEST_2_RPAREN_PASSED",
    "TACTICAL_AI_SCANNER_TEST_3_QUOTE_PASSED",
    "TACTICAL_AI_SCANNER_TEST_4_QUOTE_ERR_NL_PASSED",
    "TACTICAL_AI_SCANNER_TEST_5_QUOTE_ERR_EOF_PASSED",
    "TACTICAL_AI_SCANNER_TEST_6_COMMENT_REFILL_PASSED",
    "TACTICAL_AI_SCANNER_TEST_7_REFILL_EOF_PASSED",
    "TACTICAL_AI_SCANNER_TEST_8_WHITESPACE_PASSED",
    "TACTICAL_AI_SCANNER_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_scanner_test(tmp_path_factory):
    """Compile tactical_ai_scanner source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_scanner regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-scanner")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-scanner-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_scanner.cpp",
            "tests/native/tactical_ai_scanner_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_scanner_behavior(tactical_ai_scanner_test, case):
    """Verify tactical_ai_scanner functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_scanner_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_scanner_missing_selector(tactical_ai_scanner_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scanner_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_scanner_invalid_selector(tactical_ai_scanner_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scanner_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_scanner_nonnumeric_selector(tactical_ai_scanner_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scanner_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
