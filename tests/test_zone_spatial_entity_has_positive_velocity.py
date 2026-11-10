"""Behavioral tests for zone_spatial_entity_has_positive_velocity (func_001E0280)."""

import os
import subprocess
import pytest

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def test_zone_spatial_entity_has_positive_velocity_native(tmp_path):
    test_src = """
#include <cassert>
#include "zone_spatial_entity_has_positive_velocity.h"

struct Vector3 {
    float x;
    float y;
    float z;
};

struct SpatialEntity {
    char pad[0xBC];
    Vector3 *vel_vec;
};

int main() {
    SpatialEntity entity;
    for (unsigned int i = 0; i < sizeof(entity); i++) ((char *)&entity)[i] = 0;

    // Test 1: Null velocity pointer returns 0
    entity.vel_vec = 0;
    assert(func_001E0280(&entity) == 0);

    // Test 2: Zero velocity returns 0
    Vector3 zero_vel;
    zero_vel.x = 0.0f; zero_vel.y = 0.0f; zero_vel.z = 0.0f;
    entity.vel_vec = &zero_vel;
    assert(func_001E0280(&entity) == 0);

    // Test 3: Positive velocity returns 1
    Vector3 pos_vel;
    pos_vel.x = 1.0f; pos_vel.y = 0.0f; pos_vel.z = 0.0f;
    entity.vel_vec = &pos_vel;
    assert(func_001E0280(&entity) == 1);

    // Test 4: Negative component still has positive magnitude squared > 0
    Vector3 neg_vel;
    neg_vel.x = 0.0f; neg_vel.y = -2.0f; neg_vel.z = 0.0f;
    entity.vel_vec = &neg_vel;
    assert(func_001E0280(&entity) == 1);

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
        os.path.join(PROJECT_ROOT, "src/zone/zone_spatial_entity_has_positive_velocity.cpp"),
        "-o", str(bin_path)
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
