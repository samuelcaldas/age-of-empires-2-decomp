"""Native regressions for item_creator."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "ItemCreator create item type 9",
    "ItemCreator create item type 2 (null)",
    "ItemCreator create item unknown type",
]

MARKERS = [
    "ITEM_CREATOR_TEST_0_TYPE9_PASSED",
    "ITEM_CREATOR_TEST_1_TYPE2_PASSED",
    "ITEM_CREATOR_TEST_2_UNKNOWN_PASSED",
]


@pytest.fixture(scope="module")
def item_creator_test(tmp_path_factory):
    """Compile item_creator source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("item_creator regressions require g++")
    fixture = tmp_path_factory.mktemp("item-creator")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "item-creator-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/base_list.cpp",
            "src/item_creator.cpp",
            "tests/native/item_creator_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_item_creator_behavior(item_creator_test, case):
    """Verify ItemCreator functionality and unique test case markers."""
    result = subprocess.run([str(item_creator_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_item_creator_missing_selector(item_creator_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(item_creator_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_item_creator_invalid_selector(item_creator_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(item_creator_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_item_creator_nonnumeric_selector(item_creator_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(item_creator_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
