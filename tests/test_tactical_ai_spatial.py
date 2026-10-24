"""Native regressions for tactical_ai_spatial (`0x1422F0`–`0x1424A0`).

Reconciled function extents:
- func_001422F0: [0x1422F0, 0x142378) (0x88 code), padding [0x142378, 0x142380) (8 B NOP)
- func_00142380: [0x142380, 0x1423F4) (0x74 code), padding [0x1423F4, 0x142400) (12 B NOP)
- func_00142400: [0x142400, 0x142498) (0x98 code), padding [0x142498, 0x1424A0) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_spatial func_22f0 fail 11e0",
    "tactical_ai_spatial func_22f0 match",
    "tactical_ai_spatial func_22f0 mismatch",
    "tactical_ai_spatial func_2380 fail 1500",
    "tactical_ai_spatial func_2380 success",
    "tactical_ai_spatial func_2400 fail 1630",
    "tactical_ai_spatial func_2400 success with old",
    "tactical_ai_spatial func_2400 success null old",
    "tactical_ai_spatial layout",
]

MARKERS = [
    "TACTICAL_AI_SPATIAL_TEST_0_22F0_FAIL_11E0_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_1_22F0_MATCH_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_2_22F0_MISMATCH_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_3_2380_FAIL_1500_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_4_2380_SUCCESS_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_5_2400_FAIL_1630_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_6_2400_SUCCESS_WITH_OLD_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_7_2400_SUCCESS_NULL_OLD_PASSED",
    "TACTICAL_AI_SPATIAL_TEST_8_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_spatial_test(tmp_path_factory):
    """Compile tactical_ai_spatial source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_spatial regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-spatial")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-spatial-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_spatial.cpp",
            "tests/native/tactical_ai_spatial_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_spatial_behavior(tactical_ai_spatial_test, case):
    """Verify tactical_ai_spatial functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_spatial_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_spatial_missing_selector(tactical_ai_spatial_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_spatial_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_spatial_invalid_selector(tactical_ai_spatial_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_spatial_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_spatial_nonnumeric_selector(tactical_ai_spatial_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_spatial_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
