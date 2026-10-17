import subprocess
import os

def test_zone_cursor_controller_display_native():
    cmd = [
        "g++", "-m32", "-O2",
        "-Iinclude",
        "tests/native/zone_cursor_controller_display_test.cpp",
        "src/zone_cursor_controller_hide_cursor.cpp",
        "src/zone_cursor_controller_show_cursor.cpp",
        "src/zone_cursor_controller_init_display_res.cpp",
        "src/zone_cursor_controller_reset_global.cpp",
        "-o", "/tmp/zone_cursor_controller_display_test"
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"
    res_run = subprocess.run(["/tmp/zone_cursor_controller_display_test"], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
    if os.path.exists("/tmp/zone_cursor_controller_display_test"):
        os.remove("/tmp/zone_cursor_controller_display_test")
