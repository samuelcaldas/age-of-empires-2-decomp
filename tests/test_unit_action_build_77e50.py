"""Native regressions for unit_action_build_77e50 (Milestone 106)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def build_77e50_test(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_77e50 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-77e50")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-77e50-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_77e50.cpp",
            "tests/native/unit_action_build_77e50_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


def test_build_77e50_behavior(build_77e50_test):
    """Verify behavior of unit_action_build_77e50."""
    result = subprocess.run([str(build_77e50_test)], capture_output=True, text=True)
    assert result.returncode == 0, f"execution failed: {result.stderr}"
