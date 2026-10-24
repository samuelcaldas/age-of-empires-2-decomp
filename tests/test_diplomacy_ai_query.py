"""Native regressions for diplomacy_ai_query (`0x13FA90`–`0x13FC80`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "diplomacy_ai_query func_0013FA90 bounds",
    "diplomacy_ai_query func_0013FA90 modes 0, 2, and invalid",
    "diplomacy_ai_query func_0013FA90 mode 1 composite score",
    "diplomacy_ai_query func_13FB50 bounds",
    "diplomacy_ai_query func_13FB50 mode 0 clamping",
    "diplomacy_ai_query func_13FB50 mode 1 noop",
    "diplomacy_ai_query func_13FB50 mode 2 clamping",
]

MARKERS = [
    "DIPLOMACY_AI_QUERY_TEST_0_FA90_BOUNDS_PASSED",
    "DIPLOMACY_AI_QUERY_TEST_1_FA90_MODES_0_2_INVALID_PASSED",
    "DIPLOMACY_AI_QUERY_TEST_2_FA90_MODE_1_SCORE_PASSED",
    "DIPLOMACY_AI_QUERY_TEST_3_FB50_BOUNDS_PASSED",
    "DIPLOMACY_AI_QUERY_TEST_4_FB50_MODE_0_CLAMPING_PASSED",
    "DIPLOMACY_AI_QUERY_TEST_5_FB50_MODE_1_NOOP_PASSED",
    "DIPLOMACY_AI_QUERY_TEST_6_FB50_MODE_2_CLAMPING_PASSED",
]


@pytest.fixture(scope="module")
def diplomacy_ai_query_test(tmp_path_factory):
    """Compile diplomacy_ai_query source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("diplomacy_ai_query regressions require g++")
    fixture = tmp_path_factory.mktemp("diplomacy-ai-query")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "diplomacy-ai-query-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/diplomacy_ai_query.cpp",
            "tests/native/diplomacy_ai_query_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_diplomacy_ai_query_behavior(diplomacy_ai_query_test, case):
    """Verify diplomacy_ai_query functionality and unique test case markers."""
    result = subprocess.run([str(diplomacy_ai_query_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_diplomacy_ai_query_missing_selector(diplomacy_ai_query_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_query_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_diplomacy_ai_query_invalid_selector(diplomacy_ai_query_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_query_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_diplomacy_ai_query_nonnumeric_selector(diplomacy_ai_query_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_query_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
