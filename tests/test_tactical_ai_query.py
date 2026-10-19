"""Native regressions for tactical_ai_query (`0x141250`–`0x141500`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_query func_1250 no table",
    "tactical_ai_query func_1250 with table",
    "tactical_ai_query func_1250 capacity full",
    "tactical_ai_query func_1370 invalid index",
    "tactical_ai_query func_1370 fast path",
    "tactical_ai_query func_1370 expansion path",
    "tactical_ai_query func_1370 expansion overflow",
    "tactical_ai_query func_1470",
    "tactical_ai_query func_14a0",
    "tactical_ai_query layout",
]

MARKERS = [
    "TACTICAL_AI_QUERY_TEST_0_FUNC_1250_NO_TABLE_PASSED",
    "TACTICAL_AI_QUERY_TEST_1_FUNC_1250_WITH_TABLE_PASSED",
    "TACTICAL_AI_QUERY_TEST_2_FUNC_1250_CAPACITY_FULL_PASSED",
    "TACTICAL_AI_QUERY_TEST_3_FUNC_1370_INVALID_INDEX_PASSED",
    "TACTICAL_AI_QUERY_TEST_4_FUNC_1370_FAST_PATH_PASSED",
    "TACTICAL_AI_QUERY_TEST_5_FUNC_1370_EXPANSION_PATH_PASSED",
    "TACTICAL_AI_QUERY_TEST_6_FUNC_1370_EXPANSION_OVERFLOW_PASSED",
    "TACTICAL_AI_QUERY_TEST_7_FUNC_1470_PASSED",
    "TACTICAL_AI_QUERY_TEST_8_FUNC_14A0_PASSED",
    "TACTICAL_AI_QUERY_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_query_test(tmp_path_factory):
    """Compile tactical_ai_query source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_query regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-query")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-query-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_query.cpp",
            "tests/native/tactical_ai_query_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_query_behavior(tactical_ai_query_test, case):
    """Verify tactical_ai_query functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_query_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_query_missing_selector(tactical_ai_query_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_query_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_query_invalid_selector(tactical_ai_query_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_query_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_query_nonnumeric_selector(tactical_ai_query_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_query_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
