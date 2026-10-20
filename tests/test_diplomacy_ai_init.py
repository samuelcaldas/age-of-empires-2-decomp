"""Native regressions for diplomacy_ai_init (`0x13F730`–`0x13F910`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "diplomacy_ai_init func_0013F730 base call and state",
    "diplomacy_ai_init func_0013F730 arrays initialization",
    "diplomacy_ai_init func_0013F7C0 base call and state",
    "diplomacy_ai_init func_0013F7C0 stream reads",
    "diplomacy_ai_init func_0013F890 null pointer guard",
    "diplomacy_ai_init func_0013F890 destructor nofree",
    "diplomacy_ai_init func_0013F890 destructor with free",
    "diplomacy_ai_init func_0013F900 set fieldAC",
]

MARKERS = [
    "DIPLOMACY_AI_INIT_TEST_0_F730_BASE_CALL_PASSED",
    "DIPLOMACY_AI_INIT_TEST_1_F730_ARRAYS_INIT_PASSED",
    "DIPLOMACY_AI_INIT_TEST_2_F7C0_BASE_CALL_PASSED",
    "DIPLOMACY_AI_INIT_TEST_3_F7C0_STREAM_READS_PASSED",
    "DIPLOMACY_AI_INIT_TEST_4_F890_NULL_PASSED",
    "DIPLOMACY_AI_INIT_TEST_5_F890_DESTRUCTOR_NOFREE_PASSED",
    "DIPLOMACY_AI_INIT_TEST_6_F890_DESTRUCTOR_FREE_PASSED",
    "DIPLOMACY_AI_INIT_TEST_7_F900_SET_FIELDAC_PASSED",
]


@pytest.fixture(scope="module")
def diplomacy_ai_init_test(tmp_path_factory):
    """Compile diplomacy_ai_init source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("diplomacy_ai_init regressions require g++")
    fixture = tmp_path_factory.mktemp("diplomacy-ai-init")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "diplomacy-ai-init-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/diplomacy_ai_init.cpp",
            "tests/native/diplomacy_ai_init_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_diplomacy_ai_init_behavior(diplomacy_ai_init_test, case):
    """Verify diplomacy_ai_init functionality and unique test case markers."""
    result = subprocess.run([str(diplomacy_ai_init_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_diplomacy_ai_init_missing_selector(diplomacy_ai_init_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_init_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_diplomacy_ai_init_invalid_selector(diplomacy_ai_init_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_init_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_diplomacy_ai_init_nonnumeric_selector(diplomacy_ai_init_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_init_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
