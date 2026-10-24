import os
import subprocess
import pytest

@pytest.mark.build
def test_zone_spatial_grid_block56_build():
    """Verify that Block 56 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block56_no_asm():
    """Verify that zero assembly files were generated for Block 56."""
    block56_names = [
        "zone_spatial_grid_scan_cell_nodes",
        "zone_spatial_grid_traverse_quadtree_path",
        "zone_spatial_grid_node_pool_init",
    ]
    for name in block56_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"

def test_zone_spatial_grid_block56_native():
    """Verify behavioral correctness and side effects via native 32-bit test."""
    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block56_test.cpp",
        "src/zone/zone_spatial_grid_scan_cell_nodes.cpp",
        "src/zone/zone_spatial_grid_traverse_quadtree_path.cpp",
        "src/zone/zone_spatial_grid_node_pool_init.cpp",
        "-o", "tests/native/zone_spatial_grid_block56_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"
    run_res = subprocess.run(["./tests/native/zone_spatial_grid_block56_test"], capture_output=True, text=True)
    if os.path.exists("tests/native/zone_spatial_grid_block56_test"):
        os.remove("tests/native/zone_spatial_grid_block56_test")
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
