"""Native semantic regressions for trade action helper 217A10 block."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00217A10 stores fields and invokes vtable 0x28"),
    ("1", "func_00217A50 stores fields, switch 0x1BC, calls func_00217B50"),
    ("2", "func_00217AD0 stores field 0x1C0, calls func_00217B50"),
    ("3", "func_00217AE0 calls 1F3DC0 and dispatches method 0x1C"),
]


@pytest.fixture(scope="module")
def helper_217A10_test(tmp_path_factory):
    """Compile render_helper_217A10 with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_helper_217A10 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-217A10")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "helper-217A10-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/render_helper_217A10.cpp",
         "tests/native/render_helper_217A10_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_helper_217A10_behavior(helper_217A10_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_217A10_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
