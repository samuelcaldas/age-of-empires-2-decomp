import subprocess
import os

def test_zone_spatial_entity_waypoint_buffer_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_entity_waypoint_buffer_test.cpp",
        "src/zone/zone_spatial_entity_alloc_waypoint_buffer.cpp",
        "src/zone/zone_spatial_entity_free_waypoint_buffer.cpp",
        "-o", "/tmp/zone_spatial_entity_waypoint_buffer_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_entity_waypoint_buffer_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_entity_waypoint_buffer_test"):
        os.remove("/tmp/zone_spatial_entity_waypoint_buffer_test")
