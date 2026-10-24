"""Native regressions for sub_list_handlers (`0x13AE00`–`0x13B0B0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_handlers func_0013AE00 direct match",
    "sub_list_handlers func_0013AE00 loop fallback match",
    "sub_list_handlers func_0013AE00 no match",
    "sub_list_handlers func_0013AF70 empty list",
    "sub_list_handlers func_0013AF70 has items",
    "sub_list_handlers func_0013AFC0 field D0",
    "sub_list_handlers func_0013AFD0 null base",
    "sub_list_handlers func_0013AFD0 sum",
    "sub_list_handlers func_0013B020 null base",
    "sub_list_handlers func_0013B020 head exists",
    "sub_list_handlers func_0013B070 contains",
]

MARKERS = [
    "SUB_LIST_HANDLERS_TEST_0_AE00_DIRECT_MATCH_PASSED",
    "SUB_LIST_HANDLERS_TEST_1_AE00_LOOP_FALLBACK_PASSED",
    "SUB_LIST_HANDLERS_TEST_2_AE00_NO_MATCH_PASSED",
    "SUB_LIST_HANDLERS_TEST_3_AF70_EMPTY_PASSED",
    "SUB_LIST_HANDLERS_TEST_4_AF70_HAS_ITEMS_PASSED",
    "SUB_LIST_HANDLERS_TEST_5_AFC0_FIELD_D0_PASSED",
    "SUB_LIST_HANDLERS_TEST_6_AFD0_NULL_BASE_PASSED",
    "SUB_LIST_HANDLERS_TEST_7_AFD0_SUM_PASSED",
    "SUB_LIST_HANDLERS_TEST_8_B020_NULL_BASE_PASSED",
    "SUB_LIST_HANDLERS_TEST_9_B020_HEAD_EXISTS_PASSED",
    "SUB_LIST_HANDLERS_TEST_10_B070_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_handlers_test(tmp_path_factory):
    """Compile sub_list_handlers source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_handlers regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-handlers")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-handlers-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_handlers.cpp",
            "tests/native/sub_list_handlers_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_handlers_behavior(sub_list_handlers_test, case):
    """Verify sub_list_handlers functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_handlers_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_handlers_missing_selector(sub_list_handlers_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_handlers_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_handlers_invalid_selector(sub_list_handlers_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_handlers_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_handlers_nonnumeric_selector(sub_list_handlers_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_handlers_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
