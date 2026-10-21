from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_network_transport_init_native(tmp_path):
    executable = tmp_path / "transport-init-native"
    command = [
        "g++", "-m32", "-std=c++98", "-Iinclude",
        "tests/native/network_transport_init_337d40_test.cpp",
        "src/network_transport_init_337d40.cpp", "-o", str(executable),
    ]
    compile_result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    assert compile_result.returncode == 0, compile_result.stderr
    run_result = subprocess.run([str(executable)], cwd=ROOT, capture_output=True, text=True)
    assert run_result.returncode == 0, run_result.stderr
