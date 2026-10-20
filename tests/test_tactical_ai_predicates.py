"""Native regressions for tactical_ai_predicates (`0x141A70`–`0x141D40`).

Reconciled function extents:
- func_00141A70: [0x141A70, 0x141C68) (0x1F8 code), padding [0x141C68, 0x141C70) (8 B NOP)
- func_00141C70: [0x141C70, 0x141D40) (0xD0 code), padding [0x141D40, 0x141D40) (0 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_predicates leaf item",
    "tactical_ai_predicates not unary",
    "tactical_ai_predicates and xor",
    "tactical_ai_predicates or nor",
    "tactical_ai_predicates xnor nand",
    "tactical_ai_predicates default op",
    "tactical_ai_predicates 1c70 cond fail",
    "tactical_ai_predicates 1c70 actions success",
    "tactical_ai_predicates layout",
]

MARKERS = [
    "TACTICAL_AI_PREDICATES_TEST_0_LEAF_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_1_NOT_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_2_AND_XOR_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_3_OR_NOR_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_4_XNOR_NAND_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_5_DEFAULT_OP_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_6_1C70_COND_FAIL_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_7_1C70_ACTIONS_SUCCESS_PASSED",
    "TACTICAL_AI_PREDICATES_TEST_8_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_predicates_test(tmp_path_factory):
    """Compile tactical_ai_predicates source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_predicates regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-predicates")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-predicates-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_predicates.cpp",
            "tests/native/tactical_ai_predicates_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_predicates_behavior(tactical_ai_predicates_test, case):
    """Verify tactical_ai_predicates functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_predicates_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_predicates_missing_selector(tactical_ai_predicates_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_predicates_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_predicates_invalid_selector(tactical_ai_predicates_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_predicates_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_predicates_nonnumeric_selector(tactical_ai_predicates_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_predicates_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
