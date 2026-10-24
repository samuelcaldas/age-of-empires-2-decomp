"""Native regressions for sub_list_action_save (`0x13BAD0`–`0x13BD10`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_action_save func_0013BAD0",
    "sub_list_action_save func_0013BAE0 with fields",
    "sub_list_action_save func_0013BAE0 zero fields",
    "sub_list_action_save func_0013BB70 stream save",
]

MARKERS = [
    "SUB_LIST_ACTION_SAVE_TEST_0_BAD0_PASSED",
    "SUB_LIST_ACTION_SAVE_TEST_1_BAE0_WITH_FIELDS_PASSED",
    "SUB_LIST_ACTION_SAVE_TEST_2_BAE0_ZERO_FIELDS_PASSED",
    "SUB_LIST_ACTION_SAVE_TEST_3_BB70_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_action_save_test(tmp_path_factory):
    """Compile sub_list_action_save source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_action_save regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-action-save")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-action-save-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_action_save.cpp",
            "tests/native/sub_list_action_save_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_action_save_behavior(sub_list_action_save_test, case):
    """Verify sub_list_action_save functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_action_save_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_action_save_missing_selector(sub_list_action_save_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_save_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_action_save_invalid_selector(sub_list_action_save_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_save_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_action_save_nonnumeric_selector(sub_list_action_save_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_action_save_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
