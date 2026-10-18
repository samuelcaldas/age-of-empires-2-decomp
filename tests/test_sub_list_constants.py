"""Native regressions for sub_list_constants (`0x13B470`–`0x13B710`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_constants zeroes",
    "sub_list_constants ones",
    "sub_list_constants minus ones",
    "sub_list_constants noops",
    "sub_list_constants sequence b550 to b600",
    "sub_list_constants sequence b610 to b6f0",
]

MARKERS = [
    "SUB_LIST_CONSTANTS_TEST_0_ZEROES_PASSED",
    "SUB_LIST_CONSTANTS_TEST_1_ONES_PASSED",
    "SUB_LIST_CONSTANTS_TEST_2_MINUS_ONES_PASSED",
    "SUB_LIST_CONSTANTS_TEST_3_NOOPS_PASSED",
    "SUB_LIST_CONSTANTS_TEST_4_SEQUENCE_B550_B600_PASSED",
    "SUB_LIST_CONSTANTS_TEST_5_SEQUENCE_B610_B6F0_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_constants_test(tmp_path_factory):
    """Compile sub_list_constants source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_constants regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-constants")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-constants-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_constants.cpp",
            "tests/native/sub_list_constants_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_constants_behavior(sub_list_constants_test, case):
    """Verify sub_list_constants functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_constants_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_constants_missing_selector(sub_list_constants_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_constants_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_constants_invalid_selector(sub_list_constants_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_constants_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_constants_nonnumeric_selector(sub_list_constants_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_constants_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
