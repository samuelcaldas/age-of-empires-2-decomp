import subprocess
from pathlib import Path

def test_kt_gs_render_23a270_native():
    root = Path(__file__).resolve().parents[1]
    impl = root / "tests/native/kt_gs_render_23a270_impl.cpp"
    test = root / "tests/native/kt_gs_render_23a270_test.cpp"
    bin_path = root / "build/test_kt_gs_render_23a270"
    bin_path.parent.mkdir(parents=True, exist_ok=True)

    cmd_compile = [
        "g++",
        "-m32",
        "-std=c++17",
        "-Iinclude",
        str(impl),
        str(test),
        "-o",
        str(bin_path),
    ]
    subprocess.run(cmd_compile, check=True)
    subprocess.run([str(bin_path)], check=True)
