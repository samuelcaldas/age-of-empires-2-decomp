"""Native semantic regressions for render_helper_219F60."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00219F60 initialize stream slots table to zero"),
    ("1", "func_00219FB0 allocate slot and func_0021A040 free slot"),
]


@pytest.fixture(scope="module")
def helper_219F60_test(tmp_path_factory):
    """Compile render_helper_219F60 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_helper_219F60 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-219F60")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-219F60-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_helper_219F60.cpp",
         "tests/native/render_helper_219F60_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_219F60_behavior(helper_219F60_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_219F60_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
