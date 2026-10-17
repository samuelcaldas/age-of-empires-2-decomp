"""Native regressions for unit_action_build_tile_notify."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026F8A0 returns early when func_26A700 returns zero",
    "func_0026F8A0 returns early when resolved target pointer is null",
    "func_0026F8A0 forwards exact tile coordinates and sentinels to func_25F6E0",
]


@pytest.fixture(scope="module")
def build_tile_notify_test(tmp_path_factory):
    """Compile the actual build_tile_notify source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("build_tile_notify regressions require g++")
    fixture = tmp_path_factory.mktemp("action-build-tile-notify")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "build-tile-notify-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_build_tile_notify.cpp",
            "tests/native/unit_action_build_tile_notify_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_build_tile_notify_behavior(build_tile_notify_test, case):
    """Verify tile coordinate queries, pointer chains, and notification arguments."""
    result = subprocess.run([str(build_tile_notify_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
