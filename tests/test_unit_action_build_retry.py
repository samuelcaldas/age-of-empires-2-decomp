"""Native regressions for unit_action_build_retry."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00270A20 game mode 7 with master type != 50 returns early",
    "func_00270A20 status 8 rewrites to 27 on non-matching actor and player match preserves status",
    "func_00270A20 direct statuses 1, 28, and 14 resolve flag 15 without tile lookup",
    "func_00270A20 tile lookup and zone flag override conditions force flag 15",
    "func_00270A20 non-15 flag writes status directly to self->m_field15A",
]


@pytest.fixture(scope="module")
def build_retry_test(tmp_path_factory):
    """Compile the actual build_retry source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_retry regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-retry")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-retry-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_retry.cpp",
            "tests/native/unit_action_build_retry_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_retry_behavior(build_retry_test, case):
    """Verify game mode filtering, status rewriting, and zone flag evaluation."""
    result = subprocess.run([str(build_retry_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
