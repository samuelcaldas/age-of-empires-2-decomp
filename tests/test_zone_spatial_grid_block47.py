import os
import subprocess
import pytest

@pytest.mark.build
def test_zone_spatial_grid_block47_build():
    """Verify that Block 47 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block47_no_asm():
    """Verify that zero assembly files were generated for Block 47."""
    block47_names = [
        "zone_spatial_grid_compute_terrain_mask",
        "zone_spatial_grid_stamp_obstacle_region",
        "zone_spatial_grid_clear_obstacle_region",
        "zone_spatial_grid_set_obstacle_callback",
    ]
    for name in block47_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"

def test_zone_spatial_grid_block47_native():
    """Verify behavioral correctness and side effects via native 32-bit test."""
    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block47_test.cpp",
        "src/zone/zone_spatial_grid_compute_terrain_mask.cpp",
        "src/zone/zone_spatial_grid_stamp_obstacle_region.cpp",
        "src/zone/zone_spatial_grid_clear_obstacle_region.cpp",
        "src/zone/zone_spatial_grid_set_obstacle_callback.cpp",
        "-o", "tests/native/zone_spatial_grid_block47_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"
    run_res = subprocess.run(["./tests/native/zone_spatial_grid_block47_test"], capture_output=True, text=True)
    if os.path.exists("tests/native/zone_spatial_grid_block47_test"):
        os.remove("tests/native/zone_spatial_grid_block47_test")
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
