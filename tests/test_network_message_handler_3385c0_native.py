"""Build and run native handler behavior checks."""

from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def test_network_message_handler_native(tmp_path):
    executable = tmp_path / "network_message_handler_test"
    compile_result = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-Iinclude",
         "tests/native/network_message_handler_3385c0_test.cpp", "-o", str(executable)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert compile_result.returncode == 0, compile_result.stdout + compile_result.stderr
    result = subprocess.run([str(executable)], capture_output=True, text=True)
    assert result.returncode == 0, result.stdout + result.stderr
