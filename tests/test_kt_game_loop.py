"""Native semantic regressions for kt_game_loop_2206a0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "main game engine thread loop execution and frame counting"),
]


@pytest.fixture(scope="module")
def game_loop_test(tmp_path_factory):
    """Compile kt_game_loop_2206a0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("kt_game_loop tests require g++")
    fixture = tmp_path_factory.mktemp("kt-game-loop")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "kt-game-loop-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/kcet/kt_game_loop_2206a0.cpp",
         "tests/native/kt_game_loop_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_kt_game_loop_behavior(game_loop_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(game_loop_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
