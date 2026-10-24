"""Native regressions for emotional_ai_save (`0x140600`–`0x1407B0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "emotional_ai_save Save stream writes",
    "emotional_ai_save SetPersonality 0 Aggressive",
    "emotional_ai_save SetPersonality 1 Compassionate",
    "emotional_ai_save SetPersonality 2 Defensive",
    "emotional_ai_save SetPersonality 3 Friendly",
    "emotional_ai_save SetPersonality 4 Passive",
    "emotional_ai_save SetPersonality 5 Vengeful",
    "emotional_ai_save SetPersonality out of range",
]

MARKERS = [
    "EMOTIONAL_AI_SAVE_TEST_0_STREAM_WRITES_PASSED",
    "EMOTIONAL_AI_SAVE_TEST_1_PERSONALITY_0_PASSED",
    "EMOTIONAL_AI_SAVE_TEST_2_PERSONALITY_1_PASSED",
    "EMOTIONAL_AI_SAVE_TEST_3_PERSONALITY_2_PASSED",
    "EMOTIONAL_AI_SAVE_TEST_4_PERSONALITY_3_PASSED",
    "EMOTIONAL_AI_SAVE_TEST_5_PERSONALITY_4_PASSED",
    "EMOTIONAL_AI_SAVE_TEST_6_PERSONALITY_5_PASSED",
    "EMOTIONAL_AI_SAVE_TEST_7_PERSONALITY_OUT_OF_RANGE_PASSED",
]


@pytest.fixture(scope="module")
def emotional_ai_save_test(tmp_path_factory):
    """Compile emotional_ai_save source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("emotional_ai_save regressions require g++")
    fixture = tmp_path_factory.mktemp("emotional-ai-save")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "emotional-ai-save-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/emotional_ai_save.cpp",
            "tests/native/emotional_ai_save_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_emotional_ai_save_behavior(emotional_ai_save_test, case):
    """Verify emotional_ai_save functionality and unique test case markers."""
    result = subprocess.run([str(emotional_ai_save_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_emotional_ai_save_missing_selector(emotional_ai_save_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(emotional_ai_save_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_emotional_ai_save_invalid_selector(emotional_ai_save_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(emotional_ai_save_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_emotional_ai_save_nonnumeric_selector(emotional_ai_save_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(emotional_ai_save_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
