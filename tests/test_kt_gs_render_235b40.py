from pathlib import Path
import subprocess

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_kt_gs_render_235b40_behavior(tmp_path):
    bin_path = tmp_path / "kt_gs_render_235b40_test"
    subprocess.run(
        [
            "g++",
            "-O2",
            "-Iinclude",
            "tests/native/kt_gs_render_235b40_test.cpp",
            "tests/native/kt_gs_render_235b40_impl.cpp",
            "-o",
            str(bin_path),
        ],
        cwd=PROJECT_ROOT,
        check=True,
    )
    result = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert result.returncode == 0
    assert "kt_gs_render_235b40 tests passed!" in result.stdout
