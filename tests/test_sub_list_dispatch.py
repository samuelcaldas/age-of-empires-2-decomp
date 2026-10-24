"""Native regressions for sub_list_dispatch (`0x13B0B0`–`0x13B360`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_dispatch func_0013B0B0 null fieldC8 guard",
    "sub_list_dispatch func_0013B0B0 with other dispatch",
    "sub_list_dispatch func_0013B0B0 without other dispatch",
    "sub_list_dispatch func_0013B0B0 default action mapping",
]

MARKERS = [
    "SUB_LIST_DISPATCH_TEST_0_NULL_FIELD_C8_PASSED",
    "SUB_LIST_DISPATCH_TEST_1_WITH_OTHER_PASSED",
    "SUB_LIST_DISPATCH_TEST_2_WITHOUT_OTHER_PASSED",
    "SUB_LIST_DISPATCH_TEST_3_DEFAULT_ACTION_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_dispatch_test(tmp_path_factory):
    """Compile sub_list_dispatch source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_dispatch regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-dispatch")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-dispatch-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_dispatch.cpp",
            "tests/native/sub_list_dispatch_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_dispatch_behavior(sub_list_dispatch_test, case):
    """Verify sub_list_dispatch functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_dispatch_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_dispatch_missing_selector(sub_list_dispatch_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_dispatch_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_dispatch_invalid_selector(sub_list_dispatch_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_dispatch_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_dispatch_nonnumeric_selector(sub_list_dispatch_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_dispatch_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
