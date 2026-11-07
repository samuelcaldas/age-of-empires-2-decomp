import subprocess
from pathlib import Path

def test_kt_gs_render_23a500_native():
    root = Path(__file__).resolve().parents[1]
    impl = root / "tests/native/kt_gs_render_23a500_impl.cpp"
    test = root / "tests/native/kt_gs_render_23a500_test.cpp"
    bin_path = root / "build/test_kt_gs_render_23a500"
    bin_path.parent.mkdir(parents=True, exist_ok=True)

    cmd_compile = [
        "g++",
        "-std=c++17",
        "-Iinclude",
        str(impl),
        str(test),
        "-o",
        str(bin_path),
    ]
    subprocess.run(cmd_compile, check=True)
    subprocess.run([str(bin_path)], check=True)
