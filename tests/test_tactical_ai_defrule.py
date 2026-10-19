"""Native regressions for tactical_ai_defrule (`0x143E00`–`0x144050`).

Reconciled function extents:
- func_143E00: [0x143E00, 0x144050) (0x250 code), padding [0x144050, 0x144050) (0 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_defrule success",
    "tactical_ai_defrule no name",
    "tactical_ai_defrule multiple items",
    "tactical_ai_defrule missing cond before arrow",
    "tactical_ai_defrule invalid arrow",
    "tactical_ai_defrule cond fail",
    "tactical_ai_defrule missing action",
    "tactical_ai_defrule action fail",
    "tactical_ai_defrule missing close paren",
    "tactical_ai_defrule layout",
]

MARKERS = [
    "TACTICAL_AI_DEFRULE_TEST_0_SUCCESS_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_1_NO_NAME_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_2_MULTIPLE_ITEMS_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_3_MISSING_COND_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_4_INVALID_ARROW_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_5_COND_FAIL_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_6_MISSING_ACTION_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_7_ACTION_FAIL_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_8_MISSING_CLOSE_PAREN_PASSED",
    "TACTICAL_AI_DEFRULE_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_defrule_test(tmp_path_factory):
    """Compile tactical_ai_defrule source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_defrule regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-defrule")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-defrule-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_defrule.cpp",
            "tests/native/tactical_ai_defrule_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_defrule_behavior(tactical_ai_defrule_test, case):
    """Verify tactical_ai_defrule functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_defrule_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_defrule_missing_selector(tactical_ai_defrule_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_defrule_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_defrule_invalid_selector(tactical_ai_defrule_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_defrule_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_defrule_nonnumeric_selector(tactical_ai_defrule_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_defrule_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
