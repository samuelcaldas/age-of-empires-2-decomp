"""Native regressions for tactical_ai_actions (`0x141D40`–`0x141F60`).

Reconciled function extents:
- func_00141D40: [0x141D40, 0x141EBC) (0x17C code), padding [0x141EBC, 0x141EC0) (4 B NOP)
- func_00141EC0: [0x141EC0, 0x141F5C) (0x9C code), padding [0x141F5C, 0x141F60) (4 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_actions func_1d40 full",
    "tactical_ai_actions func_1d40 zero cap",
    "tactical_ai_actions func_1ec0 load",
    "tactical_ai_actions layout",
]

MARKERS = [
    "TACTICAL_AI_ACTIONS_TEST_0_1D40_FULL_PASSED",
    "TACTICAL_AI_ACTIONS_TEST_1_1D40_ZERO_CAP_PASSED",
    "TACTICAL_AI_ACTIONS_TEST_2_1EC0_LOAD_PASSED",
    "TACTICAL_AI_ACTIONS_TEST_3_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_actions_test(tmp_path_factory):
    """Compile tactical_ai_actions source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_actions regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-actions")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-actions-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_actions.cpp",
            "tests/native/tactical_ai_actions_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_actions_behavior(tactical_ai_actions_test, case):
    """Verify tactical_ai_actions functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_actions_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_actions_missing_selector(tactical_ai_actions_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_actions_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_actions_invalid_selector(tactical_ai_actions_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_actions_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_actions_nonnumeric_selector(tactical_ai_actions_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_actions_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
