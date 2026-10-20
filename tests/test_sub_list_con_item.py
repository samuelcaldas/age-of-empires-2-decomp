"""Native regressions for sub_list_con_item (`0x13DFB0`–`0x13E200`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_con_item func_0013DFB0 constructor",
    "sub_list_con_item func_0013E000 init",
    "sub_list_con_item func_0013E050 copy",
    "sub_list_con_item func_0013E0A0 destructor",
    "sub_list_con_item func_0013E110 position equality",
    "sub_list_con_item accessors and counters",
]

MARKERS = [
    "SUB_LIST_CON_ITEM_TEST_0_CTOR_PASSED",
    "SUB_LIST_CON_ITEM_TEST_1_INIT_PASSED",
    "SUB_LIST_CON_ITEM_TEST_2_COPY_PASSED",
    "SUB_LIST_CON_ITEM_TEST_3_DTOR_PASSED",
    "SUB_LIST_CON_ITEM_TEST_4_POS_EQ_PASSED",
    "SUB_LIST_CON_ITEM_TEST_5_ACCESSORS_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_con_item_test(tmp_path_factory):
    """Compile sub_list_con_item source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_con_item regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-con-item")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-con-item-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_con_item.cpp",
            "tests/native/sub_list_con_item_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_con_item_behavior(sub_list_con_item_test, case):
    """Verify sub_list_con_item functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_con_item_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_con_item_missing_selector(sub_list_con_item_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_con_item_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_con_item_invalid_selector(sub_list_con_item_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_con_item_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_con_item_nonnumeric_selector(sub_list_con_item_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_con_item_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
