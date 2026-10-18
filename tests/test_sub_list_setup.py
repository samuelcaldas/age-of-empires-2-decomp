"""Native regressions for sub_list_setup (`0x13B8A0`–`0x13BAD0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_setup func_0013BA60 default setup",
    "sub_list_setup func_0013B8A0 id minus1",
    "sub_list_setup func_0013B8A0 id master",
    "sub_list_setup func_0013B8A0 version check",
]

MARKERS = [
    "SUB_LIST_SETUP_TEST_0_BA60_PASSED",
    "SUB_LIST_SETUP_TEST_1_B8A0_ID_MINUS1_PASSED",
    "SUB_LIST_SETUP_TEST_2_B8A0_ID_MASTER_PASSED",
    "SUB_LIST_SETUP_TEST_3_B8A0_VERSION_CHECK_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_setup_test(tmp_path_factory):
    """Compile sub_list_setup source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_setup regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-setup")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-setup-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_setup.cpp",
            "tests/native/sub_list_setup_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_setup_behavior(sub_list_setup_test, case):
    """Verify sub_list_setup functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_setup_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_setup_missing_selector(sub_list_setup_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_setup_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_setup_invalid_selector(sub_list_setup_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_setup_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_setup_nonnumeric_selector(sub_list_setup_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_setup_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
