import os
import subprocess
import pytest

def test_zone_spatial_grid_block27_build():
    """Verify that Block 27 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block27_no_asm():
    """Verify that zero assembly files were generated for Block 27."""
    block27_names = [
        "zone_spatial_grid_reset_destructor",
        "zone_spatial_grid_init_node",
        "zone_spatial_grid_free_buffers",
        "zone_spatial_grid_init_pyramid",
        "zone_spatial_grid_leaf_helper",
        "zone_spatial_grid_reset_pyramid",
        "zone_spatial_grid_realloc_vector",
        "zone_spatial_grid_transfer_bucket",
    ]
    for name in block27_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
