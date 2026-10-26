"""Native semantic regressions for DRS archive parser."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "validate DRS archive header and version"),
    ("1", "find resource tables by tag (slp, pal, wav)"),
    ("2", "find resource records by ID"),
    ("3", "calculate sector and memory alignment"),
]


@pytest.fixture(scope="module")
def drs_archive_test(tmp_path_factory):
    """Compile drs_parser with test harness."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("drs_archive_test requires g++")
    fixture = tmp_path_factory.mktemp("drs-archive")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "drs-archive-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude",
         "src/engine/drs_parser.cpp",
         "tests/native/drs_archive_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_drs_archive_behavior(drs_archive_test, case, description):
    """Run each behavior in an isolated native process."""
    result = subprocess.run(
        [str(drs_archive_test), case], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
