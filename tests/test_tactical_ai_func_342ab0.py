"""Execute native behavioral unit tests for tactical AI level check function 0x342AB0."""

import shutil
import subprocess
from pathlib import Path

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
#include <cstring>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""


@pytest.fixture(scope="module")
def tactical_ai_func_342ab0_binary(tmp_path_factory):
    """Compile func_00342AB0 with native behavioral test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_func_342ab0 regressions require g++")
    fixture_dir = tmp_path_factory.mktemp("tactical-func-342ab0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "tactical-func-342ab0-test"
    subprocess.run(
        [
            compiler,
            "-m32",
            "-std=c++98",
            "-flto",
            "-Werror=lto-type-mismatch",
            "-Iinclude",
            "tests/native/tactical_ai_func_342ab0_test.cpp",
            "src/tactical_ai_func_342ab0.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_tactical_ai_func_342ab0_native_runner(tactical_ai_func_342ab0_binary):
    """Execute native behavioral tests for func_00342AB0."""
    res = subprocess.run([str(tactical_ai_func_342ab0_binary)], capture_output=True, text=True)
    assert res.returncode == 0, f"Native test failed:\n{res.stderr}"
    assert "ALL TACTICAL AI FUNC 342AB0 TESTS PASSED" in res.stdout
