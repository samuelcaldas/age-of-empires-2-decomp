"""Native behavioral regressions for tactical_ai_slice_342800."""

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
def tactical_ai_slice_342800_binary(tmp_path_factory):
    """Compile tactical_ai_slice_342800 stub with native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_slice_342800 regressions require g++")
    fixture_dir = tmp_path_factory.mktemp("tactical-slice-342800")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "tactical-slice-342800-test"
    subprocess.run(
        [
            compiler,
            "-m32",
            "-std=c++98",
            "-Iinclude",
            "tests/native/tactical_ai_slice_342800_test.cpp",
            "src/tactical_ai_slice_342800.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_tactical_ai_slice_342800_native_runner(tactical_ai_slice_342800_binary):
    """Verify all tactical_ai_slice_342800 stub entrypoints execute without fault."""
    res = subprocess.run([str(tactical_ai_slice_342800_binary)], capture_output=True, text=True, check=True)
    assert "PASS test_tactical_ai_slice_3444D0" in res.stdout
