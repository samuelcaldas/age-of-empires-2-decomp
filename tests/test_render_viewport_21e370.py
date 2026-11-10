"""Native regressions for render_viewport_21e370."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "configures display dimensions and kicks DMA presentation"),
    ("1", "allocates packet buffer when input ctx is null"),
]


@pytest.fixture(scope="module")
def viewport_21e370_test(tmp_path_factory):
    """Compile render_viewport_21e370 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_viewport_21e370 tests require g++")
    fixture = tmp_path_factory.mktemp("viewport-21e370")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "viewport-21e370-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_viewport_21e370.cpp",
         "tests/native/render_viewport_21e370_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_viewport_21e370_behavior(viewport_21e370_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(viewport_21e370_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
