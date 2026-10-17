import subprocess
import os

def test_zone_spatial_entity_occupants_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_entity_occupants_test.cpp",
        "src/zone_spatial_entity_resolve_world_node.cpp",
        "src/zone_spatial_entity_query_spatial_cell.cpp",
        "-o", "/tmp/zone_spatial_entity_occupants_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_entity_occupants_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_entity_occupants_test"):
        os.remove("/tmp/zone_spatial_entity_occupants_test")
