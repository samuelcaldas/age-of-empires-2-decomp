#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_entity_ctor_simple.h"

static int g_151b20_called = 0;
static int g_26ad60_called = 0;
static int g_1e3710_called = 0;
static int g_1dc2e0_called = 0;
static int g_mask_flags = 0;

extern "C" {
void func_151B20(void *self, int a1, int a2, int a3) {
    g_151b20_called++;
}

void func_26AD60(void *self, int mask) {
    g_26ad60_called++;
    g_mask_flags |= mask;
}

void func_1E3710(void *self) {
    g_1e3710_called++;
}

void func_1DC2E0(void *self, int a1, int a2) {
    g_1dc2e0_called++;
}
}

#include "../../src/zone/zone_spatial_entity_ctor_simple.cpp"

int main() {
    SpatialEntity entity;
    memset(&entity, 0xAA, sizeof(entity));

    // Call with flag = 0
    func_001DBFC0(&entity, 10, 20, 0);

    assert(g_151b20_called == 1);
    assert(g_26ad60_called == 2);
    assert((g_mask_flags & 0x40) != 0);
    assert((g_mask_flags & 0x20) != 0);
    assert(g_1e3710_called == 1);
    assert(g_1dc2e0_called == 0);

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
    func_001DBFC0(&entity, 10, 20, 1);
    assert(g_1dc2e0_called == 1);

    printf("zone_spatial_entity_ctor_simple_test passed\n");
    return 0;
}
