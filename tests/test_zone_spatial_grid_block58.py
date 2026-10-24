import pytest
import os
import subprocess
import sys


@pytest.mark.build
def test_zone_spatial_grid_block58_build():
    """Verify that Block 58 objects configure and build cleanly."""
    for f in [".ninja_log", ".ninja_deps"]:
        if os.path.exists(f):
            os.remove(f)
    cfg_res = subprocess.run([sys.executable, "configure.py", "--version", "SLES-50282"], capture_output=True, text=True)
    assert cfg_res.returncode == 0, f"configure failed: {cfg_res.stderr}"
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"


def test_zone_spatial_grid_block58_no_asm():
    """Verify that decompiled source files are 100% pure C/C++ without embedded assembly."""
    with open("src/zone/zone_spatial_grid_node_pool_expand.cpp", "r") as f:
        content = f.read()
    assert "__asm__" not in content, "Found embedded assembly"
    assert ".word" not in content, "Found raw opcodes"
    assert "asm" not in content or "exceptions" in content, "Found unexpected assembly directive"


def test_zone_spatial_grid_block58_native():
    """Verify behavioral correctness and side effects via native 32-bit test."""
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block58_test.cpp",
        "src/zone/zone_spatial_grid_node_pool_expand.cpp",
        "-o", "tests/native/zone_spatial_grid_block58_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"

    try:
        run_res = subprocess.run(["./tests/native/zone_spatial_grid_block58_test"], capture_output=True, text=True)
        assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
    finally:
        if os.path.exists("tests/native/zone_spatial_grid_block58_test"):
            os.remove("tests/native/zone_spatial_grid_block58_test")
