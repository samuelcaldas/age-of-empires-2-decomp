import subprocess
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

def test_kt_gs_render_256800_native():
    build_dir = REPO_ROOT / "build" / "native_tests"
    build_dir.mkdir(parents=True, exist_ok=True)
    test_bin = build_dir / "kt_gs_render_256800_test"

    cmd_compile = [
        "g++",
        "-std=c++17",
        "-I", str(REPO_ROOT / "include"),
        str(REPO_ROOT / "tests" / "native" / "kt_gs_render_256800_impl.cpp"),
        str(REPO_ROOT / "tests" / "native" / "kt_gs_render_256800_test.cpp"),
        "-o", str(test_bin),
    ]
    res_compile = subprocess.run(cmd_compile, capture_output=True, text=True)
    assert res_compile.returncode == 0, f"Compilation failed: {res_compile.stderr}"

    res_run = subprocess.run([str(test_bin)], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Test execution failed: {res_run.stderr}"
