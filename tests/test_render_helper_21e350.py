"""Native behavioral regressions for render_helper_21e350."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "base case zero offset returns 0x7C000"),
    ("1", "low bits outside mask 0x1F0 are ignored"),
    ("2", "valid offset is shifted left by 4"),
    ("3", "max mask value 0x1F0 yields 0x7DF00"),
]


@pytest.fixture(scope="module")
def helper_21e350_test(tmp_path_factory):
    """Compile render_helper_21e350 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_helper_21e350 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-21e350")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-21e350-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_helper_21e350.cpp",
         "tests/native/render_helper_21e350_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_21e350_behavior(helper_21e350_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_21e350_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
