"""Native regressions for base_list_update (`0x1392c0`–`0x139430`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "BaseListUpdate empty list update",
    "BaseListUpdate items update traversal",
    "BaseListUpdate items update2 traversal",
]

MARKERS = [
    "BASE_LIST_UPDATE_TEST_0_EMPTY_PASSED",
    "BASE_LIST_UPDATE_TEST_1_ITEMS_PASSED",
    "BASE_LIST_UPDATE_TEST_2_UPDATE2_PASSED",
]


@pytest.fixture(scope="module")
def base_list_update_test(tmp_path_factory):
    """Compile base_list_update source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("base_list_update regressions require g++")
    fixture = tmp_path_factory.mktemp("base-list-update")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "base-list-update-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/core/base_list.cpp",
            "src/core/base_list_node_mgr.cpp",
            "src/core/base_list_ops.cpp",
            "src/core/base_list_update.cpp",
            "tests/native/base_list_update_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_base_list_update_behavior(base_list_update_test, case):
    """Verify BaseListUpdate functionality and unique test case markers."""
    result = subprocess.run([str(base_list_update_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_base_list_update_missing_selector(base_list_update_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_update_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_base_list_update_invalid_selector(base_list_update_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_update_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_base_list_update_nonnumeric_selector(base_list_update_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_update_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
