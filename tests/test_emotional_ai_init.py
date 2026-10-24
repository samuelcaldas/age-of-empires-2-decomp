"""Native regressions for emotional_ai_init (`0x140370`–`0x140600`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "emotional_ai_init func_00140370 base call",
    "emotional_ai_init func_00140370 arrays and strings",
    "emotional_ai_init func_00140470 base call",
    "emotional_ai_init func_00140470 stream reads and strings",
    "emotional_ai_init func_00140580 null",
    "emotional_ai_init func_00140580 destructor nofree",
    "emotional_ai_init func_00140580 destructor free",
    "emotional_ai_init func_00140580 destructor negative flag",
    "emotional_ai_init func_001405F0 set fieldac",
]

MARKERS = [
    "EMOTIONAL_AI_INIT_TEST_0_0370_BASE_CALL_PASSED",
    "EMOTIONAL_AI_INIT_TEST_1_0370_ARRAYS_AND_STRINGS_PASSED",
    "EMOTIONAL_AI_INIT_TEST_2_0470_BASE_CALL_PASSED",
    "EMOTIONAL_AI_INIT_TEST_3_0470_STREAM_READS_AND_STRINGS_PASSED",
    "EMOTIONAL_AI_INIT_TEST_4_0580_NULL_PASSED",
    "EMOTIONAL_AI_INIT_TEST_5_0580_DESTRUCTOR_NOFREE_PASSED",
    "EMOTIONAL_AI_INIT_TEST_6_0580_DESTRUCTOR_FREE_PASSED",
    "EMOTIONAL_AI_INIT_TEST_7_0580_DESTRUCTOR_NEGATIVE_FLAG_PASSED",
    "EMOTIONAL_AI_INIT_TEST_8_05F0_SET_FIELDAC_PASSED",
]


@pytest.fixture(scope="module")
def emotional_ai_init_test(tmp_path_factory):
    """Compile emotional_ai_init source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("emotional_ai_init regressions require g++")
    fixture = tmp_path_factory.mktemp("emotional-ai-init")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "emotional-ai-init-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/emotional_ai_init.cpp",
            "tests/native/emotional_ai_init_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_emotional_ai_init_behavior(emotional_ai_init_test, case):
    """Verify emotional_ai_init functionality and unique test case markers."""
    result = subprocess.run([str(emotional_ai_init_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_emotional_ai_init_missing_selector(emotional_ai_init_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(emotional_ai_init_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_emotional_ai_init_invalid_selector(emotional_ai_init_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(emotional_ai_init_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_emotional_ai_init_nonnumeric_selector(emotional_ai_init_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(emotional_ai_init_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
