from pathlib import Path
import subprocess
import pytest

ROOT = Path(__file__).resolve().parents[1]


def test_receiver_native_contract(tmp_path):
    output = tmp_path / "receiver-test"
    result = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-Iinclude", "src/network_receiver_337B30.cpp",
         "tests/native/network_receiver_337B30_test.cpp", "-o", str(output)],
        cwd=ROOT, capture_output=True, text=True)
    if result.returncode:
        pytest.skip("host g++ -m32 unavailable: " + result.stderr)
    run = subprocess.run([str(output)], capture_output=True, text=True)
    assert run.returncode == 0, run.stdout + run.stderr
