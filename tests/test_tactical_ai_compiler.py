"""Native regressions for tactical_ai_compiler (`0x143020`–`0x143440`).

Reconciled function extents:
- func_00143020: [0x143020, 0x143434) (0x414 code), padding [0x143434, 0x143440) (12 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_compiler leaf condition",
    "tactical_ai_compiler connective unary",
    "tactical_ai_compiler missing lparen",
    "tactical_ai_compiler eof first",
    "tactical_ai_compiler unknown identifier",
    "tactical_ai_compiler invalid token type",
    "tactical_ai_compiler closing fail",
    "tactical_ai_compiler layout",
]

MARKERS = [
    "TACTICAL_AI_COMPILER_TEST_0_LEAF_PASSED",
    "TACTICAL_AI_COMPILER_TEST_1_CONNECTIVE_UNARY_PASSED",
    "TACTICAL_AI_COMPILER_TEST_2_MISSING_LPAREN_PASSED",
    "TACTICAL_AI_COMPILER_TEST_3_EOF_FIRST_PASSED",
    "TACTICAL_AI_COMPILER_TEST_4_UNKNOWN_IDENTIFIER_PASSED",
    "TACTICAL_AI_COMPILER_TEST_5_INVALID_TOKEN_TYPE_PASSED",
    "TACTICAL_AI_COMPILER_TEST_6_CLOSING_FAIL_PASSED",
    "TACTICAL_AI_COMPILER_TEST_7_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_compiler_test(tmp_path_factory):
    """Compile tactical_ai_compiler source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_compiler regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-compiler")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-compiler-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_compiler.cpp",
            "tests/native/tactical_ai_compiler_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_compiler_behavior(tactical_ai_compiler_test, case):
    """Verify tactical_ai_compiler functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_compiler_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_compiler_missing_selector(tactical_ai_compiler_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_compiler_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_compiler_invalid_selector(tactical_ai_compiler_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_compiler_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_compiler_nonnumeric_selector(tactical_ai_compiler_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_compiler_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
