"""Native regressions for diplomacy_ai_save (`0x13F910`–`0x13FA90`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "diplomacy_ai_save func_0013F910 skips self player id",
    "diplomacy_ai_save func_0013F910 branch 140280 true 1402e0 false",
    "diplomacy_ai_save func_0013F910 branch 140280 false 1402e0 true",
    "diplomacy_ai_save func_0013F910 both true or both false no call",
    "diplomacy_ai_save func_0013F910 num players 1 no loop",
    "diplomacy_ai_save Save stream writes",
]

MARKERS = [
    "DIPLOMACY_AI_SAVE_TEST_0_F910_SKIPS_SELF_PLAYER_ID_PASSED",
    "DIPLOMACY_AI_SAVE_TEST_1_F910_BRANCH1_PASSED",
    "DIPLOMACY_AI_SAVE_TEST_2_F910_BRANCH2_PASSED",
    "DIPLOMACY_AI_SAVE_TEST_3_F910_BOTH_TRUE_OR_FALSE_NO_CALL_PASSED",
    "DIPLOMACY_AI_SAVE_TEST_4_F910_NUM_PLAYERS_1_NO_LOOP_PASSED",
    "DIPLOMACY_AI_SAVE_TEST_5_SAVE_STREAM_WRITES_PASSED",
]


@pytest.fixture(scope="module")
def diplomacy_ai_save_test(tmp_path_factory):
    """Compile diplomacy_ai_save source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("diplomacy_ai_save regressions require g++")
    fixture = tmp_path_factory.mktemp("diplomacy-ai-save")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "diplomacy-ai-save-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/diplomacy_ai_save.cpp",
            "tests/native/diplomacy_ai_save_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_diplomacy_ai_save_behavior(diplomacy_ai_save_test, case):
    """Verify diplomacy_ai_save functionality and unique test case markers."""
    result = subprocess.run([str(diplomacy_ai_save_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_diplomacy_ai_save_missing_selector(diplomacy_ai_save_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_save_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_diplomacy_ai_save_invalid_selector(diplomacy_ai_save_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_save_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_diplomacy_ai_save_nonnumeric_selector(diplomacy_ai_save_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_save_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
