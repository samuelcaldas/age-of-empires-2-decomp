import os
import subprocess
import pytest

def test_zone_spatial_grid_block57_build():
    """Verify that Block 57 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block57_no_asm():
    """Verify that zero assembly files were generated for Block 57."""
    block57_names = [
        "zone_spatial_grid_node_pool_setup",
        "zone_spatial_grid_node_pool_destructor",
        "zone_spatial_grid_node_pool_clear",
    ]
    for name in block57_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"

def test_zone_spatial_grid_block57_native():
    """Verify behavioral correctness and side effects via native 32-bit test."""
    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block57_test.cpp",
        "src/zone_spatial_grid_node_pool_setup.cpp",
        "src/zone_spatial_grid_node_pool_destructor.cpp",
        "src/zone_spatial_grid_node_pool_clear.cpp",
        "-o", "tests/native/zone_spatial_grid_block57_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"
    run_res = subprocess.run(["./tests/native/zone_spatial_grid_block57_test"], capture_output=True, text=True)
    if os.path.exists("tests/native/zone_spatial_grid_block57_test"):
        os.remove("tests/native/zone_spatial_grid_block57_test")
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
