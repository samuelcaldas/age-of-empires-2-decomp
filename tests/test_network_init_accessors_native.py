"""Compile and run native contracts for network initialization and state accessors."""
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def test_network_initialization_and_accessors(tmp_path):
    executable = tmp_path / "network_init_accessors_test"
    result = subprocess.run(
        ["g++", "-std=c++11", "-Iinclude", "tests/native/network_init_accessors_test.cpp",
         "src/network_init_3377d0.cpp", "src/network_state_set_337820.cpp",
         "src/network_state_get_337830.cpp", "-o", str(executable)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    result = subprocess.run([str(executable)], capture_output=True, text=True)
    assert result.returncode == 0, result.stdout + result.stderr
