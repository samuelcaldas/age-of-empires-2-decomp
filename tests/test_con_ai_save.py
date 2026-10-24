"""Native regressions for con_ai_save (`0x13E990`–`0x13EE20`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_save Save empty lists",
    "con_ai_save Save list1 item",
    "con_ai_save Save list2 item",
    "con_ai_save Save both lists items",
]

MARKERS = [
    "CON_AI_SAVE_TEST_0_EMPTY_PASSED",
    "CON_AI_SAVE_TEST_1_LIST1_ITEM_PASSED",
    "CON_AI_SAVE_TEST_2_LIST2_ITEM_PASSED",
    "CON_AI_SAVE_TEST_3_BOTH_LISTS_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_save_test(tmp_path_factory):
    """Compile con_ai_save source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_save regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-save")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-save-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/con_ai_save.cpp",
            "tests/native/con_ai_save_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_save_behavior(con_ai_save_test, case):
    """Verify con_ai_save functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_save_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_save_missing_selector(con_ai_save_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_save_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_save_invalid_selector(con_ai_save_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_save_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_save_nonnumeric_selector(con_ai_save_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_save_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
