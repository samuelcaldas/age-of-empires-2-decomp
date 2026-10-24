"""Native regressions for tactical_ai_dispatch (`0x142130`–`0x1422F0`).

Reconciled function extents:
- func_00142130: [0x142130, 0x14219C) (0x6C code), padding [0x14219C, 0x1421A0) (4 B NOP)
- func_001421A0: [0x1421A0, 0x1421FC) (0x5C code), padding [0x1421FC, 0x142200) (4 B NOP)
- func_00142200: [0x142200, 0x14225C) (0x5C code), padding [0x14225C, 0x142260) (4 B NOP)
- func_00142260: [0x142260, 0x1422EC) (0x8C code), padding [0x1422EC, 0x1422F0) (4 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_dispatch func_2130",
    "tactical_ai_dispatch func_21a0",
    "tactical_ai_dispatch func_2200",
    "tactical_ai_dispatch func_2260 fail1170",
    "tactical_ai_dispatch func_2260 success",
    "tactical_ai_dispatch layout",
]

MARKERS = [
    "TACTICAL_AI_DISPATCH_TEST_0_2130_PASSED",
    "TACTICAL_AI_DISPATCH_TEST_1_21A0_PASSED",
    "TACTICAL_AI_DISPATCH_TEST_2_2200_PASSED",
    "TACTICAL_AI_DISPATCH_TEST_3_2260_FAIL1170_PASSED",
    "TACTICAL_AI_DISPATCH_TEST_4_2260_SUCCESS_PASSED",
    "TACTICAL_AI_DISPATCH_TEST_5_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_dispatch_test(tmp_path_factory):
    """Compile tactical_ai_dispatch source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_dispatch regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-dispatch")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-dispatch-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/tactical_ai_dispatch.cpp",
            "tests/native/tactical_ai_dispatch_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_dispatch_behavior(tactical_ai_dispatch_test, case):
    """Verify tactical_ai_dispatch functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_dispatch_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_dispatch_missing_selector(tactical_ai_dispatch_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_dispatch_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_dispatch_invalid_selector(tactical_ai_dispatch_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_dispatch_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_dispatch_nonnumeric_selector(tactical_ai_dispatch_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_dispatch_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
