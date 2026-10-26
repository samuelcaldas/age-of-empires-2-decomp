"""Native semantic regressions for render_viewport_21a850."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0021A850 flag 0x800 translates rect and dispatches to func_0021AE90"),
    ("1", "func_0021A850 default flags with arg3 translates rect and calls 21A960"),
    ("2", "func_0021A850 default flags with null arg3 skips 21ACD0"),
]


@pytest.fixture(scope="module")
def helper_21A850_test(tmp_path_factory):
    """Compile render_viewport_21a850 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_viewport_21a850 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21A850")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21A850-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_viewport_21a850.cpp",
         "tests/native/render_viewport_21a850_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21A850_behavior(helper_21A850_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21A850_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
