"""Native regressions for sub_list_events (`0x13AA80`–`0x13AE00`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_events func_0013AA80 m_field39 >= 3 free head",
    "sub_list_events func_0013AA80 m_field39 == 2 no head v193",
    "sub_list_events func_0013AA80 field1c update",
    "sub_list_events func_0013AA80 update2 delete head",
    "sub_list_events func_0013AB90 action extended",
    "sub_list_events func_0013ABF0 broadcast",
    "sub_list_events func_0013AC40 has items",
    "sub_list_events func_0013AC70 head item field4",
    "sub_list_events func_0013ACA0 field64 branch",
    "sub_list_events func_0013ACA0 head flags branch",
    "sub_list_events func_0013ADC0 target v21",
]

MARKERS = [
    "SUB_LIST_EVENTS_TEST_0_AA80_FIELD39_GE3_PASSED",
    "SUB_LIST_EVENTS_TEST_1_AA80_FIELD39_EQ2_NO_HEAD_PASSED",
    "SUB_LIST_EVENTS_TEST_2_AA80_FIELD1C_UPDATE_PASSED",
    "SUB_LIST_EVENTS_TEST_3_AA80_UPDATE2_DELETE_HEAD_PASSED",
    "SUB_LIST_EVENTS_TEST_4_AB90_ACTION_EXTENDED_PASSED",
    "SUB_LIST_EVENTS_TEST_5_ABF0_BROADCAST_PASSED",
    "SUB_LIST_EVENTS_TEST_6_AC40_HAS_ITEMS_PASSED",
    "SUB_LIST_EVENTS_TEST_7_AC70_HEAD_ITEM_PASSED",
    "SUB_LIST_EVENTS_TEST_8_ACA0_FIELD64_PASSED",
    "SUB_LIST_EVENTS_TEST_9_ACA0_HEAD_FLAGS_PASSED",
    "SUB_LIST_EVENTS_TEST_10_ADC0_TARGET_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_events_test(tmp_path_factory):
    """Compile sub_list_events source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_events regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-events")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-events-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_events.cpp",
            "tests/native/sub_list_events_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_events_behavior(sub_list_events_test, case):
    """Verify sub_list_events functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_events_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_events_missing_selector(sub_list_events_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_events_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_events_invalid_selector(sub_list_events_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_events_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_events_nonnumeric_selector(sub_list_events_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_events_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
