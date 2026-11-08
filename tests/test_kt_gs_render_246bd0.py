import subprocess
import pytest
from pathlib import Path

def test_kt_gs_render_246bd0_native():
    repo_root = Path(__file__).resolve().parent.parent
    bin_path = repo_root / "build" / "test_kt_gs_render_246bd0"
    bin_path.parent.mkdir(parents=True, exist_ok=True)
    cmd = [
        "g++", "-O2", "-Iinclude",
        str(repo_root / "tests" / "native" / "kt_gs_render_246bd0_impl.cpp"),
        str(repo_root / "tests" / "native" / "kt_gs_render_246bd0_test.cpp"),
        "-o", str(bin_path)
    ]
    compile_res = subprocess.run(cmd, cwd=repo_root, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"
    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
