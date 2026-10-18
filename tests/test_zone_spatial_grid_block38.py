import os
import subprocess
import pytest

def test_zone_spatial_grid_block38_build():
    """Verify that Block 38 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block38_no_asm():
    """Verify that zero assembly files were generated for Block 38."""
    block38_names = [
        "zone_spatial_grid_deserialize_node_stream",
        "zone_spatial_grid_deserialize_entity_factory",
        "zone_spatial_grid_serialize_vector",
        "zone_spatial_grid_vector_update_elements",
        "zone_spatial_grid_vector_purge_inactive_elements",
    ]
    for name in block38_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"
