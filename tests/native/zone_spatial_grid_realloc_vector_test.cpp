#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_grid_realloc_vector.h"

static int g_1e67a0_called = 0;
static int g_100730_called = 0;
static int g_100630_called = 0;

static void *g_mock_allocated[100];

extern "C" {
void func_1E67A0(void *self, int flag) {
    g_1e67a0_called++;
}

void* func_100730(unsigned int size) {
    g_100730_called++;
    return g_mock_allocated;
}

void func_100630(void *ptr) {
    g_100630_called++;
}
}

#include "../../src/zone/zone_spatial_grid_realloc_vector.cpp"

int main() {
    SpatialGrid grid;
    memset(&grid, 0, sizeof(grid));

    void *orig_items[10] = { (void*)1, (void*)2, (void*)3 };
    grid.items = orig_items;
    grid.count = 3;
    grid.capacity = 10;

    // Test case 1: capacity >= 0 (no reallocation needed)
    func_001E6680(&grid);
    assert(g_1e67a0_called == 2);
    // items should be zeroed
    assert(orig_items[0] == 0);
    assert(orig_items[1] == 0);
    assert(orig_items[2] == 0);
    assert(g_100730_called == 0);

    // Test case 2: capacity < 0 (needs reallocation)
    orig_items[0] = (void*)0xAAA;
    orig_items[1] = (void*)0xBBB;
    grid.items = orig_items;
    grid.count = 2;
    grid.capacity = -5;

    func_001E6680(&grid);
    assert(g_1e67a0_called == 4);
    assert(g_100730_called == 1);
    assert(g_100630_called == 1);
    assert(grid.items == g_mock_allocated);
    assert(grid.count == 0);

    printf("zone_spatial_grid_realloc_vector_test passed\n");
    return 0;
}
