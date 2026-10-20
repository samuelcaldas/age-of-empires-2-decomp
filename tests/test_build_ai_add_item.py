"""Native regressions for build_ai_add_item (`0x13DB20`–`0x13DD80`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "build_ai_add_item func_0013DB20 null alloc",
    "build_ai_add_item func_0013DB20 type 6",
    "build_ai_add_item func_0013DB20 unit type valid",
    "build_ai_add_item func_0013DB20 unit type null",
]

MARKERS = [
    "BUILD_AI_ADD_ITEM_TEST_0_NULL_ALLOC_PASSED",
    "BUILD_AI_ADD_ITEM_TEST_1_TYPE6_PASSED",
    "BUILD_AI_ADD_ITEM_TEST_2_UNIT_TYPE_VALID_PASSED",
    "BUILD_AI_ADD_ITEM_TEST_3_UNIT_TYPE_NULL_PASSED",
]


@pytest.fixture(scope="module")
def build_ai_add_item_test(tmp_path_factory):
    """Compile build_ai_add_item source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_ai_add_item regressions require g++")
    fixture = tmp_path_factory.mktemp("build-ai-add-item")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-ai-add-item-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/build_ai_add_item.cpp",
            "tests/native/build_ai_add_item_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_ai_add_item_behavior(build_ai_add_item_test, case):
    """Verify build_ai_add_item functionality and unique test case markers."""
    result = subprocess.run([str(build_ai_add_item_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_build_ai_add_item_missing_selector(build_ai_add_item_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_add_item_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_build_ai_add_item_invalid_selector(build_ai_add_item_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_add_item_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_build_ai_add_item_nonnumeric_selector(build_ai_add_item_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_add_item_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
