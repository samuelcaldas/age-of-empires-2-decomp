#include <cassert>
#include <cstring>
#include <iostream>
#include "zone_spatial_entity_set_vertical_velocity.h"

static char g_mock_motion[64];
static int g_alloc_count = 0;

extern "C" {
void *func_1FC3B0() {
    g_alloc_count++;
    std::memset(g_mock_motion, 0, sizeof(g_mock_motion));
    return g_mock_motion;
}
}

struct SpatialEntity {
    char pad[0xBC];
    char *motion_ptr;
};

int main() {
    SpatialEntity entity;
    std::memset(&entity, 0, sizeof(entity));

    // Test 1: val == 0.0f, motion_ptr == 0 -> should not allocate
    func_001DFF00(&entity, 0.0f);
    assert(entity.motion_ptr == 0);
    assert(g_alloc_count == 0);

    // Test 2: val != 0.0f, motion_ptr == 0 -> should allocate and set offset 0x8
    func_001DFF00(&entity, 12.5f);
    assert(entity.motion_ptr == g_mock_motion);
    assert(g_alloc_count == 1);
    assert(*(float *)(entity.motion_ptr + 0x8) == 12.5f);

    // Test 3: val == 0.0f, motion_ptr != 0 -> should not allocate, update offset 0x8
    func_001DFF00(&entity, 0.0f);
    assert(g_alloc_count == 1);
    assert(*(float *)(entity.motion_ptr + 0x8) == 0.0f);

    std::cout << "zone_spatial_entity_set_vertical_velocity_test passed\n";
    return 0;
}
