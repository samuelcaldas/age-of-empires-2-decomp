import os
import subprocess
import pytest

@pytest.mark.build
def test_zone_spatial_grid_block55_build():
    """Verify that Block 55 objects build and link without errors."""
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"

def test_zone_spatial_grid_block55_no_asm():
    """Verify that zero assembly files were generated for Block 55."""
    block55_names = [
        "zone_spatial_grid_eval_node_hit",
        "zone_spatial_grid_eval_edge_hit",
    ]
    for name in block55_names:
        asm_path = f"asm/SLES-50282/main/{name}.s"
        assert not os.path.exists(asm_path), f"Assembly file exists: {asm_path}"

def test_zone_spatial_grid_block55_native():
    """Verify behavioral correctness and side effects via native 32-bit test."""
    cmd = [
        "g++", "-m32", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block55_test.cpp",
        "src/zone/zone_spatial_grid_eval_node_hit.cpp",
        "src/zone/zone_spatial_grid_eval_edge_hit.cpp",
        "-o", "tests/native/zone_spatial_grid_block55_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"
    run_res = subprocess.run(["./tests/native/zone_spatial_grid_block55_test"], capture_output=True, text=True)
    if os.path.exists("tests/native/zone_spatial_grid_block55_test"):
        os.remove("tests/native/zone_spatial_grid_block55_test")
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
