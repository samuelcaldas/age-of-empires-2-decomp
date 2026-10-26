"""Native semantic regressions for SLP sprite decoder and offset relocator."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "validate SLP 2.0N header and frame counts"),
    ("1", "relocate sub-image entry offsets"),
    ("2", "relocate row edge command offsets"),
    ("3", "validate frame bounds against display limits"),
]


@pytest.fixture(scope="module")
def slp_decoder_test(tmp_path_factory):
    """Compile slp_decoder with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("slp_decoder_test requires g++")
    fixture = tmp_path_factory.mktemp("slp-decoder")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "slp-decoder-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/render/slp_decoder.cpp",
         "tests/native/slp_decoder_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_slp_decoder_behavior(slp_decoder_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(slp_decoder_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
