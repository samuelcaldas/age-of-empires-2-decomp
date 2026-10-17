import subprocess
import os

def test_zone_spatial_grid_edges_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_grid_edges_test.cpp",
        "src/zone_spatial_grid_dispatch_edge_north.cpp",
        "src/zone_spatial_grid_dispatch_edge_east.cpp",
        "src/zone_spatial_grid_dispatch_edge_south.cpp",
        "src/zone_spatial_grid_dispatch_edge_west.cpp",
        "-o", "/tmp/zone_spatial_grid_edges_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_grid_edges_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_grid_edges_test"):
        os.remove("/tmp/zone_spatial_grid_edges_test")
