"""Native regressions for tactical_ai_nodes (`0x1418E0`–`0x141A70`).

Reconciled function extents:
- func_001418E0: [0x1418E0, 0x141978) (0x98 code), padding [0x141978, 0x141980) (8 B NOP)
- func_00141980: [0x141980, 0x141A1C) (0x9C code), padding [0x141A1C, 0x141A20) (4 B NOP)
- func_00141A20: [0x141A20, 0x141A60) (0x40 code), padding [0x141A60, 0x141A70) (16 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_nodes func_18e0 success",
    "tactical_ai_nodes func_18e0 null obj30",
    "tactical_ai_nodes func_18e0 negative index",
    "tactical_ai_nodes func_18e0 out of bounds",
    "tactical_ai_nodes func_1980 success",
    "tactical_ai_nodes func_1980 null obj30",
    "tactical_ai_nodes func_1980 out of bounds",
    "tactical_ai_nodes func_1a20 valid",
    "tactical_ai_nodes func_1a20 out of bounds",
    "tactical_ai_nodes layout",
]

MARKERS = [
    "TACTICAL_AI_NODES_TEST_0_18E0_SUCCESS_PASSED",
    "TACTICAL_AI_NODES_TEST_1_18E0_NULL_OBJ30_PASSED",
    "TACTICAL_AI_NODES_TEST_2_18E0_NEGATIVE_INDEX_PASSED",
    "TACTICAL_AI_NODES_TEST_3_18E0_OUT_OF_BOUNDS_PASSED",
    "TACTICAL_AI_NODES_TEST_4_1980_SUCCESS_PASSED",
    "TACTICAL_AI_NODES_TEST_5_1980_NULL_OBJ30_PASSED",
    "TACTICAL_AI_NODES_TEST_6_1980_OUT_OF_BOUNDS_PASSED",
    "TACTICAL_AI_NODES_TEST_7_1A20_VALID_PASSED",
    "TACTICAL_AI_NODES_TEST_8_1A20_OUT_OF_BOUNDS_PASSED",
    "TACTICAL_AI_NODES_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_nodes_test(tmp_path_factory):
    """Compile tactical_ai_nodes source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_nodes regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-nodes")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-nodes-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_nodes.cpp",
            "tests/native/tactical_ai_nodes_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_nodes_behavior(tactical_ai_nodes_test, case):
    """Verify tactical_ai_nodes functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_nodes_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_nodes_missing_selector(tactical_ai_nodes_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_nodes_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_nodes_invalid_selector(tactical_ai_nodes_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_nodes_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_nodes_nonnumeric_selector(tactical_ai_nodes_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_nodes_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
