"""Native regressions for sub_list_item_base (`0x13C660`–`0x13C8E0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_item_base func_0013C660 ctor",
    "sub_list_item_base func_0013C6D0 setter",
    "sub_list_item_base func_0013C710 copy",
    "sub_list_item_base func_0013C770 dtor",
    "sub_list_item_base getters",
    "sub_list_item_base setters",
]

MARKERS = [
    "SUB_LIST_ITEM_BASE_TEST_0_CTOR_PASSED",
    "SUB_LIST_ITEM_BASE_TEST_1_SETTER_PASSED",
    "SUB_LIST_ITEM_BASE_TEST_2_COPY_PASSED",
    "SUB_LIST_ITEM_BASE_TEST_3_DTOR_PASSED",
    "SUB_LIST_ITEM_BASE_TEST_4_GETTERS_PASSED",
    "SUB_LIST_ITEM_BASE_TEST_5_SETTERS_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_item_base_test(tmp_path_factory):
    """Compile sub_list_item_base source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_item_base regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-item-base")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-item-base-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_item_base.cpp",
            "tests/native/sub_list_item_base_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_item_base_behavior(sub_list_item_base_test, case):
    """Verify sub_list_item_base functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_item_base_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_item_base_missing_selector(sub_list_item_base_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_item_base_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_item_base_invalid_selector(sub_list_item_base_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_item_base_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_item_base_nonnumeric_selector(sub_list_item_base_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_item_base_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
