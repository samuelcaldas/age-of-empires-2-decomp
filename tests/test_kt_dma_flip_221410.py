"""Behavioral tests for kt_dma_flip_221410."""

import subprocess
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[1]


def test_kt_dma_flip_221410_behavior(tmp_path):
    src = PROJECT_ROOT / "src/kcet/kt_dma_flip_221410.cpp"
    test_src = PROJECT_ROOT / "tests/native/kt_dma_flip_221410_test.cpp"
    exe = tmp_path / "kt_dma_flip_221410_test"

    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        str(src), str(test_src), "-o", str(exe)
    ]
    subprocess.run(cmd, check=True)
    res = subprocess.run([str(exe)], capture_output=True, text=True, check=True)
    assert "All kt_dma_flip_221410 tests passed!" in res.stdout
