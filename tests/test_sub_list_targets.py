"""Native regressions for sub_list_targets (`0x13BE90`–`0x13C0D0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_targets func_0013BE90 action",
    "sub_list_targets func_0013BE90 flags",
    "sub_list_targets func_0013BF50 set new target",
    "sub_list_targets func_0013BF50 clear target",
    "sub_list_targets func_0013C010 set new target",
    "sub_list_targets func_0013C010 clear target",
]

MARKERS = [
    "SUB_LIST_TARGETS_TEST_0_BE90_ACTION_PASSED",
    "SUB_LIST_TARGETS_TEST_1_BE90_FLAGS_PASSED",
    "SUB_LIST_TARGETS_TEST_2_BF50_SET_NEW_PASSED",
    "SUB_LIST_TARGETS_TEST_3_BF50_CLEAR_PASSED",
    "SUB_LIST_TARGETS_TEST_4_C010_SET_NEW_PASSED",
    "SUB_LIST_TARGETS_TEST_5_C010_CLEAR_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_targets_test(tmp_path_factory):
    """Compile sub_list_targets source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_targets regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-targets")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-targets-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_targets.cpp",
            "tests/native/sub_list_targets_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_targets_behavior(sub_list_targets_test, case):
    """Verify sub_list_targets functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_targets_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_targets_missing_selector(sub_list_targets_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_targets_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_targets_invalid_selector(sub_list_targets_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_targets_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_targets_nonnumeric_selector(sub_list_targets_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_targets_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
