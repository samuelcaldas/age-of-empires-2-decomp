import os
import subprocess
import pytest

@pytest.mark.build
def test_zone_spatial_grid_block39_build():
    """Verify that Block 39 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block39_no_asm():
    """Verify that zero assembly files were generated for Block 39."""
    block39_names = [
        "zone_spatial_grid_search_nearest_cell",
        "zone_spatial_grid_query_ray_intersection",
        "zone_spatial_grid_vector_find_by_id",
    ]
    for name in block39_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
