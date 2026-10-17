import subprocess
import os

def test_zone_spatial_entity_motion_scale_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_entity_motion_scale_test.cpp",
        "src/zone_spatial_entity_has_positive_velocity.cpp",
        "src/zone_spatial_entity_reset_motion_state.cpp",
        "src/zone_spatial_entity_set_motion_scale.cpp",
        "src/zone_spatial_entity_get_state_id.cpp",
        "-o", "/tmp/zone_spatial_entity_motion_scale_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_entity_motion_scale_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_entity_motion_scale_test"):
        os.remove("/tmp/zone_spatial_entity_motion_scale_test")
