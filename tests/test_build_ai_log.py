"""Native regressions for build_ai_log (`0x13D820`–`0x13DAC0`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "build_ai_log Log empty list",
    "build_ai_log Log item fmt1",
    "build_ai_log Log item fmt2",
]

MARKERS = [
    "BUILD_AI_LOG_TEST_0_EMPTY_PASSED",
    "BUILD_AI_LOG_TEST_1_ITEM_FMT1_PASSED",
    "BUILD_AI_LOG_TEST_2_ITEM_FMT2_PASSED",
]


@pytest.fixture(scope="module")
def build_ai_log_test(tmp_path_factory):
    """Compile build_ai_log source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_ai_log regressions require g++")
    fixture = tmp_path_factory.mktemp("build-ai-log")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-ai-log-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/build_ai_log.cpp",
            "tests/native/build_ai_log_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_ai_log_behavior(build_ai_log_test, case):
    """Verify build_ai_log functionality and unique test case markers."""
    result = subprocess.run([str(build_ai_log_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_build_ai_log_missing_selector(build_ai_log_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_log_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_build_ai_log_invalid_selector(build_ai_log_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_log_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_build_ai_log_nonnumeric_selector(build_ai_log_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_log_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
