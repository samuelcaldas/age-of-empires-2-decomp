from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_network_func_3379f0_native(tmp_path):
    executable = tmp_path / "network-func-3379f0-native"
    compile_result = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
         "tests/native/network_func_3379f0_test.cpp",
         "src/network/network_func_3379f0.cpp", "-o", str(executable)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert compile_result.returncode == 0, compile_result.stderr
    run_result = subprocess.run([str(executable)], capture_output=True, text=True, cwd=ROOT)
    assert run_result.returncode == 0, run_result.stderr
