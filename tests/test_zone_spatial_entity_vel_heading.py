import subprocess
import os

def test_zone_spatial_entity_vel_heading_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_entity_vel_heading_test.cpp",
        "src/zone_spatial_entity_set_velocity.cpp",
        "src/zone_spatial_entity_set_heading.cpp",
        "-o", "/tmp/zone_spatial_entity_vel_heading_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_entity_vel_heading_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_entity_vel_heading_test"):
        os.remove("/tmp/zone_spatial_entity_vel_heading_test")
