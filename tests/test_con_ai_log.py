"""Native regressions for con_ai_log (`0x13EE20`–`0x13EEF0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_log func_0013EE20 normal name zero count",
    "con_ai_log func_0013EE20 normal name nonzero count",
    "con_ai_log func_0013EE20 NONE name",
    "con_ai_log func_0013EE20 empty name",
]

MARKERS = [
    "CON_AI_LOG_TEST_0_NORMAL_ZERO_COUNT_PASSED",
    "CON_AI_LOG_TEST_1_NORMAL_NONZERO_COUNT_PASSED",
    "CON_AI_LOG_TEST_2_NONE_NAME_PASSED",
    "CON_AI_LOG_TEST_3_EMPTY_NAME_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_log_test(tmp_path_factory):
    """Compile con_ai_log source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_log regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-log")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-log-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/con_ai_log.cpp",
            "tests/native/con_ai_log_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_log_behavior(con_ai_log_test, case):
    """Verify con_ai_log functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_log_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_log_missing_selector(con_ai_log_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_log_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_log_invalid_selector(con_ai_log_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_log_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_log_nonnumeric_selector(con_ai_log_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_log_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
