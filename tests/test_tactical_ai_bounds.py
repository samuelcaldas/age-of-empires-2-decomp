"""Native regressions for tactical_ai_bounds (`0x1424A0`–`0x142680`).

Reconciled function extents:
- func_001424A0: [0x1424A0, 0x142558) (0xB8 code), padding [0x142558, 0x142560) (8 B NOP)
- func_00142560: [0x142560, 0x142678) (0x118 code), padding [0x142678, 0x142680) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_bounds func_24a0 success",
    "tactical_ai_bounds func_24a0 fail 2560",
    "tactical_ai_bounds func_24a0 fail field194",
    "tactical_ai_bounds func_2560 success 19c 1",
    "tactical_ai_bounds func_2560 success 19c 2",
    "tactical_ai_bounds func_2560 invalid 19c",
    "tactical_ai_bounds func_2560 non zero tok",
    "tactical_ai_bounds func_2560 stack mismatch",
    "tactical_ai_bounds layout",
]

MARKERS = [
    "TACTICAL_AI_BOUNDS_TEST_0_24A0_SUCCESS_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_1_24A0_FAIL_2560_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_2_24A0_FAIL_FIELD194_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_3_2560_SUCCESS_19C_1_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_4_2560_SUCCESS_19C_2_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_5_2560_INVALID_19C_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_6_2560_NON_ZERO_TOK_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_7_2560_STACK_MISMATCH_PASSED",
    "TACTICAL_AI_BOUNDS_TEST_8_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_bounds_test(tmp_path_factory):
    """Compile tactical_ai_bounds source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_bounds regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-bounds")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-bounds-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_bounds.cpp",
            "tests/native/tactical_ai_bounds_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_bounds_behavior(tactical_ai_bounds_test, case):
    """Verify tactical_ai_bounds functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_bounds_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_bounds_missing_selector(tactical_ai_bounds_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_bounds_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_bounds_invalid_selector(tactical_ai_bounds_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_bounds_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_bounds_nonnumeric_selector(tactical_ai_bounds_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_bounds_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
