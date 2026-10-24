"""Native regressions for diplomacy_ai_helpers (`0x13FC80`–`0x13FEF0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "diplomacy_ai_helpers func_0013FC80 bounds",
    "diplomacy_ai_helpers func_0013FC80 mode 0 clamping",
    "diplomacy_ai_helpers func_0013FC80 mode 1 noop",
    "diplomacy_ai_helpers func_0013FC80 mode 2 clamping",
    "diplomacy_ai_helpers func_0013FDA0 check",
    "diplomacy_ai_helpers func_0013FDF0 set",
    "diplomacy_ai_helpers func_0013FE30 facts and call",
    "diplomacy_ai_helpers func_0013FEE0 returns minus one",
]

MARKERS = [
    "DIPLOMACY_AI_HELPERS_TEST_0_FC80_BOUNDS_PASSED",
    "DIPLOMACY_AI_HELPERS_TEST_1_FC80_MODE_0_CLAMPING_PASSED",
    "DIPLOMACY_AI_HELPERS_TEST_2_FC80_MODE_1_NOOP_PASSED",
    "DIPLOMACY_AI_HELPERS_TEST_3_FC80_MODE_2_CLAMPING_PASSED",
    "DIPLOMACY_AI_HELPERS_TEST_4_FDA0_CHECK_PASSED",
    "DIPLOMACY_AI_HELPERS_TEST_5_FDF0_SET_PASSED",
    "DIPLOMACY_AI_HELPERS_TEST_6_FE30_FACTS_AND_CALL_PASSED",
    "DIPLOMACY_AI_HELPERS_TEST_7_FEE0_RETURNS_MINUS_ONE_PASSED",
]


@pytest.fixture(scope="module")
def diplomacy_ai_helpers_test(tmp_path_factory):
    """Compile diplomacy_ai_helpers source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("diplomacy_ai_helpers regressions require g++")
    fixture = tmp_path_factory.mktemp("diplomacy-ai-helpers")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "diplomacy-ai-helpers-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/diplomacy_ai_helpers.cpp",
            "tests/native/diplomacy_ai_helpers_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_diplomacy_ai_helpers_behavior(diplomacy_ai_helpers_test, case):
    """Verify diplomacy_ai_helpers functionality and unique test case markers."""
    result = subprocess.run([str(diplomacy_ai_helpers_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_diplomacy_ai_helpers_missing_selector(diplomacy_ai_helpers_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_helpers_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_diplomacy_ai_helpers_invalid_selector(diplomacy_ai_helpers_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_helpers_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_diplomacy_ai_helpers_nonnumeric_selector(diplomacy_ai_helpers_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_helpers_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
