import os
import subprocess
import pytest

def test_zone_spatial_grid_block41_build():
    """Verify that Block 41 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block41_no_asm():
    """Verify that zero assembly files were generated for Block 41."""
    block41_names = [
        "zone_spatial_grid_link_header_remove",
        "zone_spatial_grid_link_header_prepend",
        "zone_spatial_grid_buffer_manager_init",
        "zone_spatial_grid_buffer_manager_destructor",
        "zone_spatial_grid_buffer_manager_setup",
        "zone_spatial_grid_buffer_manager_insert",
    ]
    for name in block41_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
