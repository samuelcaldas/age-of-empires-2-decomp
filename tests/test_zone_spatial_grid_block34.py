import os
import subprocess
import pytest

def test_zone_spatial_grid_block34_build():
    """Verify that Block 34 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block34_no_asm():
    """Verify that zero assembly files were generated for Block 34."""
    block34_names = [
        "zone_spatial_grid_find_spatial_path",
        "zone_spatial_grid_smooth_path_waypoints",
        "zone_spatial_grid_clear_table_b4_flags",
        "zone_spatial_grid_clear_table_b8_flags",
    ]
    for name in block34_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
