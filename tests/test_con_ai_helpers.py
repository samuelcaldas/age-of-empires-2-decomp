"""Native regressions for con_ai_helpers (`0x13F3F0`–`0x13F4B0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_helpers func_0013F3F0 null item",
    "con_ai_helpers func_0013F3F0 found item multiple calls",
    "con_ai_helpers func_0013F3F0 zero count",
    "con_ai_helpers func_0013F450 null item",
    "con_ai_helpers func_0013F450 found item multiple calls",
    "con_ai_helpers func_0013F450 zero count",
]

MARKERS = [
    "CON_AI_HELPERS_TEST_0_F3F0_NULL_PASSED",
    "CON_AI_HELPERS_TEST_1_F3F0_FOUND_PASSED",
    "CON_AI_HELPERS_TEST_2_F3F0_ZERO_COUNT_PASSED",
    "CON_AI_HELPERS_TEST_3_F450_NULL_PASSED",
    "CON_AI_HELPERS_TEST_4_F450_FOUND_PASSED",
    "CON_AI_HELPERS_TEST_5_F450_ZERO_COUNT_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_helpers_test(tmp_path_factory):
    """Compile con_ai_helpers source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_helpers regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-helpers")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-helpers-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/con_ai_helpers.cpp",
            "tests/native/con_ai_helpers_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_helpers_behavior(con_ai_helpers_test, case):
    """Verify con_ai_helpers functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_helpers_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_helpers_missing_selector(con_ai_helpers_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_helpers_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_helpers_invalid_selector(con_ai_helpers_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_helpers_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_helpers_nonnumeric_selector(con_ai_helpers_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_helpers_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
