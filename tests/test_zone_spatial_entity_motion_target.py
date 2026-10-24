import subprocess
import os

def test_zone_spatial_entity_motion_target_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_entity_motion_target_test.cpp",
        "src/zone/zone_spatial_entity_finalize_motion_step.cpp",
        "src/zone/zone_spatial_entity_get_velocity_vector.cpp",
        "-o", "/tmp/zone_spatial_entity_motion_target_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_entity_motion_target_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_entity_motion_target_test"):
        os.remove("/tmp/zone_spatial_entity_motion_target_test")
