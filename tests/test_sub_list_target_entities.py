"""Native regressions for sub_list_target_entities (`0x13C470`–`0x13C4F0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "sub_list_target_entities func_0013C470 field18 lt 0",
    "sub_list_target_entities func_0013C470 field18 ge 0",
    "sub_list_target_entities func_0013C4B0 field1C lt 0",
    "sub_list_target_entities func_0013C4B0 field1C ge 0",
]

MARKERS = [
    "SUB_LIST_TARGET_ENTITIES_TEST_0_C470_LT0_PASSED",
    "SUB_LIST_TARGET_ENTITIES_TEST_1_C470_GE0_PASSED",
    "SUB_LIST_TARGET_ENTITIES_TEST_2_C4B0_LT0_PASSED",
    "SUB_LIST_TARGET_ENTITIES_TEST_3_C4B0_GE0_PASSED",
]


@pytest.fixture(scope="module")
def sub_list_target_entities_test(tmp_path_factory):
    """Compile sub_list_target_entities source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("sub_list_target_entities regressions require g++")
    fixture = tmp_path_factory.mktemp("sub-list-target-entities")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "sub-list-target-entities-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/sub_list_target_entities.cpp",
            "tests/native/sub_list_target_entities_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_sub_list_target_entities_behavior(sub_list_target_entities_test, case):
    """Verify sub_list_target_entities functionality and unique test case markers."""
    result = subprocess.run([str(sub_list_target_entities_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_sub_list_target_entities_missing_selector(sub_list_target_entities_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_target_entities_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_sub_list_target_entities_invalid_selector(sub_list_target_entities_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_target_entities_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_sub_list_target_entities_nonnumeric_selector(sub_list_target_entities_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(sub_list_target_entities_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
