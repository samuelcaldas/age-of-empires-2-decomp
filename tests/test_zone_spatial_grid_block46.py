import os
import subprocess
import pytest

def test_zone_spatial_grid_block46_build():
    """Verify that Block 46 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block46_no_asm():
    """Verify that zero assembly files were generated for Block 46."""
    block46_names = [
        "zone_spatial_grid_clear_active_markers",
        "zone_spatial_grid_insert_marker_node",
        "zone_spatial_grid_mark_bounds_region",
    ]
    for name in block46_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"

def test_zone_spatial_grid_block46_native():
    """Verify behavioral correctness and side effects via native 32-bit test."""
    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block46_test.cpp",
        "src/zone_spatial_grid_clear_active_markers.cpp",
        "src/zone_spatial_grid_insert_marker_node.cpp",
        "src/zone_spatial_grid_mark_bounds_region.cpp",
        "-o", "tests/native/zone_spatial_grid_block46_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"
    run_res = subprocess.run(["./tests/native/zone_spatial_grid_block46_test"], capture_output=True, text=True)
    if os.path.exists("tests/native/zone_spatial_grid_block46_test"):
        os.remove("tests/native/zone_spatial_grid_block46_test")
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
