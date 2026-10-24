from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_network_join_request_338fa0_native(tmp_path):
    executable = tmp_path / "join-request-native"
    result = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
         "tests/native/network_join_request_338fa0_test.cpp",
         "src/network/network_join_request_338fa0.cpp", "-o", str(executable)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert result.returncode == 0, result.stderr
    execution = subprocess.run([str(executable)], capture_output=True, text=True, cwd=ROOT)
    assert execution.returncode == 0, execution.stderr
