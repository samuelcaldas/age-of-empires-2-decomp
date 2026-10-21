"""Run native byte-swap behavior checks against the C++ implementations."""

from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
SOURCES = [
    "src/network_byte_swap_337520.cpp", "src/network_byte_swap_337560.cpp",
    "src/network_byte_swap_337590.cpp", "src/network_byte_swap_3375d0.cpp",
    "tests/native/network_address_helpers_test.cpp",
]


def test_byte_swap_helpers_on_host():
    with tempfile.TemporaryDirectory() as directory:
        executable = Path(directory) / "address_helpers"
        compile_result = subprocess.run(
            ["g++", "-m32", "-std=c++98", "-Iinclude", *SOURCES, "-o", str(executable)],
            cwd=ROOT, capture_output=True, text=True,
        )
        assert compile_result.returncode == 0, compile_result.stdout + compile_result.stderr
        run_result = subprocess.run([str(executable)], capture_output=True, text=True)
        assert run_result.returncode == 0, run_result.stdout + run_result.stderr
