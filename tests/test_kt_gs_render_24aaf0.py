import subprocess
from pathlib import Path

def test_kt_gs_render_24aaf0_behavior(tmp_path):
    repo_root = Path(__file__).resolve().parent.parent
    src = repo_root / "tests" / "native" / "kt_gs_render_24aaf0_test.cpp"
    impl = repo_root / "tests" / "native" / "kt_gs_render_24aaf0_impl.cpp"
    bin_path = tmp_path / "kt_gs_render_24aaf0_test"

    compile_cmd = [
        "g++",
        "-std=c++17",
        f"-I{repo_root / 'include'}",
        str(src),
        str(impl),
        "-o",
        str(bin_path),
    ]
    subprocess.run(compile_cmd, check=True)
    subprocess.run([str(bin_path)], check=True)
