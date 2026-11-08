import subprocess
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

def test_kt_gs_render_24df80_native(tmp_path):
    bin_path = tmp_path / "kt_gs_render_24df80_test"
    cmd = [
        "g++",
        "-std=c++17",
        "-Iinclude",
        str(REPO_ROOT / "tests" / "native" / "kt_gs_render_24df80_impl.cpp"),
        str(REPO_ROOT / "tests" / "native" / "kt_gs_render_24df80_test.cpp"),
        "-o",
        str(bin_path),
    ]
    subprocess.run(cmd, check=True, cwd=REPO_ROOT)
    res = subprocess.run([str(bin_path)], check=True, capture_output=True)
    assert res.returncode == 0
