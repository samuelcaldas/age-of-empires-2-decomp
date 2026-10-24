import os
import subprocess
import pytest

def test_zone_spatial_grid_block48_build():
    """Verify that Block 48 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block48_no_asm():
    """Verify that zero assembly files were generated for Block 48."""
    block48_names = [
        "zone_spatial_grid_clear_entity_markers",
        "zone_spatial_grid_remove_node",
        "zone_spatial_grid_set_obstacle_array",
        "zone_spatial_grid_set_query_params",
        "zone_spatial_grid_set_collision_margin",
    ]
    for name in block48_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"

def test_zone_spatial_grid_block48_native():
    """Verify behavioral correctness and side effects via native 32-bit test."""
    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block48_test.cpp",
        "src/zone/zone_spatial_grid_clear_entity_markers.cpp",
        "src/zone/zone_spatial_grid_remove_node.cpp",
        "src/zone/zone_spatial_grid_set_obstacle_array.cpp",
        "src/zone/zone_spatial_grid_set_query_params.cpp",
        "src/zone/zone_spatial_grid_set_collision_margin.cpp",
        "-o", "tests/native/zone_spatial_grid_block48_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"
    run_res = subprocess.run(["./tests/native/zone_spatial_grid_block48_test"], capture_output=True, text=True)
    if os.path.exists("tests/native/zone_spatial_grid_block48_test"):
        os.remove("tests/native/zone_spatial_grid_block48_test")
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
