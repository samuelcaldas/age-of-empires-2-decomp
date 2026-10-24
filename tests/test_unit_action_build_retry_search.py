"""Native regressions for unit_action_build_retry_search."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270BA0 status 27 matches tile flag set {0, 12, 3, 7..9, 29..31} and updates to 27",
    "func_00270BA0 non-27 status matches exact tile flag and preserves non-matching tiles",
    "func_00270BA0 gate master type 109 preserves the 4 excluded boundary points",
    "func_00270BA0 unmatching tiles result in zero modifications and skip notify call",
]


@pytest.fixture(scope="module")
def build_retry_search_test(tmp_path_factory):
    """Compile the actual build_retry_search source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_retry_search regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-retry-search")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-retry-search-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_retry_search.cpp",
            "tests/native/unit_action_build_retry_search_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_retry_search_behavior(build_retry_search_test, case):
    """Verify bounding box scan, status 27 sets, gate 109 exclusions, and notification."""
    result = subprocess.run([str(build_retry_search_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
