"""Native compilation and linkage smoke test for tactical_ai_slice_342800 stubs.

NOTE: Stub functions in tactical_ai_slice_342800 are currently no-ops.
This test verifies 32-bit compilation and clean linkage only. Behavioral regression
evidence will be added when implementing actual slice logic under TDD.
"""

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
    """Compile tactical_ai_slice_342800 stub with native smoke test driver."""
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
            "-flto",
            "-Werror=lto-type-mismatch",
            "-Iinclude",
            "tests/native/tactical_ai_slice_342800_test.cpp",
            "src/ai/tactical_ai_slice_342800.cpp",
            "src/ai/tactical_ai_func_3429e0.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_tactical_ai_slice_342800_smoke_runner(tactical_ai_slice_342800_binary):
    """Verify tactical_ai_slice_342800 stub entrypoints link and execute cleanly (smoke only)."""
    res = subprocess.run([str(tactical_ai_slice_342800_binary)], capture_output=True, text=True, check=True)
    assert "PASS smoke_test_tactical_ai_slice_342800_stubs" in res.stdout
