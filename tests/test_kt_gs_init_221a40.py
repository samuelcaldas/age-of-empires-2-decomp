"""Behavioral tests for kt_gs_init_221a40 slice."""

from pathlib import Path
import subprocess

PROJECT_ROOT = Path(__file__).resolve().parents[1]


def test_kt_gs_init_221a40_behavior(tmp_path):
    src = PROJECT_ROOT / "src/kcet/kt_gs_init_221a40.cpp"
    test_src = PROJECT_ROOT / "tests/native/kt_gs_init_221a40_test.cpp"
    bin_path = tmp_path / "kt_gs_init_221a40_test"

    subprocess.run(
        ["g++", "-std=c++11", "-Iinclude", str(src), str(test_src), "-o", str(bin_path)],
        cwd=PROJECT_ROOT,
        check=True,
    )
    subprocess.run([str(bin_path)], check=True)
