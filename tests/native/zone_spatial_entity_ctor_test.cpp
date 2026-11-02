#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_ctor.h"

static int g_151a80_called = 0;
static int g_26ad60_called = 0;
static int g_1e3710_called = 0;
static int g_1dc180_called = 0;
static int g_mask_flags = 0;
static float g_last_x = 0.0f;
static float g_last_y = 0.0f;
static float g_last_z = 0.0f;

extern "C" {
void func_151A80(void *self, int a1, int a2, int flag) {
    g_151a80_called++;
}

void func_26AD60(void *self, int mask) {
    g_26ad60_called++;
    g_mask_flags |= mask;
}

void func_1E3710(void *self) {
    g_1e3710_called++;
}

void func_1DC180(void *self, int a1, int a2, float x, float y, float z) {
    g_1dc180_called++;
    g_last_x = x;
    g_last_y = y;
    g_last_z = z;
}
}

#include "../../src/zone/zone_spatial_entity_ctor.cpp"

int main() {
    SpatialEntity entity;
    memset(&entity, 0xBB, sizeof(entity));

    // Call with flag = 0
    func_001DBEA0(&entity, 11, 22, 0, 1.0f, 2.0f, 3.0f);

    assert(g_151a80_called == 1);
    assert(g_26ad60_called == 2);
    assert((g_mask_flags & 0x40) != 0);
    assert((g_mask_flags & 0x20) != 0);
    assert(g_1e3710_called == 1);
    assert(g_1dc180_called == 0);

    assert(entity.f6C == 0);
    assert(entity.f70 == 0);
    assert(entity.f74 == 0);
    assert(entity.f78 == 0);
    assert(entity.f7C == 0);
    assert(entity.f80 == 0);
    assert(entity.f84 == 0);
    assert(entity.f88 == 0);
    assert(entity.fC4 == 0);
    assert(entity.f98 == 0);
    assert(entity.f94 == 0);
    assert(entity.f90 == 0);
    assert(entity.f9C == 1.0f);
    assert(entity.fA4 == 0);
    assert(entity.fA0 == 0);
    assert(entity.fAC == 0);
    assert(entity.fA8 == 0);
    assert(entity.fB0 == -1.0f);
    assert(entity.fB4 == 0);
    assert(entity.fB8 == 0);
    assert(entity.fBC == 0);
    assert(entity.fC0 == 0);

    // Call with flag != 0
    func_001DBEA0(&entity, 11, 22, 1, 4.0f, 5.0f, 6.0f);
    assert(g_1dc180_called == 1);
    assert(g_last_x == 4.0f);
    assert(g_last_y == 5.0f);
    assert(g_last_z == 6.0f);

    printf("zone_spatial_entity_ctor_test passed\n");
    return 0;
}
