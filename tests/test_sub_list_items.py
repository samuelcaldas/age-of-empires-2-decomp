"""Native regressions for sub_list_items (`0x13A700`–`0x13AA80`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_items func_0013A700 self guard",
    "sub_list_items func_0013A700 direct match",
    "sub_list_items func_0013A700 loop fallback match",
    "sub_list_items func_0013A870 null or contains guard",
    "sub_list_items func_0013A870 create item dispatch",
    "sub_list_items func_0013A910 null or contains guard",
    "sub_list_items func_0013A910 create item dispatch",
    "sub_list_items func_0013A9B0 add head dispatch",
    "sub_list_items func_0013A9D0 free and add head dispatch",
    "sub_list_items func_0013AA20 add tail dispatch",
    "sub_list_items func_0013AA40 call method13 and conditional free",
]

MARKERS = [
    "SUB_LIST_ITEMS_TEST_0_A700_SELF_PASSED",
    "SUB_LIST_ITEMS_TEST_1_A700_DIRECT_MATCH_PASSED",
    "SUB_LIST_ITEMS_TEST_2_A700_LOOP_FALLBACK_PASSED",
    "SUB_LIST_ITEMS_TEST_3_A870_NULL_OR_CONTAINS_PASSED",
    "SUB_LIST_ITEMS_TEST_4_A870_CREATES_PASSED",
    "SUB_LIST_ITEMS_TEST_5_A910_NULL_OR_CONTAINS_PASSED",
    "SUB_LIST_ITEMS_TEST_6_A910_CREATES_PASSED",
    "SUB_LIST_ITEMS_TEST_7_A9B0_ADD_HEAD_PASSED",
    "SUB_LIST_ITEMS_TEST_8_A9D0_FREE_ADD_HEAD_PASSED",
    "SUB_LIST_ITEMS_TEST_9_AA20_ADD_TAIL_PASSED",
    "SUB_LIST_ITEMS_TEST_10_AA40_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_items_test(tmp_path_factory):
    """Compile sub_list_items source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_items regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-items")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-items-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_items.cpp",
            "tests/native/sub_list_items_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_items_behavior(sub_list_items_test, case):
    """Verify sub_list_items functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_items_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_items_missing_selector(sub_list_items_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_items_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_items_invalid_selector(sub_list_items_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_items_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_items_nonnumeric_selector(sub_list_items_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_items_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
