import subprocess
import pytest
from pathlib import Path

def test_kt_gs_render_245c70_behavioral():
    repo_root = Path(__file__).resolve().parent.parent
    test_src = repo_root / "tests" / "native" / "kt_gs_render_245c70_test.cpp"
    impl_src = repo_root / "tests" / "native" / "kt_gs_render_245c70_impl.cpp"
    include_dir = repo_root / "include"
    bin_path = repo_root / "tests" / "native" / "test_kt_gs_render_245c70_bin"

    cmd_compile = [
        "g++", "-std=c++11",
        f"-I{include_dir}",
        str(test_src), str(impl_src),
        "-o", str(bin_path)
    ]
    subprocess.check_call(cmd_compile)

    try:
        res = subprocess.run([str(bin_path)], capture_output=True, text=True)
        assert res.returncode == 0, f"Native test failed with code {res.returncode}: {res.stderr}"
    finally:
        if bin_path.exists():
            bin_path.unlink()
