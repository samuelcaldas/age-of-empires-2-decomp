"""Native regressions for build_ai_list_ops (`0x13DD80`–`0x13DE00`)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "build_ai_list_ops func_0013DD80 null item",
    "build_ai_list_ops func_0013DD80 relink item",
    "build_ai_list_ops func_0013DDD0 null item",
    "build_ai_list_ops func_0013DDD0 unlink item",
]

MARKERS = [
    "BUILD_AI_LIST_OPS_TEST_0_DD80_NULL_PASSED",
    "BUILD_AI_LIST_OPS_TEST_1_DD80_RELINK_PASSED",
    "BUILD_AI_LIST_OPS_TEST_2_DDD0_NULL_PASSED",
    "BUILD_AI_LIST_OPS_TEST_3_DDD0_UNLINK_PASSED",
]


@pytest.fixture(scope="module")
def build_ai_list_ops_test(tmp_path_factory):
    """Compile build_ai_list_ops source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_ai_list_ops regressions require g++")
    fixture = tmp_path_factory.mktemp("build-ai-list-ops")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-ai-list-ops-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/ai/build_ai_list_ops.cpp",
            "tests/native/build_ai_list_ops_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_ai_list_ops_behavior(build_ai_list_ops_test, case):
    """Verify build_ai_list_ops functionality and unique test case markers."""
    result = subprocess.run([str(build_ai_list_ops_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
    assert MARKERS[case] in result.stdout, f"case {case} missing marker {MARKERS[case]}"


def test_build_ai_list_ops_missing_selector(build_ai_list_ops_test):
    """Verify missing selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_list_ops_test)], capture_output=True, text=True)
    assert result.returncode != 0
    assert "argument required" in result.stderr


def test_build_ai_list_ops_invalid_selector(build_ai_list_ops_test):
    """Verify invalid selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_list_ops_test), "99"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode" in result.stderr


def test_build_ai_list_ops_nonnumeric_selector(build_ai_list_ops_test):
    """Verify non-numeric selector argument fails fast with non-zero exit."""
    result = subprocess.run([str(build_ai_list_ops_test), "abc"], capture_output=True, text=True)
    assert result.returncode != 0
    assert "invalid test mode format" in result.stderr
