// Tests for func_277450 — Milestone 103 (848B)
// Verifies ActionBuild elevation and raycast line-of-sight traversal.
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "unit_action_build_7450.h"

static int g_tile_check_calls = 0;
static int g_counter_delta = 0;
static int g_check_fn_return = 0;

extern "C" int func_123350(float val) {
    return (int)std::round(val);
}

extern "C" int func_114308(int val) {
    return std::abs(val);
}

static int mock_tile_check(void *, void *, int, int,
                           float, float, float, float,
                           void *, void *, float *, int *counter) {
    g_tile_check_calls++;
    *counter += g_counter_delta;
    return g_check_fn_return;
}

static void test_elevation_clearance() {
    unsigned char self[256], target[256];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));

    float sz = 5.0f, tz = 10.0f; // self->z <= target->z
    std::memcpy(self + 0x4C, &sz, sizeof(float));
    std::memcpy(target + 0x4C, &tz, sizeof(float));

    assert(func_277450(self, target) == 1);
    printf("PASS test_elevation_clearance\n");
}

static void test_zero_delta() {
    unsigned char self[256], target[256];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));

    float sz = 15.0f, tz = 10.0f; // self->z > target->z
    std::memcpy(self + 0x4C, &sz, sizeof(float));
    std::memcpy(target + 0x4C, &tz, sizeof(float));

    float pos = 5.0f;
    std::memcpy(self + 0x44, &pos, sizeof(float));
    std::memcpy(self + 0x48, &pos, sizeof(float));
    std::memcpy(target + 0x44, &pos, sizeof(float));
    std::memcpy(target + 0x48, &pos, sizeof(float));

    assert(func_277450(self, target) == 0);
    printf("PASS test_zero_delta\n");
}

static void test_raycast_pass() {
    unsigned char self[512], target[256], owner[0x2000], world[512], map[256];
    void *vtbl[256];
    std::memset(self, 0, sizeof(self));
    std::memset(target, 0, sizeof(target));
    std::memset(owner, 0, sizeof(owner));
    std::memset(world, 0, sizeof(world));
    std::memset(map, 0, sizeof(map));
    std::memset(vtbl, 0, sizeof(vtbl));

    vtbl[217] = (void *)mock_tile_check;
    void *vtbl_ptr = vtbl;
    std::memcpy(self, &vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
    void *world_ptr = world;
    void *map_ptr = map;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0x1730, &world_ptr, sizeof(void *));
    std::memcpy(world + 0x78, &map_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(owner + 0xB98, &world_ptr, sizeof(void *));
    std::memcpy(world + 0x3C, &map_ptr, sizeof(void *));
#endif

    float sz = 15.0f, tz = 10.0f;
    std::memcpy(self + 0x4C, &sz, sizeof(float));
    std::memcpy(target + 0x4C, &tz, sizeof(float));

    float sx = 0.0f, sy = 0.0f;
    float tx = 10.0f, ty = 10.0f;
    std::memcpy(self + 0x44, &sx, sizeof(float));
    std::memcpy(self + 0x48, &sy, sizeof(float));
    std::memcpy(target + 0x44, &tx, sizeof(float));
    std::memcpy(target + 0x48, &ty, sizeof(float));

    g_tile_check_calls = 0;
    g_counter_delta = 1;
    g_check_fn_return = 1;

    int ret = func_277450(self, target);
    assert(ret == 1);
    assert(g_tile_check_calls > 0);
    printf("PASS test_raycast_pass\n");
}

int main() {
    test_elevation_clearance();
    test_zero_delta();
    test_raycast_pass();
    printf("All unit_action_build_7450 tests passed!\n");
    return 0;
}
