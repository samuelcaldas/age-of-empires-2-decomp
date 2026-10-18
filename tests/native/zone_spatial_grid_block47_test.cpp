#include <cassert>
#include <cstring>
#include "zone_spatial_grid_compute_terrain_mask.h"
#include "zone_spatial_grid_stamp_obstacle_region.h"
#include "zone_spatial_grid_clear_obstacle_region.h"
#include "zone_spatial_grid_set_obstacle_callback.h"

static int g_callback_called = 0;
static void *g_callback_arg = 0;

static void test_callback(void *arg) {
    g_callback_called++;
    g_callback_arg = arg;
}

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001EE550 - compute terrain mask from weights
    // -------------------------------------------------------------
    float weights[32];
    for (int i = 0; i < 32; ++i) {
        weights[i] = 0.0f;
    }
    // With zero weights, mask should be 0
    int mask_zero = func_001EE550(0, weights);
    assert(mask_zero == 0);

    // Set one weight > 0
    weights[0] = 1.0f;
    int mask_one = func_001EE550(0, weights);
    assert(mask_one != 0);

    // -------------------------------------------------------------
    // Test 2: func_001EE710 - set obstacle callback
    // -------------------------------------------------------------
    struct DummyGrid47 {
        char pad_00[0x12B438];
        int **grid_table;
        char pad_after[0x12B5A4 - 0x12B438 - 4];
        void *cb_fn;
        void *cb_ctx;
    } grid;
    memset(&grid, 0, sizeof(grid));

    func_001EE710((SpatialGrid *)&grid, (void *)test_callback, (void *)0x1234);
    assert(grid.cb_fn == (void *)test_callback);
    assert(grid.cb_ctx == (void *)0x1234);

    // -------------------------------------------------------------
    // Test 3: func_001EE5B0 - stamp obstacle region
    // -------------------------------------------------------------
    int cell = 0;
    int *row = &cell;
    int *grid_rows[1] = { row };
    grid.grid_table = grid_rows;

    g_callback_called = 0;
    int res_stamp = func_001EE5B0((SpatialGrid *)&grid, 0, 0, 0, 0, 1, 5);
    assert(res_stamp == 1);
    assert((cell & 0x4000) != 0); // stamped flag
    assert(g_callback_called == 1);
    assert(g_callback_arg == (void *)0x1234);

    // -------------------------------------------------------------
    // Test 4: func_001EE670 - clear obstacle region
    // -------------------------------------------------------------
    g_callback_called = 0;
    int res_clear = func_001EE670((SpatialGrid *)&grid, 0, 0, 0, 0);
    assert(res_clear == 1);
    assert((cell & 0x4000) == 0); // high bits cleared
    assert(g_callback_called == 1);

    return 0;
}
