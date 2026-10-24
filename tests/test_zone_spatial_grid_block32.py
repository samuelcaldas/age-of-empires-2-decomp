import os
import subprocess
import pytest

@pytest.mark.build
def test_zone_spatial_grid_block32_build():
    """Verify that Block 32 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block32_no_asm():
    """Verify that zero assembly files were generated for Block 32."""
    block32_names = [
        "zone_spatial_grid_trace_grid_ray",
        "zone_spatial_grid_reset_bounding_indices",
    ]
    for name in block32_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
