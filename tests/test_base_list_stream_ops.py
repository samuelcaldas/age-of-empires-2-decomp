"""Native regressions for base_list_stream_ops (`0x139C80`–`0x139EA0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "SubList SetupSpatial",
    "SubList Setup",
    "SubList CreateSubList",
    "SubList Action",
    "SubList Save",
    "SubList Free",
    "SubList Teardown",
    "SubList Noop",
    "SubList Notify",
]

MARKERS = [
    "BASE_LIST_STREAM_OPS_TEST_0_SETUP_SPATIAL_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_1_SETUP_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_2_CREATE_SUBLIST_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_3_ACTION_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_4_SAVE_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_5_FREE_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_6_TEARDOWN_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_7_NOOP_PASSED",
    "BASE_LIST_STREAM_OPS_TEST_8_NOTIFY_PASSED",
]


@pytest.fixture(scope="module")
def base_list_stream_ops_test(tmp_path_factory):
    """Compile base_list_stream_ops source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("base_list_stream_ops regressions require g++")
    fixture = tmp_path_factory.mktemp("base-list-stream-ops")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "base-list-stream-ops-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/base_list_stream_ops.cpp",
            "tests/native/base_list_stream_ops_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_base_list_stream_ops_behavior(base_list_stream_ops_test, case):
    """Verify BaseListStreamOps functionality and unique test case markers."""
    result = subprocess.run([str(base_list_stream_ops_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_base_list_stream_ops_missing_selector(base_list_stream_ops_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_stream_ops_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_base_list_stream_ops_invalid_selector(base_list_stream_ops_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_stream_ops_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_base_list_stream_ops_nonnumeric_selector(base_list_stream_ops_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_stream_ops_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
