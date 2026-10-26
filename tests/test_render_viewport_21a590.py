"""Native semantic regressions for render_viewport_21a590."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021A590 default null rect and 27-word buffer copy"),
    ("1", "func_0021A590 custom rect with stride and pitch offset computation"),
    ("2", "func_0021A590 flag 0x4000 sets view offset to minus one"),
]


@pytest.fixture(scope="module")
def helper_21A590_test(tmp_path_factory):
    """Compile render_viewport_21a590 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_viewport_21a590 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21A590")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21A590-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_viewport_21a590.cpp",
         "tests/native/render_viewport_21a590_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21A590_behavior(helper_21A590_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21A590_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
