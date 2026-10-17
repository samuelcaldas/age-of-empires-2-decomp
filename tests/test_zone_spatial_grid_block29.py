import os
import subprocess
import pytest

def test_zone_spatial_grid_block29_build():
    """Verify that Block 29 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block29_no_asm():
    """Verify that zero assembly files were generated for Block 29."""
    block29_names = [
        "zone_spatial_grid_query_bounded_area",
        "zone_spatial_grid_scan_ring_perimeter",
        "zone_spatial_grid_partition_area_query",
        "zone_spatial_grid_filter_terrain_obstacle",
    ]
    for name in block29_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
