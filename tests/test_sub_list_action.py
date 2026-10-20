"""Native regressions for sub_list_action (`0x13A280`–`0x13A700`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_action func_0013A280 self guard",
    "sub_list_action func_0013A280 head field30 match",
    "sub_list_action func_0013A280 has items type9 match",
    "sub_list_action func_0013A280 create item dispatch",
    "sub_list_action func_0013A280 fieldA4 positive dispatch",
    "sub_list_action func_0013A280 loop fallback v24",
    "sub_list_action func_0013A6A0 method16 dispatch",
    "sub_list_action func_0013A6C0 noop",
    "sub_list_action func_0013A6D0 method17 dispatch",
    "sub_list_action func_0013A6F0 noop",
]

MARKERS = [
    "SUB_LIST_ACTION_TEST_0_SELF_GUARD_PASSED",
    "SUB_LIST_ACTION_TEST_1_HEAD_FIELD30_PASSED",
    "SUB_LIST_ACTION_TEST_2_HAS_ITEMS_TYPE9_PASSED",
    "SUB_LIST_ACTION_TEST_3_CREATE_ITEM_PASSED",
    "SUB_LIST_ACTION_TEST_4_FIELD_A4_GT0_PASSED",
    "SUB_LIST_ACTION_TEST_5_LOOP_V24_PASSED",
    "SUB_LIST_ACTION_TEST_6_A6A0_PASSED",
    "SUB_LIST_ACTION_TEST_7_A6C0_PASSED",
    "SUB_LIST_ACTION_TEST_8_A6D0_PASSED",
    "SUB_LIST_ACTION_TEST_9_A6F0_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_action_test(tmp_path_factory):
    """Compile sub_list_action source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_action regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-action")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-action-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_action.cpp",
            "tests/native/sub_list_action_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_action_behavior(sub_list_action_test, case):
    """Verify sub_list_action functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_action_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_action_missing_selector(sub_list_action_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_action_invalid_selector(sub_list_action_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_action_nonnumeric_selector(sub_list_action_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
