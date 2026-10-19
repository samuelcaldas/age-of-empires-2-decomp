"""Native regressions for diplomacy_ai_relations (`0x1401C0`–`0x140370`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "diplomacy_ai_relations func_1401C0 stance 3 check",
    "diplomacy_ai_relations func_140220 stance 1 check",
    "diplomacy_ai_relations func_140280 self and stance 0 check",
    "diplomacy_ai_relations func_1402E0 bounds and null",
    "diplomacy_ai_relations func_1402E0 check relation called",
    "diplomacy_ai_relations func_00140360 callable",
]

MARKERS = [
    "DIPLOMACY_AI_RELATIONS_TEST_0_1401C0_STANCE_3_CHECK_PASSED",
    "DIPLOMACY_AI_RELATIONS_TEST_1_140220_STANCE_1_CHECK_PASSED",
    "DIPLOMACY_AI_RELATIONS_TEST_2_140280_SELF_AND_STANCE_0_CHECK_PASSED",
    "DIPLOMACY_AI_RELATIONS_TEST_3_1402E0_BOUNDS_AND_NULL_PASSED",
    "DIPLOMACY_AI_RELATIONS_TEST_4_1402E0_CHECK_RELATION_CALLED_PASSED",
    "DIPLOMACY_AI_RELATIONS_TEST_5_00140360_CALLABLE_PASSED",
]


@pytest.fixture(scope="module")
def diplomacy_ai_relations_test(tmp_path_factory):
    """Compile diplomacy_ai_relations source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("diplomacy_ai_relations regressions require g++")
    fixture = tmp_path_factory.mktemp("diplomacy-ai-relations")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "diplomacy-ai-relations-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/diplomacy_ai_relations.cpp",
            "tests/native/diplomacy_ai_relations_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_diplomacy_ai_relations_behavior(diplomacy_ai_relations_test, case):
    """Verify diplomacy_ai_relations functionality and unique test case markers."""
    result = subprocess.run([str(diplomacy_ai_relations_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_diplomacy_ai_relations_missing_selector(diplomacy_ai_relations_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_relations_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_diplomacy_ai_relations_invalid_selector(diplomacy_ai_relations_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_relations_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_diplomacy_ai_relations_nonnumeric_selector(diplomacy_ai_relations_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(diplomacy_ai_relations_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
