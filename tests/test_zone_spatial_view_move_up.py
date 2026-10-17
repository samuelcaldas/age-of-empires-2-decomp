import subprocess
import os

def test_zone_spatial_view_move_up_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_spatial_view_move_up_test.cpp",
        "src/zone_spatial_view_move_up.cpp",
        "-o", "/tmp/zone_spatial_view_move_up_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_spatial_view_move_up_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_spatial_view_move_up_test"):
        os.remove("/tmp/zone_spatial_view_move_up_test")
