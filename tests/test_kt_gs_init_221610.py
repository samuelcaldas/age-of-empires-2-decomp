"""Behavioral tests for kt_gs_init_221610."""

import subprocess
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[1]


def test_kt_gs_init_221610_behavior(tmp_path):
    src = PROJECT_ROOT / "src/kcet/kt_gs_init_221610.cpp"
    test_src = PROJECT_ROOT / "tests/native/kt_gs_init_221610_test.cpp"
    exe = tmp_path / "kt_gs_init_221610_test"

    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        str(src), str(test_src), "-o", str(exe)
    ]
    subprocess.run(cmd, check=True)
    res = subprocess.run([str(exe)], capture_output=True, text=True, check=True)
    assert "All kt_gs_init_221610 tests passed!" in res.stdout
