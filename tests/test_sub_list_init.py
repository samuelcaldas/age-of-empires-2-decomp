"""Native regressions for sub_list_init (`0x13B710`–`0x13B770`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_init func_0013B710 do_setup true",
    "sub_list_init func_0013B710 do_setup false",
    "sub_list_init func_0013B740 do_setup true",
    "sub_list_init func_0013B740 do_setup false",
]

MARKERS = [
    "SUB_LIST_INIT_TEST_0_B710_SETUP1_PASSED",
    "SUB_LIST_INIT_TEST_1_B710_SETUP0_PASSED",
    "SUB_LIST_INIT_TEST_2_B740_SETUP1_PASSED",
    "SUB_LIST_INIT_TEST_3_B740_SETUP0_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_init_test(tmp_path_factory):
    """Compile sub_list_init source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_init regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-init")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-init-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_init.cpp",
            "tests/native/sub_list_init_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_init_behavior(sub_list_init_test, case):
    """Verify sub_list_init functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_init_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_init_missing_selector(sub_list_init_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_init_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_init_invalid_selector(sub_list_init_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_init_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_init_nonnumeric_selector(sub_list_init_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_init_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
