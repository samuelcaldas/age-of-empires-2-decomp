"""Native regressions for tactical_ai_cleanup (`0x144050`–`0x1441B0`).

Reconciled function extents:
- func_144050: [0x144050, 0x14417C) (0x12C code), padding [0x14417C, 0x144180) (4 B NOP)
- func_144180: [0x144180, 0x1441A4) (0x24 code), padding [0x1441A4, 0x1441B0) (12 B NOP)
"""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "tactical_ai_cleanup func_144050",
    "tactical_ai_cleanup func_144180",
    "tactical_ai_cleanup layout",
]

MARKERS = [
    "TACTICAL_AI_CLEANUP_TEST_0_144050_PASSED",
    "TACTICAL_AI_CLEANUP_TEST_1_144180_PASSED",
    "TACTICAL_AI_CLEANUP_TEST_2_LAYOUT_PASSED",
]


@pytest.fixture(scope="module")
def tactical_ai_cleanup_test(tmp_path_factory):
    """Compile tactical_ai_cleanup source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_cleanup regressions require g++")
    fixture = tmp_path_factory.mktemp("tactical-ai-cleanup")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "tactical-ai-cleanup-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/tactical_ai_cleanup.cpp",
            "tests/native/tactical_ai_cleanup_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_tactical_ai_cleanup_behavior(tactical_ai_cleanup_test, case):
    """Verify tactical_ai_cleanup functionality and unique test case markers."""
    result = subprocess.run([str(tactical_ai_cleanup_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_tactical_ai_cleanup_missing_selector(tactical_ai_cleanup_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_cleanup_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_tactical_ai_cleanup_invalid_selector(tactical_ai_cleanup_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_cleanup_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_tactical_ai_cleanup_nonnumeric_selector(tactical_ai_cleanup_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(tactical_ai_cleanup_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
