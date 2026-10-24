"""Native regressions for tactical_ai_init (`0x1407B0`–`0x1409A4`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_init vtable and zeroes",
    "tactical_ai_init field8 allocation",
    "tactical_ai_init field10 vector init",
    "tactical_ai_init field18 vector init",
    "tactical_ai_init field20 item16 init",
    "tactical_ai_init field24 item8 init",
    "tactical_ai_init zero counts",
    "tactical_ai_init layout",
]

MARKERS = [
    "TACTICAL_AI_INIT_TEST_0_VTABLE_AND_ZEROES_PASSED",
    "TACTICAL_AI_INIT_TEST_1_FIELD8_ALLOCATION_PASSED",
    "TACTICAL_AI_INIT_TEST_2_FIELD10_VECTOR_INIT_PASSED",
    "TACTICAL_AI_INIT_TEST_3_FIELD18_VECTOR_INIT_PASSED",
    "TACTICAL_AI_INIT_TEST_4_FIELD20_ITEM16_INIT_PASSED",
    "TACTICAL_AI_INIT_TEST_5_FIELD24_ITEM8_INIT_PASSED",
    "TACTICAL_AI_INIT_TEST_6_ZERO_COUNTS_PASSED",
    "TACTICAL_AI_INIT_TEST_7_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_init_test(tmp_path_factory):
    """Compile tactical_ai_init source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_init regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-init")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-init-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_init.cpp",
            "tests/native/tactical_ai_init_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_init_behavior(tactical_ai_init_test, case):
    """Verify tactical_ai_init functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_init_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_init_missing_selector(tactical_ai_init_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_init_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_init_invalid_selector(tactical_ai_init_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_init_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_init_nonnumeric_selector(tactical_ai_init_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_init_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
