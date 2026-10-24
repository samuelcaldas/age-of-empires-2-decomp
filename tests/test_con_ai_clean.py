"""Native regressions for con_ai_clean (`0x13F4B0`–`0x13F730`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_clean func_0013F4B0 found in list 1",
    "con_ai_clean func_0013F4B0 found in list 2",
    "con_ai_clean func_0013F4B0 not found in either list",
    "con_ai_clean func_0013F5B0 found in list 2",
    "con_ai_clean func_0013F5B0 in list 1 only returns null",
    "con_ai_clean func_0013F650 frees list 1",
    "con_ai_clean func_0013F650 empty list 1",
    "con_ai_clean func_0013F6C0 fieldB0 zero early return",
    "con_ai_clean func_0013F6C0 frees list 2",
]

MARKERS = [
    "CON_AI_CLEAN_TEST_0_F4B0_FOUND_LIST1_PASSED",
    "CON_AI_CLEAN_TEST_1_F4B0_FOUND_LIST2_PASSED",
    "CON_AI_CLEAN_TEST_2_F4B0_NOT_FOUND_PASSED",
    "CON_AI_CLEAN_TEST_3_F5B0_FOUND_LIST2_PASSED",
    "CON_AI_CLEAN_TEST_4_F5B0_IN_LIST1_ONLY_RETURNS_NULL_PASSED",
    "CON_AI_CLEAN_TEST_5_F650_FREES_LIST1_PASSED",
    "CON_AI_CLEAN_TEST_6_F650_EMPTY_LIST1_PASSED",
    "CON_AI_CLEAN_TEST_7_F6C0_FIELDB0_ZERO_EARLY_RETURN_PASSED",
    "CON_AI_CLEAN_TEST_8_F6C0_FREES_LIST2_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_clean_test(tmp_path_factory):
    """Compile con_ai_clean source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_clean regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-clean")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-clean-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/con_ai_clean.cpp",
            "tests/native/con_ai_clean_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_clean_behavior(con_ai_clean_test, case):
    """Verify con_ai_clean functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_clean_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_clean_missing_selector(con_ai_clean_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_clean_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_clean_invalid_selector(con_ai_clean_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_clean_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_clean_nonnumeric_selector(con_ai_clean_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_clean_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
