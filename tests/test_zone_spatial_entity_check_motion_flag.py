"""Behavioral tests for zone_spatial_entity_check_motion_flag (func_001E3600)."""

import os
import subprocess
import pytest

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def test_zone_spatial_entity_check_motion_flag_native(tmp_path):
    test_src = """
#include <cassert>
#include "zone_spatial_entity_check_motion_flag.h"

unsigned int D_00492600 = 0x20;

struct SubEntity2 {
    char pad[0x18];
    unsigned int flags;
};

struct SubEntity {
    char pad[0x8];
    SubEntity2 *sub2;
};

struct SpatialEntity {
    char pad[0xB4];
    SubEntity *sub;
};

int main() {
    SpatialEntity entity;
    for (unsigned int i = 0; i < sizeof(entity); i++) ((char *)&entity)[i] = 0;

    // Test 1: Null sub pointer -> 0
    entity.sub = 0;
    assert(func_001E3600(&entity) == 0);

    // Test 2: Null sub2 pointer -> 0
    SubEntity sub;
    for (unsigned int i = 0; i < sizeof(sub); i++) ((char *)&sub)[i] = 0;
    entity.sub = &sub;
    sub.sub2 = 0;
    assert(func_001E3600(&entity) == 0);

    // Test 3: Matching flag not set -> 0
    SubEntity2 sub2;
    for (unsigned int i = 0; i < sizeof(sub2); i++) ((char *)&sub2)[i] = 0;
    sub.sub2 = &sub2;
    sub2.flags = 0x10;
    assert(func_001E3600(&entity) == 0);

    // Test 4: Matching flag set -> 1
    sub2.flags = 0x20;
    assert(func_001E3600(&entity) == 1);

    // Test 5: Multiple flags with match -> 1
    sub2.flags = 0xFF;
    assert(func_001E3600(&entity) == 1);

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
        os.path.join(PROJECT_ROOT, "src/zone/zone_spatial_entity_check_motion_flag.cpp"),
        "-o", str(bin_path)
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
