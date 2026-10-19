"""Native regressions for tactical_ai_analyzer (`0x143440`–`0x143860`).

Reconciled function extents:
- func_143440: [0x143440, 0x143858) (0x418 code), padding [0x143858, 0x143860) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_analyzer load",
    "tactical_ai_analyzer load random",
    "tactical_ai_analyzer defrule",
    "tactical_ai_analyzer defconst int",
    "tactical_ai_analyzer defconst sym",
    "tactical_ai_analyzer unknown keyword",
    "tactical_ai_analyzer first eof",
    "tactical_ai_analyzer first not ident",
    "tactical_ai_analyzer defrule link fail",
    "tactical_ai_analyzer layout",
]

MARKERS = [
    "TACTICAL_AI_ANALYZER_TEST_0_LOAD_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_1_LOAD_RANDOM_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_2_DEFRULE_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_3_DEFCONST_INT_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_4_DEFCONST_SYM_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_5_UNKNOWN_KEYWORD_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_6_FIRST_EOF_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_7_FIRST_NOT_IDENT_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_8_DEFRULE_LINK_FAIL_PASSED",
    "TACTICAL_AI_ANALYZER_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_analyzer_test(tmp_path_factory):
    """Compile tactical_ai_analyzer source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_analyzer regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-analyzer")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-analyzer-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_analyzer.cpp",
            "tests/native/tactical_ai_analyzer_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_analyzer_behavior(tactical_ai_analyzer_test, case):
    """Verify tactical_ai_analyzer functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_analyzer_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_analyzer_missing_selector(tactical_ai_analyzer_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_analyzer_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_analyzer_invalid_selector(tactical_ai_analyzer_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_analyzer_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_analyzer_nonnumeric_selector(tactical_ai_analyzer_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_analyzer_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
