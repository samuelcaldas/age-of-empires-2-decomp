"""Native regressions for sub_list_float_accessors (`0x13C430`–`0x13C470`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_float_accessors func_0013C430 field20",
    "sub_list_float_accessors func_0013C440 field24",
    "sub_list_float_accessors func_0013C450 field28",
    "sub_list_float_accessors func_0013C460 field3C setter",
]

MARKERS = [
    "SUB_LIST_FLOAT_ACCESSORS_TEST_0_C430_PASSED",
    "SUB_LIST_FLOAT_ACCESSORS_TEST_1_C440_PASSED",
    "SUB_LIST_FLOAT_ACCESSORS_TEST_2_C450_PASSED",
    "SUB_LIST_FLOAT_ACCESSORS_TEST_3_C460_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_float_accessors_test(tmp_path_factory):
    """Compile sub_list_float_accessors source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_float_accessors regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-float-accessors")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-float-accessors-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_float_accessors.cpp",
            "tests/native/sub_list_float_accessors_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_float_accessors_behavior(sub_list_float_accessors_test, case):
    """Verify sub_list_float_accessors functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_float_accessors_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_float_accessors_missing_selector(sub_list_float_accessors_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_float_accessors_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_float_accessors_invalid_selector(sub_list_float_accessors_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_float_accessors_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_float_accessors_nonnumeric_selector(sub_list_float_accessors_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_float_accessors_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
