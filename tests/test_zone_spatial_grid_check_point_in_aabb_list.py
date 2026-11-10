import os
import subprocess
import pytest

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def test_zone_spatial_grid_check_point_in_aabb_list_native(tmp_path):
    test_src = """
#include <cassert>
#include "zone_spatial_grid_check_point_in_aabb_list.h"

struct AABB {
    float min_x;
    float min_y;
    float max_x;
    float max_y;
    float z;
};

struct Point2D {
    float x;
    float y;
};

struct AABBList {
    char pad[0x20];
    int count;
    char pad2[0x4];
    AABB *items;
};

int main() {
    AABB boxes[2];
    boxes[0].min_x = 0.0f; boxes[0].min_y = 0.0f; boxes[0].max_x = 10.0f; boxes[0].max_y = 10.0f; boxes[0].z = 0.0f;
    boxes[1].min_x = 20.0f; boxes[1].min_y = 20.0f; boxes[1].max_x = 30.0f; boxes[1].max_y = 30.0f; boxes[1].z = 0.0f;

    AABBList list;
    for (unsigned int i = 0; i < sizeof(list); i++) ((char *)&list)[i] = 0;
    list.count = 2;
    list.items = boxes;

    Point2D p_in; p_in.x = 5.0f; p_in.y = 5.0f;
    assert(func_001E6140(&list, &p_in) == 1);

    Point2D p_out; p_out.x = 15.0f; p_out.y = 15.0f;
    assert(func_001E6140(&list, &p_out) == 0);
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
        os.path.join(PROJECT_ROOT, "src/zone/zone_spatial_grid_check_point_in_aabb_list.cpp"),
        "-o", str(bin_path)
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
