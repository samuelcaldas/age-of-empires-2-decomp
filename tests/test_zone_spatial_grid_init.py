import subprocess
import os

def test_zone_spatial_grid_init_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_grid_init_test.cpp",
        "src/zone_spatial_entity_stub_1e3830.cpp",
        "src/zone_spatial_entity_identity_getter.cpp",
        "src/zone_spatial_grid_init_node_buffer.cpp",
        "-o", "/tmp/zone_spatial_grid_init_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_grid_init_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_grid_init_test"):
        os.remove("/tmp/zone_spatial_grid_init_test")
