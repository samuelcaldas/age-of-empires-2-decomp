"""Native regressions for unit_action_build_7a090 (Milestone 128)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def build_7a090_test(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_7a090 regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-7a090")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-7a090-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_build_7a090.cpp",
            "tests/native/unit_action_build_7a090_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


def test_build_7a090_behavior(build_7a090_test):
    """Verify behavior of unit_action_build_7a090."""
    result = subprocess.run([str(build_7a090_test)], capture_output=True, text=True)
    assert result.returncode == 0, f"execution failed: {result.stderr}"
