import os
import subprocess
import pytest

@pytest.mark.build
def test_zone_spatial_grid_block40_build():
    """Verify that Block 40 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block40_no_asm():
    """Verify that zero assembly files were generated for Block 40."""
    block40_names = [
        "zone_spatial_grid_query_ray_cell",
        "zone_spatial_grid_filter_intersecting_obstacles",
        "zone_spatial_grid_link_header_init",
        "zone_spatial_grid_link_header_destructor",
        "zone_spatial_grid_link_header_clear",
    ]
    for name in block40_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
