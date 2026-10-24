"""Native regressions for tactical_ai_scope (`0x1441B0`–`0x144440`).

Reconciled function extents:
- func_1441B0: [0x1441B0, 0x1442DC) (0x12C code), padding [0x1442DC, 0x1442E0) (4 B NOP)
- func_1442E0: [0x1442E0, 0x144304) (0x24 code), padding [0x144304, 0x144310) (12 B NOP)
- func_144310: [0x144310, 0x14433C) (0x2C code), padding [0x14433C, 0x144340) (4 B NOP)
- func_144340: [0x144340, 0x144438) (0xF8 code), padding [0x144438, 0x144440) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_scope func_1441b0",
    "tactical_ai_scope func_1442e0",
    "tactical_ai_scope func_144310",
    "tactical_ai_scope func_144340 null err",
    "tactical_ai_scope func_144340 filename param",
    "tactical_ai_scope func_144340 empty defaults",
    "tactical_ai_scope func_144340 no line codes",
    "tactical_ai_scope func_144340 unknown code",
    "tactical_ai_scope layout",
]

MARKERS = [
    "TACTICAL_AI_SCOPE_TEST_0_1441B0_PASSED",
    "TACTICAL_AI_SCOPE_TEST_1_1442E0_PASSED",
    "TACTICAL_AI_SCOPE_TEST_2_144310_PASSED",
    "TACTICAL_AI_SCOPE_TEST_3_144340_NULL_ERR_PASSED",
    "TACTICAL_AI_SCOPE_TEST_4_144340_FILENAME_PARAM_PASSED",
    "TACTICAL_AI_SCOPE_TEST_5_144340_EMPTY_DEFAULTS_PASSED",
    "TACTICAL_AI_SCOPE_TEST_6_144340_NO_LINE_CODES_PASSED",
    "TACTICAL_AI_SCOPE_TEST_7_144340_UNKNOWN_CODE_PASSED",
    "TACTICAL_AI_SCOPE_TEST_8_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_scope_test(tmp_path_factory):
    """Compile tactical_ai_scope source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_scope regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-scope")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-scope-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_scope.cpp",
            "tests/native/tactical_ai_scope_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_scope_behavior(tactical_ai_scope_test, case):
    """Verify tactical_ai_scope functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_scope_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_scope_missing_selector(tactical_ai_scope_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scope_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_scope_invalid_selector(tactical_ai_scope_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scope_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_scope_nonnumeric_selector(tactical_ai_scope_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_scope_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
