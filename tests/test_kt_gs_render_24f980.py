import subprocess
from pathlib import Path

def test_kt_gs_render_24f980_native():
    root = Path(__file__).resolve().parents[1]
    exe = root / "build" / "native" / "kt_gs_render_24f980_test"
    exe.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([
        "g++", "-I", str(root / "include"),
        str(root / "tests" / "native" / "kt_gs_render_24f980_impl.cpp"),
        str(root / "tests" / "native" / "kt_gs_render_24f980_test.cpp"),
        "-o", str(exe)
    ], check=True)
    subprocess.run([str(exe)], check=True)
