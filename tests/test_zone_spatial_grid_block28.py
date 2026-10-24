import os
import subprocess
import pytest

@pytest.mark.build
def test_zone_spatial_grid_block28_build():
    """Verify that Block 28 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block28_no_asm():
    """Verify that zero assembly files were generated for Block 28."""
    block28_names = [
        "zone_spatial_grid_compact_bucket",
        "zone_spatial_grid_mark_tile_occupants",
        "zone_spatial_grid_push_buffer1",
        "zone_spatial_grid_expand_buffer2",
        "zone_spatial_grid_expand_buffer3",
        "zone_spatial_grid_set_margin_bounds",
        "zone_spatial_grid_test_point_in_bounds",
        "zone_spatial_grid_set_field10",
    ]
    for name in block28_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
