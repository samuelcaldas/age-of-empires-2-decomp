"""Native regressions for sub_list_action_name (`0x13C260`–`0x13C430`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_action_name func_0013C260 None",
    "sub_list_action_name func_0013C260 Done",
    "sub_list_action_name func_0013C260 Work",
    "sub_list_action_name func_0013C260 Attack",
    "sub_list_action_name func_0013C260 MoveNoSearch",
    "sub_list_action_name func_0013C260 Unknown",
]

MARKERS = [
    "SUB_LIST_ACTION_NAME_TEST_0_NONE_PASSED",
    "SUB_LIST_ACTION_NAME_TEST_1_DONE_PASSED",
    "SUB_LIST_ACTION_NAME_TEST_2_WORK_PASSED",
    "SUB_LIST_ACTION_NAME_TEST_3_ATTACK_PASSED",
    "SUB_LIST_ACTION_NAME_TEST_4_MOVE_NO_SEARCH_PASSED",
    "SUB_LIST_ACTION_NAME_TEST_5_UNKNOWN_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_action_name_test(tmp_path_factory):
    """Compile sub_list_action_name source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_action_name regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-action-name")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-action-name-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_action_name.cpp",
            "tests/native/sub_list_action_name_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_action_name_behavior(sub_list_action_name_test, case):
    """Verify sub_list_action_name functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_action_name_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_action_name_missing_selector(sub_list_action_name_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_name_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_action_name_invalid_selector(sub_list_action_name_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_name_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_action_name_nonnumeric_selector(sub_list_action_name_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_name_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
