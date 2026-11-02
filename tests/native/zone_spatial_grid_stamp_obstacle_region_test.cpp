#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_grid_stamp_obstacle_region.h"

static int g_callback_called = 0;
static void* g_callback_ctx = NULL;

static void mock_obstacle_callback(void *ctx) {
    g_callback_called++;
    g_callback_ctx = ctx;
}

#include "../../src/zone/zone_spatial_grid_stamp_obstacle_region.cpp"

int main() {
    SpatialGrid grid;
    memset(&grid, 0, sizeof(grid));

    int row0[10] = { 0x05, 0x06, 0x07 };
    int row1[10] = { 0x11, 0x12, 0x13 };
    int *table[2] = { row0, row1 };

    grid.grid_table = table;
    grid.callback_fn = mock_obstacle_callback;
    grid.callback_ctx = (void*)0xFEED;

    // Stamp type = 2, id = 3 over [0, 0] to [1, 1]
    int ret = func_001EE5B0(&grid, 0, 0, 1, 1, 2, 3);
    assert(ret == 1);
    assert(g_callback_called == 1);
    assert(g_callback_ctx == (void*)0xFEED);

    // val = ((2 << 8) & 0x3F00) | 0x4000 | (3 << 16)
    // val = 0x0200 | 0x4000 | 0x00030000 = 0x00034200
    // row0[0] low byte preserved: 0x00034205
    assert(row0[0] == 0x00034205);
    assert(row0[1] == 0x00034206);
    assert(row1[0] == 0x00034211);
    assert(row1[1] == 0x00034212);

    // Test with type = 5 (checks 0x8000 flag addition)
    func_001EE5B0(&grid, 0, 0, 0, 0, 5, 1);
    // val = ((5 << 8) & 0x3F00) | 0x4000 | (1 << 16) | 0x8000
    // val = 0x0500 | 0x4000 | 0x00010000 | 0x8000 = 0x0001C500
    // row0[0] low byte was 0x05: 0x0001C505
    assert(row0[0] == 0x0001C505);

    printf("zone_spatial_grid_stamp_obstacle_region_test passed\n");
    return 0;
}
