import os
import subprocess
import pytest

def test_zone_spatial_grid_block36_build():
    """Verify that Block 36 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block36_no_asm():
    """Verify that zero assembly files were generated for Block 36."""
    block36_names = [
        "zone_spatial_grid_deserialize_child_polymorphic",
        "zone_spatial_grid_format_path_string",
        "zone_spatial_grid_set_string",
        "zone_spatial_grid_reset_scratch_counter",
        "zone_spatial_grid_alloc_scratch_bytes",
        "zone_spatial_grid_init_entry_header",
    ]
    for name in block36_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
