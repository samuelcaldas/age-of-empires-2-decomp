import os
import subprocess
import pytest

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def test_zone_spatial_grid_expand_buffer2_native(tmp_path):
    test_src = """
#include <cassert>
#include <cstring>
#include "zone_spatial_grid_expand_buffer2.h"

extern "C" void *func_117CAC(void *dst, int val, unsigned int size) {
    return std::memset(dst, val, size);
}

struct SpatialGrid {
    char pad_8[0x8];
    int cap8;
    void **bufC;
    char pad_1CC[0x1BC];
    char embedded_buffer2[0x400];
};

int main() {
    SpatialGrid grid;
    std::memset(&grid, 0xAA, sizeof(grid));
    grid.cap8 = 0;
    grid.bufC = 0;

    // Expand to 0x100 (which is the embedded buffer threshold)
    func_001E6F60(&grid, 0x100);
    assert(grid.cap8 == 0x100);
    assert(grid.bufC == (void **)&grid.embedded_buffer2[0]);
    assert(grid.embedded_buffer2[0] == 0);
    assert(grid.embedded_buffer2[0x3FF] == 0);

    // Call with needed < cap8 -> no op
    func_001E6F60(&grid, 0x50);
    assert(grid.cap8 == 0x100);

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
        os.path.join(PROJECT_ROOT, "src/zone/zone_spatial_grid_expand_buffer2.cpp"),
        "-o", str(bin_path)
    ]
    subprocess.run(cmd, check=True)
    subprocess.run([str(bin_path)], check=True)
