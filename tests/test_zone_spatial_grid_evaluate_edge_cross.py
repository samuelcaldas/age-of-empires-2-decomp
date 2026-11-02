import subprocess
import pytest

def test_zone_spatial_grid_evaluate_edge_cross_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_grid_evaluate_edge_cross_test.cpp",
        "src/zone/zone_spatial_grid_evaluate_edge_cross.cpp",
        "-o", "/tmp/zone_spatial_grid_evaluate_edge_cross_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run(["/tmp/zone_spatial_grid_evaluate_edge_cross_test"], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
