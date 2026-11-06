import subprocess
from pathlib import Path

def test_kt_gs_render_22b9b0_native():
    compile_cmd = [
        "g++", "-Iinclude",
        "tests/native/kt_gs_render_22b9b0_test.cpp",
        "tests/native/kt_gs_render_22b9b0_impl.cpp",
        "-o", "tests/native/kt_gs_render_22b9b0_test"
    ]
    res_compile = subprocess.run(compile_cmd, capture_output=True, text=True)
    assert res_compile.returncode == 0, f"Compilation failed: {res_compile.stderr}"

    run_cmd = ["./tests/native/kt_gs_render_22b9b0_test"]
    res_run = subprocess.run(run_cmd, capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
