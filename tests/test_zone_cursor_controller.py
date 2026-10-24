import subprocess
import os

def test_zone_cursor_controller_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_cursor_controller_test.cpp",
        "src/zone/zone_cursor_controller_set_field_2c.cpp",
        "src/zone/zone_cursor_controller_set_field_30.cpp",
        "src/zone/zone_cursor_controller_get_field_30.cpp",
        "src/zone/zone_cursor_controller_set_bounds.cpp",
        "src/zone/zone_cursor_controller_is_active.cpp",
        "-o", "/tmp/zone_cursor_controller_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_cursor_controller_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_cursor_controller_test"):
        os.remove("/tmp/zone_cursor_controller_test")
