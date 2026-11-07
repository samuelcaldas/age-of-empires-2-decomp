import subprocess
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent

def test_kt_gs_render_2377d0_native(tmp_path):
    test_bin = tmp_path / "kt_gs_render_2377d0_test"
    cmd = [
        "g++",
        "-std=c++17",
        "-Iinclude",
        str(PROJECT_ROOT / "tests/native/kt_gs_render_2377d0_impl.cpp"),
        str(PROJECT_ROOT / "tests/native/kt_gs_render_2377d0_test.cpp"),
        "-o",
        str(test_bin),
    ]
    subprocess.run(cmd, check=True)
    res = subprocess.run([str(test_bin)], capture_output=True, text=True, check=True)
    assert res.returncode == 0
