"""Native regressions for diplomacy_ai_actions (`0x13FEF0`–`0x1401C0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "diplomacy_ai_actions func_13FEF0 skips self and status 2",
    "diplomacy_ai_actions func_13FEF0 a1 positive and a2 filter",
    "diplomacy_ai_actions func_13FEF0 skip conditions",
    "diplomacy_ai_actions func_13FEF0 score calculation",
    "diplomacy_ai_actions func_13FEF0 no valid player",
    "diplomacy_ai_actions func_001400B0 returns zero",
    "diplomacy_ai_actions func_001400C0 basic selection",
    "diplomacy_ai_actions func_001400C0 a1 positive a2 filter",
    "diplomacy_ai_actions func_001400C0 no valid player",
]

MARKERS = [
    "DIPLOMACY_AI_ACTIONS_TEST_0_FEF0_SKIPS_SELF_AND_STATUS2_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_1_FEF0_A1_POSITIVE_AND_A2_CHECKS_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_2_FEF0_SKIP_CONDITIONS_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_3_FEF0_SCORE_CALCULATION_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_4_FEF0_NO_VALID_PLAYER_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_5_001400B0_RETURNS_ZERO_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_6_001400C0_BASIC_SELECTION_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_7_001400C0_A1_POSITIVE_A2_FILTER_PASSED",
    "DIPLOMACY_AI_ACTIONS_TEST_8_001400C0_NO_VALID_PLAYER_PASSED",
]


@pytest.fixture(scope="module")
def diplomacy_ai_actions_test(tmp_path_factory):
    """Compile diplomacy_ai_actions source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("diplomacy_ai_actions regressions require g++")
    fixture = tmp_path_factory.mktemp("diplomacy-ai-actions")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "diplomacy-ai-actions-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/diplomacy_ai_actions.cpp",
            "tests/native/diplomacy_ai_actions_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_diplomacy_ai_actions_behavior(diplomacy_ai_actions_test, case):
    """Verify diplomacy_ai_actions functionality and unique test case markers."""
    result = subprocess.run([str(diplomacy_ai_actions_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_diplomacy_ai_actions_missing_selector(diplomacy_ai_actions_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_actions_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_diplomacy_ai_actions_invalid_selector(diplomacy_ai_actions_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_actions_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_diplomacy_ai_actions_nonnumeric_selector(diplomacy_ai_actions_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_actions_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
