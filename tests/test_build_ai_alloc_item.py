"""Native regressions for build_ai_alloc_item (`0x13DAC0`–`0x13DB20`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "build_ai_alloc_item func_0013DAC0 slot 0",
    "build_ai_alloc_item func_0013DAC0 skips occupied",
    "build_ai_alloc_item func_0013DAC0 full capacity",
]

MARKERS = [
    "BUILD_AI_ALLOC_ITEM_TEST_0_SLOT0_PASSED",
    "BUILD_AI_ALLOC_ITEM_TEST_1_SKIPS_PASSED",
    "BUILD_AI_ALLOC_ITEM_TEST_2_FULL_PASSED",
]


@pytest.fixture(scope="module")
def build_ai_alloc_item_test(tmp_path_factory):
    """Compile build_ai_alloc_item source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_ai_alloc_item regressions require g++")
    fixture = tmp_path_factory.mktemp("build-ai-alloc-item")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-ai-alloc-item-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/build_ai_alloc_item.cpp",
            "tests/native/build_ai_alloc_item_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_ai_alloc_item_behavior(build_ai_alloc_item_test, case):
    """Verify build_ai_alloc_item functionality and unique test case markers."""
    result = subprocess.run([str(build_ai_alloc_item_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_build_ai_alloc_item_missing_selector(build_ai_alloc_item_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_alloc_item_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_build_ai_alloc_item_invalid_selector(build_ai_alloc_item_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_alloc_item_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_build_ai_alloc_item_nonnumeric_selector(build_ai_alloc_item_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_alloc_item_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
