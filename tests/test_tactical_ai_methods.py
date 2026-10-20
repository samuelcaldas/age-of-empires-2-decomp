"""Native regressions for tactical_ai_methods (`0x141F60`–`0x142130`).

Reconciled function extents:
- func_00141F60: [0x141F60, 0x14204C) (0xEC code), padding [0x14204C, 0x142050) (4 B NOP)
- func_00142050: [0x142050, 0x142054) (0x4 code), padding [0x142054, 0x142060) (12 B NOP)
- func_00142060: [0x142060, 0x1420BC) (0x5C code), padding [0x1420BC, 0x1420C0) (4 B NOP)
- func_001420C0: [0x1420C0, 0x14212C) (0x6C code), padding [0x14212C, 0x142130) (4 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_methods func_1f60 null",
    "tactical_ai_methods func_1f60 flag zero",
    "tactical_ai_methods func_1f60 flag one",
    "tactical_ai_methods func_1f60 flag negative",
    "tactical_ai_methods func_2050 save",
    "tactical_ai_methods func_2060",
    "tactical_ai_methods func_20c0",
    "tactical_ai_methods layout",
]

MARKERS = [
    "TACTICAL_AI_METHODS_TEST_0_1F60_NULL_PASSED",
    "TACTICAL_AI_METHODS_TEST_1_1F60_FLAG_ZERO_PASSED",
    "TACTICAL_AI_METHODS_TEST_2_1F60_FLAG_ONE_PASSED",
    "TACTICAL_AI_METHODS_TEST_3_1F60_FLAG_NEGATIVE_PASSED",
    "TACTICAL_AI_METHODS_TEST_4_2050_SAVE_PASSED",
    "TACTICAL_AI_METHODS_TEST_5_2060_PASSED",
    "TACTICAL_AI_METHODS_TEST_6_20C0_PASSED",
    "TACTICAL_AI_METHODS_TEST_7_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_methods_test(tmp_path_factory):
    """Compile tactical_ai_methods source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_methods regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-methods")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-methods-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_methods.cpp",
            "tests/native/tactical_ai_methods_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_methods_behavior(tactical_ai_methods_test, case):
    """Verify tactical_ai_methods functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_methods_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_methods_missing_selector(tactical_ai_methods_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_methods_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_methods_invalid_selector(tactical_ai_methods_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_methods_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_methods_nonnumeric_selector(tactical_ai_methods_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_methods_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
