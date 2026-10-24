from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_network_send_checked_337840_native(tmp_path):
    """Verify the oversize rejection boundary via native 32-bit compilation and execution."""
    executable = tmp_path / "send-checked-native"
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/network_send_checked_337840_test.cpp",
        "src/network/network_send_checked_337840.cpp",
        "-o", str(executable)
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
    assert compile_res.returncode == 0, (
        f"Compilation failed: {compile_res.stderr}"
    )

    run_res = subprocess.run(
        [str(executable)], capture_output=True, text=True, cwd=ROOT,
    )
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
