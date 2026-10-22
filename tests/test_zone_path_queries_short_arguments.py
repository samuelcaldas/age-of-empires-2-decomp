"""Native regression for original signed-short projection helper arguments."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = "int main() { static_assert(sizeof(void *) == 4, \"requires 32-bit pointers\"); }"


def require_native_compiler(directory):
    """Return g++ or skip when the native 32-bit toolchain is unavailable."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("zone_path_queries short-argument regression requires g++")
    result = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(directory / "probe")],
        input=PROBE_SOURCE, capture_output=True, text=True,
    )
    if result.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {result.stderr.strip()}")
    return compiler


def compile_regression(compiler, directory):
    """Compile production C++ and return its harness, raising on build failures."""
    binary = directory / "zone-path-queries-short-arguments"
    command = [compiler, "-m32", "-ffunction-sections", "-fdata-sections",
               "-Wl,--gc-sections", "-fno-builtin", "-Iinclude",
               "src/zone_path_queries.cpp",
               "tests/native/zone_path_queries_short_arguments_test.cpp",
               "-o", str(binary)]
    subprocess.run(command, cwd=PROJECT_ROOT, check=True,
                   capture_output=True, text=True)
    return binary


@pytest.fixture(scope="module")
def short_arguments_test(tmp_path_factory):
    """Build the isolated native signed-short forwarding regression harness."""
    directory = tmp_path_factory.mktemp("zone-path-queries-short-arguments")
    compiler = require_native_compiler(directory)
    return compile_regression(compiler, directory)


def test_projection_helpers_sign_extend_low_16_bits(short_arguments_test):
    """Require signed 16-bit helper payloads while projection keeps raw inputs."""
    result = subprocess.run([str(short_arguments_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
