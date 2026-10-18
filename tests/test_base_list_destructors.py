"""Native regressions for base_list_destructors (`0x139BB0`–`0x139C80`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "BaseListDestructors func_00139BB0",
    "BaseListDestructors func_00139C10",
]

MARKERS = [
    "BASE_LIST_DESTRUCTORS_TEST_0_BB0_PASSED",
    "BASE_LIST_DESTRUCTORS_TEST_1_C10_PASSED",
]


@pytest.fixture(scope="module")
def base_list_destructors_test(tmp_path_factory):
    """Compile base_list_destructors source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("base_list_destructors regressions require g++")
    fixture = tmp_path_factory.mktemp("base-list-destructors")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "base-list-destructors-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/base_list_destructors.cpp",
            "tests/native/base_list_destructors_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_base_list_destructors_behavior(base_list_destructors_test, case):
    """Verify BaseListDestructors functionality and unique test case markers."""
    result = subprocess.run([str(base_list_destructors_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_base_list_destructors_missing_selector(base_list_destructors_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_destructors_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_base_list_destructors_invalid_selector(base_list_destructors_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_destructors_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_base_list_destructors_nonnumeric_selector(base_list_destructors_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(base_list_destructors_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
