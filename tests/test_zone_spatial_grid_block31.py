import os
import subprocess
import pytest

def test_zone_spatial_grid_block31_build():
    """Verify that Block 31 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block31_no_asm():
    """Verify that zero assembly files were generated for Block 31."""
    block31_names = [
        "zone_spatial_grid_test_sphere_obstacles",
        "zone_spatial_grid_transfer_to_subcontainer",
        "zone_spatial_grid_find_nearest_quad_intersection",
    ]
    for name in block31_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
