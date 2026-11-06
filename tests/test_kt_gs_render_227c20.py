from pathlib import Path
import subprocess

def test_kt_gs_render_227c20_native():
    repo = Path(__file__).resolve().parent.parent
    cmd = [
        "g++", "-std=c++11", "-Wall",
        str(repo / "tests/native/kt_gs_render_227c20_test.cpp"),
        str(repo / "tests/native/kt_gs_render_227c20_impl.cpp"),
        "-o", "/tmp/kt_gs_render_227c20_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run(["/tmp/kt_gs_render_227c20_test"], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
    assert "kt_gs_render_227c20 native behavioral test passed!" in run_res.stdout
