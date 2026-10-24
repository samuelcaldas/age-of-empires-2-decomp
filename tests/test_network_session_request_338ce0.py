from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_network_session_request_338ce0_native(tmp_path):
    executable = tmp_path / "session-request-native"
    command = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/network_session_request_338ce0_test.cpp",
        "src/network/network_session_request_338ce0.cpp", "-o", str(executable),
    ]
    compilation = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    assert compilation.returncode == 0, compilation.stderr
    execution = subprocess.run([str(executable)], cwd=ROOT, capture_output=True, text=True)
    assert execution.returncode == 0, execution.stderr
