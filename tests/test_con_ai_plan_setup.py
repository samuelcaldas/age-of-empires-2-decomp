"""Native regressions for con_ai_plan_setup (`0x13EEF0`–`0x13F190`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_plan_setup func_0013EEF0 invalid bounds",
    "con_ai_plan_setup func_0013EEF0 empty list",
    "con_ai_plan_setup func_0013EEF0 item inside bounds",
    "con_ai_plan_setup func_0013EEF0 item outside bounds unlinked",
    "con_ai_plan_setup func_0013F180 stub return 0",
]

MARKERS = [
    "CON_AI_PLAN_SETUP_TEST_0_INVALID_BOUNDS_PASSED",
    "CON_AI_PLAN_SETUP_TEST_1_EMPTY_LIST_PASSED",
    "CON_AI_PLAN_SETUP_TEST_2_ITEM_INSIDE_PASSED",
    "CON_AI_PLAN_SETUP_TEST_3_ITEM_OUTSIDE_PASSED",
    "CON_AI_PLAN_SETUP_TEST_4_STUB_180_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_plan_setup_test(tmp_path_factory):
    """Compile con_ai_plan_setup source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_plan_setup regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-plan-setup")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-plan-setup-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/con_ai_plan_setup.cpp",
            "tests/native/con_ai_plan_setup_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_plan_setup_behavior(con_ai_plan_setup_test, case):
    """Verify con_ai_plan_setup functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_plan_setup_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_plan_setup_missing_selector(con_ai_plan_setup_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_plan_setup_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_plan_setup_invalid_selector(con_ai_plan_setup_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_plan_setup_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_plan_setup_nonnumeric_selector(con_ai_plan_setup_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_plan_setup_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
