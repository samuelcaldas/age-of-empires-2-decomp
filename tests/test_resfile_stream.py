"""Native semantic regressions for RESFILE resource streaming and overflow protection."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "initialize resfile streaming context"),
    ("1", "register and query stream by ID"),
    ("2", "load resource slice from stream buffer"),
    ("3", "detect buffer overflow and protect against overrun"),
]


@pytest.fixture(scope="module")
def resfile_stream_test(tmp_path_factory):
    """Compile resfile_stream with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("resfile_stream_test requires g++")
    fixture = tmp_path_factory.mktemp("resfile-stream")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "resfile-stream-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/engine/resfile_stream.cpp",
         "tests/native/resfile_stream_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_resfile_stream_behavior(resfile_stream_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(resfile_stream_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
