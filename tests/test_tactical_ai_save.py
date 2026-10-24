"""Native regressions for tactical_ai_save (`0x140EF0`–`0x141250`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_save stream writes",
    "tactical_ai_save func_10e0 success",
    "tactical_ai_save func_10e0 capacity full",
    "tactical_ai_save func_1170 success",
    "tactical_ai_save func_1170 capacity full",
    "tactical_ai_save func_11e0 success",
    "tactical_ai_save func_11e0 capacity full",
    "tactical_ai_save layout",
]

MARKERS = [
    "TACTICAL_AI_SAVE_TEST_0_STREAM_WRITES_PASSED",
    "TACTICAL_AI_SAVE_TEST_1_FUNC_10E0_SUCCESS_PASSED",
    "TACTICAL_AI_SAVE_TEST_2_FUNC_10E0_CAPACITY_FULL_PASSED",
    "TACTICAL_AI_SAVE_TEST_3_FUNC_1170_SUCCESS_PASSED",
    "TACTICAL_AI_SAVE_TEST_4_FUNC_1170_CAPACITY_FULL_PASSED",
    "TACTICAL_AI_SAVE_TEST_5_FUNC_11E0_SUCCESS_PASSED",
    "TACTICAL_AI_SAVE_TEST_6_FUNC_11E0_CAPACITY_FULL_PASSED",
    "TACTICAL_AI_SAVE_TEST_7_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_save_test(tmp_path_factory):
    """Compile tactical_ai_save source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_save regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-save")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-save-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_save.cpp",
            "tests/native/tactical_ai_save_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_save_behavior(tactical_ai_save_test, case):
    """Verify tactical_ai_save functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_save_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_save_missing_selector(tactical_ai_save_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_save_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_save_invalid_selector(tactical_ai_save_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_save_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_save_nonnumeric_selector(tactical_ai_save_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_save_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
