"""Native regressions for con_ai_init (`0x13E200`–`0x13E370`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "con_ai_init func_0013E200 alloc first slot",
    "con_ai_init func_0013E200 skips and full capacity",
    "con_ai_init func_0013E250 free item",
    "con_ai_init func_0013E260 initialize fields",
]

MARKERS = [
    "CON_AI_INIT_TEST_0_ALLOC_FIRST_PASSED",
    "CON_AI_INIT_TEST_1_ALLOC_FULL_PASSED",
    "CON_AI_INIT_TEST_2_FREE_PASSED",
    "CON_AI_INIT_TEST_3_INIT_FIELDS_PASSED",
]


@pytest.fixture(scope="module")
def con_ai_init_test(tmp_path_factory):
    """Compile con_ai_init source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("con_ai_init regressions require g++")
    fixture = tmp_path_factory.mktemp("con-ai-init")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "con-ai-init-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/con_ai_init.cpp",
            "tests/native/con_ai_init_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_con_ai_init_behavior(con_ai_init_test, case):
    """Verify con_ai_init functionality and unique test case markers."""
    result = subprocess.run([str(con_ai_init_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_con_ai_init_missing_selector(con_ai_init_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_init_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_con_ai_init_invalid_selector(con_ai_init_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_init_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_con_ai_init_nonnumeric_selector(con_ai_init_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(con_ai_init_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
