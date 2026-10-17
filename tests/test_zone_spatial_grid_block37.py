import os
import subprocess
import pytest

def test_zone_spatial_grid_block37_build():
    """Verify that Block 37 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block37_no_asm():
    """Verify that zero assembly files were generated for Block 37."""
    block37_names = [
        "zone_spatial_grid_vector_destructor",
        "zone_spatial_grid_vector_init",
        "zone_spatial_grid_vector_reset",
        "zone_spatial_grid_vector_is_full",
        "zone_spatial_grid_vector_clear",
        "zone_spatial_grid_vector_push_back",
        "zone_spatial_grid_vector_swap_remove",
    ]
    for name in block37_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
