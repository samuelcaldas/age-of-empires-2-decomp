"""Native regressions for con_ai_load (`0x13E370`–`0x13E990`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_load func_0013E370 empty load",
    "con_ai_load func_0013E370 items load",
    "con_ai_load func_0013E8D0 null dtor",
    "con_ai_load func_0013E8D0 dtor no cleanup",
    "con_ai_load func_0013E8D0 dtor full cleanup",
]

MARKERS = [
    "CON_AI_LOAD_TEST_0_EMPTY_LOAD_PASSED",
    "CON_AI_LOAD_TEST_1_ITEMS_LOAD_PASSED",
    "CON_AI_LOAD_TEST_2_DTOR_NULL_PASSED",
    "CON_AI_LOAD_TEST_3_DTOR_NO_CLEANUP_PASSED",
    "CON_AI_LOAD_TEST_4_DTOR_FULL_CLEANUP_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_load_test(tmp_path_factory):
    """Compile con_ai_load source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_load regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-load")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-load-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/con_ai_load.cpp",
            "tests/native/con_ai_load_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_load_behavior(con_ai_load_test, case):
    """Verify con_ai_load functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_load_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_load_missing_selector(con_ai_load_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_load_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_load_invalid_selector(con_ai_load_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_load_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_load_nonnumeric_selector(con_ai_load_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_load_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
