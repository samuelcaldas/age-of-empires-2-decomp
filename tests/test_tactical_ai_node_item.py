"""Native regressions for tactical_ai_node_item (`0x144440`–`0x1446B0`).

Reconciled function extents:
- func_00144434: [0x144440, 0x144464) (0x24 code), padding [0x144464, 0x144470) (12 B NOP)
- func_00144464: [0x144470, 0x1444AC) (0x3C code), padding [0x1444AC, 0x1444C0) (20 B NOP)
- func_001444B4: [0x1444C0, 0x1444E0) (0x20 code), padding [0x1444E0, 0x1444F0) (16 B NOP)
- func_001444E4: [0x1444F0, 0x144528) (0x38 code), padding [0x144528, 0x144530) (8 B NOP)
- func_00144524: [0x144530, 0x144544) (0x14 code), padding [0x144544, 0x144550) (12 B NOP)
- func_144550: [0x144550, 0x144698) (0x148 code), padding [0x144698, 0x1446A0) (8 B NOP)
- func_001446A0: [0x1446A0, 0x1446A8) (0x8 code), padding [0x1446A8, 0x1446B0) (8 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_node_item ctor",
    "tactical_ai_node_item dtor",
    "tactical_ai_node_item setters",
    "tactical_ai_node_item eval field0 3",
    "tactical_ai_node_item resets",
    "tactical_ai_node_item 144550 field0 3",
    "tactical_ai_node_item 144550 field0 2 cached",
    "tactical_ai_node_item 144550 field0 1 params",
    "tactical_ai_node_item 1446a0",
    "tactical_ai_node_item layout",
]

MARKERS = [
    "TACTICAL_AI_NODE_ITEM_TEST_0_CTOR_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_1_DTOR_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_2_SETTERS_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_3_EVAL_FIELD0_3_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_4_RESETS_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_5_144550_FIELD0_3_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_6_144550_FIELD0_2_CACHED_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_7_144550_FIELD0_1_PARAMS_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_8_1446A0_PASSED",
    "TACTICAL_AI_NODE_ITEM_TEST_9_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_node_item_test(tmp_path_factory):
    """Compile tactical_ai_node_item source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_node_item regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-node-item")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-node-item-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_node_item.cpp",
            "tests/native/tactical_ai_node_item_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_node_item_behavior(tactical_ai_node_item_test, case):
    """Verify tactical_ai_node_item functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_node_item_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_node_item_missing_selector(tactical_ai_node_item_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_node_item_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_node_item_invalid_selector(tactical_ai_node_item_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_node_item_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_node_item_nonnumeric_selector(tactical_ai_node_item_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_node_item_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
