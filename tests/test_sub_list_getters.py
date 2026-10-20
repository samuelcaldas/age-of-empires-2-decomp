"""Native regressions for sub_list_getters (`0x13B360`–`0x13B470`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_getters func_0013B360 field90",
    "sub_list_getters func_0013B380 field7C",
    "sub_list_getters func_0013B390 field8C_short",
    "sub_list_getters func_0013B3A0 fieldB4",
    "sub_list_getters func_0013B3B0 fieldC0",
    "sub_list_getters func_0013B3C0 field9C",
    "sub_list_getters func_0013B3E0 field68",
    "sub_list_getters func_0013B3F0 zero",
    "sub_list_getters func_0013B400 zero",
    "sub_list_getters func_0013B410 zero",
    "sub_list_getters func_0013B420 world coordinates",
]

MARKERS = [
    "SUB_LIST_GETTERS_TEST_0_B360_PASSED",
    "SUB_LIST_GETTERS_TEST_1_B380_PASSED",
    "SUB_LIST_GETTERS_TEST_2_B390_PASSED",
    "SUB_LIST_GETTERS_TEST_3_B3A0_PASSED",
    "SUB_LIST_GETTERS_TEST_4_B3B0_PASSED",
    "SUB_LIST_GETTERS_TEST_5_B3C0_PASSED",
    "SUB_LIST_GETTERS_TEST_6_B3E0_PASSED",
    "SUB_LIST_GETTERS_TEST_7_B3F0_PASSED",
    "SUB_LIST_GETTERS_TEST_8_B400_PASSED",
    "SUB_LIST_GETTERS_TEST_9_B410_PASSED",
    "SUB_LIST_GETTERS_TEST_10_B420_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_getters_test(tmp_path_factory):
    """Compile sub_list_getters source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_getters regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-getters")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-getters-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_getters.cpp",
            "tests/native/sub_list_getters_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_getters_behavior(sub_list_getters_test, case):
    """Verify sub_list_getters functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_getters_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_getters_missing_selector(sub_list_getters_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_getters_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_getters_invalid_selector(sub_list_getters_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_getters_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_getters_nonnumeric_selector(sub_list_getters_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_getters_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
