import subprocess
from pathlib import Path

def test_kt_gs_render_23adc0_native():
    repo_root = Path(__file__).resolve().parent.parent
    build_dir = repo_root / "build" / "native_tests"
    build_dir.mkdir(parents=True, exist_ok=True)
    binary = build_dir / "kt_gs_render_23adc0_test"

    cmd_compile = [
        "g++", "-std=c++17", "-O2",
        "-I", str(repo_root / "include"),
        str(repo_root / "tests" / "native" / "kt_gs_render_23adc0_impl.cpp"),
        str(repo_root / "tests" / "native" / "kt_gs_render_23adc0_test.cpp"),
        "-o", str(binary)
    ]
    subprocess.run(cmd_compile, check=True)
    subprocess.run([str(binary)], check=True)
