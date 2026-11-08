from __future__ import annotations

import subprocess
from pathlib import Path


def test_kt_gs_render_254d50_native() -> None:
    build_dir = Path("build/native_tests")
    build_dir.mkdir(parents=True, exist_ok=True)
    bin_path = build_dir / "kt_gs_render_254d50_test"

    cmd_compile = [
        "g++",
        "-std=c++17",
        "-Iinclude",
        "tests/native/kt_gs_render_254d50_impl.cpp",
        "tests/native/kt_gs_render_254d50_test.cpp",
        "-o",
        str(bin_path),
    ]
    res = subprocess.run(cmd_compile, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert res.returncode == 0, f"Execution failed: {res.stderr}"
