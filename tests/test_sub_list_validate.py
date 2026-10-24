"""Native regressions for sub_list_validate (`0x13BD90`–`0x13BE90`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_validate func_0013BD90 ge 7",
    "sub_list_validate func_0013BD90 lt 7",
    "sub_list_validate func_0013BE10 ge 7",
    "sub_list_validate func_0013BE10 null targets",
]

MARKERS = [
    "SUB_LIST_VALIDATE_TEST_0_BD90_GE7_PASSED",
    "SUB_LIST_VALIDATE_TEST_1_BD90_LT7_PASSED",
    "SUB_LIST_VALIDATE_TEST_2_BE10_GE7_PASSED",
    "SUB_LIST_VALIDATE_TEST_3_BE10_NULL_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_validate_test(tmp_path_factory):
    """Compile sub_list_validate source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_validate regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-validate")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-validate-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_validate.cpp",
            "tests/native/sub_list_validate_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_validate_behavior(sub_list_validate_test, case):
    """Verify sub_list_validate functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_validate_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_validate_missing_selector(sub_list_validate_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_validate_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_validate_invalid_selector(sub_list_validate_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_validate_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_validate_nonnumeric_selector(sub_list_validate_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_validate_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
