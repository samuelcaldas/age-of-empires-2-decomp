"""Native regressions for sub_list_accessors (`0x13BD10`–`0x13BD90`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_accessors func_0013BD10 field4_short",
    "sub_list_accessors func_0013BD20 noop",
    "sub_list_accessors func_0013BD30 to 70 zeroes",
    "sub_list_accessors func_0013BD80 fieldC setter",
]

MARKERS = [
    "SUB_LIST_ACCESSORS_TEST_0_BD10_PASSED",
    "SUB_LIST_ACCESSORS_TEST_1_BD20_PASSED",
    "SUB_LIST_ACCESSORS_TEST_2_ZEROES_PASSED",
    "SUB_LIST_ACCESSORS_TEST_3_BD80_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_accessors_test(tmp_path_factory):
    """Compile sub_list_accessors source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_accessors regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-accessors")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-accessors-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_accessors.cpp",
            "tests/native/sub_list_accessors_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_accessors_behavior(sub_list_accessors_test, case):
    """Verify sub_list_accessors functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_accessors_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_accessors_missing_selector(sub_list_accessors_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_accessors_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_accessors_invalid_selector(sub_list_accessors_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_accessors_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_accessors_nonnumeric_selector(sub_list_accessors_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_accessors_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
