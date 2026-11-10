import os
import subprocess
import pytest

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def test_zone_perimeter_point_native(tmp_path):
    test_src = """
#include <cassert>
#include "zone_perimeter_point.h"

int main() {
    short buffer[32];
    for (int i = 0; i < 32; i++) buffer[i] = 0;
    buffer[0] = 0; // count
    buffer[1] = 5; // capacity

    // Add first point (dx=1, dy=2)
    func_001CAC00(0, buffer, 1, 2);
    assert(buffer[0] == 1);
    assert(buffer[2] == 1);
    assert(buffer[3] == 2);

    // Add duplicate point - should not add
    func_001CAC00(0, buffer, 1, 2);
    assert(buffer[0] == 1);

    // Add dx=0, dy=0 - should not add
    func_001CAC00(0, buffer, 0, 0);
    assert(buffer[0] == 1);

    // Add null buffer - no crash
    func_001CAC00(0, 0, 3, 4);

    // Add second point
    func_001CAC00(0, buffer, 3, 4);
    assert(buffer[0] == 2);
    assert(buffer[4] == 3);
    assert(buffer[5] == 4);

    return 0;
}
"""
    native_cpp = tmp_path / "test.cpp"
    native_cpp.write_text(test_src)
    bin_path = tmp_path / "test_bin"

    cmd = [
        "g++", "-m32", "-O2",
        f"-I{os.path.join(PROJECT_ROOT, 'include')}",
        str(native_cpp),
        os.path.join(PROJECT_ROOT, "src/zone/zone_perimeter_point.cpp"),
        "-o", str(bin_path)
    ]
    subprocess.run(cmd, check=True)
    subprocess.run([str(bin_path)], check=True)
