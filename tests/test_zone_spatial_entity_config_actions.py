import subprocess
import os

def test_zone_spatial_entity_config_actions_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_entity_config_actions_test.cpp",
        "src/zone/zone_spatial_entity_check_motion_flag.cpp",
        "src/zone/zone_spatial_entity_dispatch_config_action_ac.cpp",
        "src/zone/zone_spatial_entity_dispatch_config_action_a8.cpp",
        "src/zone/zone_spatial_entity_dispatch_config_action_10.cpp",
        "-o", "/tmp/zone_spatial_entity_config_actions_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_entity_config_actions_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_entity_config_actions_test"):
        os.remove("/tmp/zone_spatial_entity_config_actions_test")
