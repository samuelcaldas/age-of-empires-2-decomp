"""Native regressions for tactical_ai_target_scan (0x307B80)."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""


def _compile_fixture(tmp_path_factory, source_name, bin_name):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("tactical_ai_target_scan regressions require g++")
    fixture_directory = tmp_path_factory.mktemp(bin_name)
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / bin_name
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/ai/tactical_ai_target_scan.cpp",
            f"tests/native/{source_name}",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.fixture(scope="module")
def target_scan_test(tmp_path_factory):
    """Compile target scan test fixture with native 32-bit assertions."""
    return _compile_fixture(tmp_path_factory, "tactical_ai_target_scan_test.cpp", "target-scan-test")


@pytest.fixture(scope="module")
def target_scan_coverage_test(tmp_path_factory):
    """Compile target scan coverage fixture covering Mode 2 gates, Mode 1 predicates, and building modes."""
    return _compile_fixture(tmp_path_factory, "tactical_ai_target_scan_coverage_test.cpp", "target-scan-coverage")


def test_target_scan_evaluation(target_scan_test):
    """Verify target scan gate checks, timestamp interval toggle, and entity iteration."""
    result = subprocess.run([str(target_scan_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr


def test_target_scan_coverage_evaluation(target_scan_coverage_test):
    """Verify Mode 2 gated categories, Mode 1 predicates & ID 533, and building mode filters."""
    result = subprocess.run([str(target_scan_coverage_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
