import os
import subprocess
import pytest

def test_zone_spatial_grid_block35_build():
    """Verify that Block 35 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block35_no_asm():
    """Verify that zero assembly files were generated for Block 35."""
    block35_names = [
        "zone_spatial_grid_destroy_static_node_pool",
        "zone_spatial_grid_deserialize_node_array",
        "zone_spatial_grid_free_node_array",
        "zone_spatial_grid_deserialize_child_entries",
    ]
    for name in block35_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
