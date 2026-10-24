"""Native regressions for con_ai_query (`0x13F190`–`0x13F3F0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_query func_0013F190 update item",
    "con_ai_query func_0013F220 reset by id no 1c0",
    "con_ai_query func_0013F220 reset by id with 1c0",
    "con_ai_query func_0013F220 reset by id not found",
    "con_ai_query func_0013F2F0 reset by pos found",
    "con_ai_query func_0013F2F0 reset by pos not found",
]

MARKERS = [
    "CON_AI_QUERY_TEST_0_UPDATE_ITEM_PASSED",
    "CON_AI_QUERY_TEST_1_RESET_BY_ID_NO_1C0_PASSED",
    "CON_AI_QUERY_TEST_2_RESET_BY_ID_WITH_1C0_PASSED",
    "CON_AI_QUERY_TEST_3_RESET_BY_ID_NOT_FOUND_PASSED",
    "CON_AI_QUERY_TEST_4_RESET_BY_POS_FOUND_PASSED",
    "CON_AI_QUERY_TEST_5_RESET_BY_POS_NOT_FOUND_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_query_test(tmp_path_factory):
    """Compile con_ai_query source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_query regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-query")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-query-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/con_ai_query.cpp",
            "tests/native/con_ai_query_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_query_behavior(con_ai_query_test, case):
    """Verify con_ai_query functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_query_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_query_missing_selector(con_ai_query_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_query_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_query_invalid_selector(con_ai_query_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_query_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_query_nonnumeric_selector(con_ai_query_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_query_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
