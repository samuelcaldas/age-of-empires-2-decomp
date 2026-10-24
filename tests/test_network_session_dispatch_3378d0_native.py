from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_session_dispatch_native(tmp_path):
    executable = tmp_path / "session-dispatch-native"
    compile_result = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
         "tests/native/network_session_dispatch_3378d0_test.cpp",
         "src/network/network_session_dispatch_3378d0.cpp", "-o", str(executable)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert compile_result.returncode == 0, compile_result.stderr
    run_result = subprocess.run([str(executable)], capture_output=True, text=True, cwd=ROOT)
    assert run_result.returncode == 0, run_result.stderr
