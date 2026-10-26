"""Native semantic regressions for render_manager_init_21bdf0."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021BDF0 initialization and configuration"),
    ("1", "func_0021BDF0 allocation failure handling"),
]


@pytest.fixture(scope="module")
def render_init_21bdf0_test(tmp_path_factory):
    """Compile render_manager_init_21bdf0 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_init_21bdf0 tests require g++")
    fixture = tmp_path_factory.mktemp("render-init-21bdf0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "render-init-21bdf0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_manager_init_21bdf0.cpp",
         "tests/native/render_manager_init_21bdf0_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_render_init_21bdf0_behavior(render_init_21bdf0_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(render_init_21bdf0_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
