"""Native semantic regressions for render_palette_helper_21b880."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021B880 basic viewport initialization and coordinates calculation"),
    ("1", "func_0021B880 fullscreen override and 8bpp format resolution"),
]


@pytest.fixture(scope="module")
def helper_21B880_test(tmp_path_factory):
    """Compile render_palette_helper_21b880 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_palette_helper_21b880 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21B880")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21B880-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_palette_helper_21b880.cpp",
         "tests/native/render_palette_helper_21b880_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21B880_behavior(helper_21B880_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21B880_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
