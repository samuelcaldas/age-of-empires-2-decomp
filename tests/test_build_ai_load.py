"""Native regressions for build_ai_load (`0x13CDE0`–`0x13D370`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "build_ai_load func_0013CDE0 count 0",
    "build_ai_load func_0013CDE0 count 1",
    "build_ai_load func_0013D2B0 null self",
    "build_ai_load func_0013D2B0 flag 1 with data",
    "build_ai_load func_0013D2B0 flag 0",
]

MARKERS = [
    "BUILD_AI_LOAD_TEST_0_CDE0_COUNT0_PASSED",
    "BUILD_AI_LOAD_TEST_1_CDE0_COUNT1_PASSED",
    "BUILD_AI_LOAD_TEST_2_D2B0_NULL_PASSED",
    "BUILD_AI_LOAD_TEST_3_D2B0_FLAG1_PASSED",
    "BUILD_AI_LOAD_TEST_4_D2B0_FLAG0_PASSED",
]


@pytest.fixture(scope="module")
def build_ai_load_test(tmp_path_factory):
    """Compile build_ai_load source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_ai_load regressions require g++")
    fixture = tmp_path_factory.mktemp("build-ai-load")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-ai-load-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/build_ai_load.cpp",
            "tests/native/build_ai_load_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_ai_load_behavior(build_ai_load_test, case):
    """Verify build_ai_load functionality and unique test case markers."""
    result = subprocess.run([str(build_ai_load_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_build_ai_load_missing_selector(build_ai_load_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_load_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_build_ai_load_invalid_selector(build_ai_load_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_load_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_build_ai_load_nonnumeric_selector(build_ai_load_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_load_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
