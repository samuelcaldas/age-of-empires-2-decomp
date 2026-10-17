import os
import subprocess
import pytest

def test_zone_spatial_grid_block33_build():
    """Verify that Block 33 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block33_no_asm():
    """Verify that zero assembly files were generated for Block 33."""
    block33_names = [
        "zone_spatial_grid_execute_hierarchical_query",
    ]
    for name in block33_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
