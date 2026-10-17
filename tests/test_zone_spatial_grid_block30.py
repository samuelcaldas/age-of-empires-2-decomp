import os
import subprocess
import pytest

def test_zone_spatial_grid_block30_build():
    """Verify that Block 30 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block30_no_asm():
    """Verify that zero assembly files were generated for Block 30."""
    block30_names = [
        "zone_spatial_grid_collect_bucket_entities",
        "zone_spatial_grid_clip_and_insert_quad",
        "zone_spatial_grid_allocate_node",
    ]
    for name in block30_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
