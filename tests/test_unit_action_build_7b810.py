"""Native regressions for unit_action_build_7b810 (Milestone 137)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0027B810 linked list node search by type",
    "func_0027B850 linked list node lookup by 1-based index",
    "func_0027B890 linked list node lookup by count",
    "func_0027B8D0 linked list node position query and match count",
]


@pytest.fixture(scope="module")
def build_7b810_test(tmp_path_factory):
    """Compile unit_action_build_7b810 with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7b810 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7b810")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7b810-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_7b810.cpp",
            "tests/native/unit_action_build_7b810_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_7b810_behavior(build_7b810_test, case):
    """Verify CombatManager event list queries."""
    result = subprocess.run([str(build_7b810_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
