"""Native regressions for sub_list_build_item (`0x13C8E0`–`0x13CC60`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_build_item func_0013C8E0 ctor",
    "sub_list_build_item func_0013C960 setter",
    "sub_list_build_item func_0013CA40 dtor",
    "sub_list_build_item func_0013CB10 idx",
    "sub_list_build_item func_0013CB90 and CBA0 inc dec 80",
    "sub_list_build_item func_0013CBE0 inc 94",
    "sub_list_build_item getters and setters",
]

MARKERS = [
    "SUB_LIST_BUILD_ITEM_TEST_0_CTOR_PASSED",
    "SUB_LIST_BUILD_ITEM_TEST_1_SETTER_PASSED",
    "SUB_LIST_BUILD_ITEM_TEST_2_DTOR_PASSED",
    "SUB_LIST_BUILD_ITEM_TEST_3_IDX_PASSED",
    "SUB_LIST_BUILD_ITEM_TEST_4_INC_DEC_80_PASSED",
    "SUB_LIST_BUILD_ITEM_TEST_5_INC_94_PASSED",
    "SUB_LIST_BUILD_ITEM_TEST_6_GETTERS_SETTERS_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_build_item_test(tmp_path_factory):
    """Compile sub_list_build_item source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_build_item regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-build-item")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-build-item-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_build_item.cpp",
            "tests/native/sub_list_build_item_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_build_item_behavior(sub_list_build_item_test, case):
    """Verify sub_list_build_item functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_build_item_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_build_item_missing_selector(sub_list_build_item_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_build_item_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_build_item_invalid_selector(sub_list_build_item_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_build_item_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_build_item_nonnumeric_selector(sub_list_build_item_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_build_item_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
