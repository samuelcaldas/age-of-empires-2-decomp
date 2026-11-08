import subprocess
from pathlib import Path

def test_kt_gs_render_252430_native():
    repo = Path(__file__).resolve().parent.parent
    build_dir = repo / "build" / "native_tests"
    build_dir.mkdir(parents=True, exist_ok=True)
    binary = build_dir / "kt_gs_render_252430_test"

    cmd = [
        "g++", "-std=c++17", "-O2",
        "-I", str(repo / "include"),
        str(repo / "tests" / "native" / "kt_gs_render_252430_impl.cpp"),
        str(repo / "tests" / "native" / "kt_gs_render_252430_test.cpp"),
        "-o", str(binary)
    ]
    subprocess.run(cmd, check=True)
    res = subprocess.run([str(binary)], check=True, capture_output=True, text=True)
    assert "kt_gs_render_252430 native tests passed successfully." in res.stdout
