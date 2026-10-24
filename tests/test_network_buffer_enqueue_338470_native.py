from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_network_buffer_enqueue_338470_native(tmp_path):
    executable = tmp_path / "network-buffer-enqueue-native"
    command = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/network_buffer_enqueue_338470_test.cpp",
        "src/network/network_buffer_enqueue_338470.cpp",
        "-o", str(executable),
    ]
    result = subprocess.run(command, capture_output=True, text=True, cwd=ROOT)
    assert result.returncode == 0, result.stdout + result.stderr
    result = subprocess.run([str(executable)], capture_output=True, text=True, cwd=ROOT)
    assert result.returncode == 0, result.stdout + result.stderr
