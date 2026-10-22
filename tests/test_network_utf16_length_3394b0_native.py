from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_network_utf16_length_3394b0_native(tmp_path):
    executable = tmp_path / "network-utf16-length"
    compile_result = subprocess.run(
        ["g++", "-std=c++98", "-O2", "-Iinclude",
         "tests/native/network_utf16_length_3394b0_test.cpp",
         "src/network_utf16_length_3394b0.cpp", "-o", str(executable)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert compile_result.returncode == 0, compile_result.stderr
    run_result = subprocess.run([str(executable)], capture_output=True, text=True)
    assert run_result.returncode == 0, run_result.stderr
