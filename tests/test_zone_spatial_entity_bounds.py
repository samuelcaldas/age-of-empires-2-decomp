import subprocess
import os

def test_zone_spatial_entity_bounds_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_entity_bounds_test.cpp",
        "src/zone/zone_spatial_entity_update_velocity_threshold.cpp",
        "src/zone/zone_spatial_entity_dispatch_registration.cpp",
        "-o", "/tmp/zone_spatial_entity_bounds_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_entity_bounds_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_entity_bounds_test"):
        os.remove("/tmp/zone_spatial_entity_bounds_test")
