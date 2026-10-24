"""Native regressions for sub_list_queries (`0x139EA0`–`0x13A280`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_queries func_00139EA0 self guard",
    "sub_list_queries func_00139EA0 direct s0 match",
    "sub_list_queries func_00139EA0 loop fallback match",
    "sub_list_queries func_00139EA0 type 104 scale le 1",
    "sub_list_queries func_00139EA0 type 104 scale gt 1",
    "sub_list_queries func_0013A090 zero float return",
    "sub_list_queries func_0013A0A0 self guard",
    "sub_list_queries func_0013A0A0 method14 early return",
    "sub_list_queries func_0013A0A0 dispatch with other",
    "sub_list_queries func_0013A0A0 dispatch without other",
    "sub_list_queries func_0013A230 notify self vs other",
]

MARKERS = [
    "SUB_LIST_QUERIES_TEST_0_EA0_SELF_PASSED",
    "SUB_LIST_QUERIES_TEST_1_EA0_DIRECT_S0_PASSED",
    "SUB_LIST_QUERIES_TEST_2_EA0_LOOP_FALLBACK_PASSED",
    "SUB_LIST_QUERIES_TEST_3_EA0_TYPE_104_LE1_PASSED",
    "SUB_LIST_QUERIES_TEST_4_EA0_TYPE_104_GT1_PASSED",
    "SUB_LIST_QUERIES_TEST_5_A090_PASSED",
    "SUB_LIST_QUERIES_TEST_6_A0A0_SELF_PASSED",
    "SUB_LIST_QUERIES_TEST_7_A0A0_METHOD14_PASSED",
    "SUB_LIST_QUERIES_TEST_8_A0A0_WITH_OTHER_PASSED",
    "SUB_LIST_QUERIES_TEST_9_A0A0_WITHOUT_OTHER_PASSED",
    "SUB_LIST_QUERIES_TEST_10_A230_NOTIFY_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_queries_test(tmp_path_factory):
    """Compile sub_list_queries source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_queries regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-queries")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-queries-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/sub_list_queries.cpp",
            "tests/native/sub_list_queries_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_queries_behavior(sub_list_queries_test, case):
    """Verify sub_list_queries functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_queries_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_queries_missing_selector(sub_list_queries_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_queries_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_queries_invalid_selector(sub_list_queries_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_queries_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_queries_nonnumeric_selector(sub_list_queries_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_queries_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
