#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

struct SpatialGrid;

#define func_123350 mock_func_123350
#define func_1EE130 mock_func_1EE130

static int g_1ee130_count = 0;
static int g_last_x = -1;
static int g_last_y = -1;

extern "C" {
int mock_func_123350(float val) { return (int)val; }
int mock_func_1EE130(SpatialGrid *self, int x, int y) {
    g_1ee130_count++;
    g_last_x = x;
    g_last_y = y;
    return 1;
}
}

#include "../../src/zone/zone_spatial_grid_mark_bounds_region.cpp"

int main() {
    SpatialGrid *grid = (SpatialGrid *)calloc(1, sizeof(SpatialGrid));
    assert(grid != NULL);

    grid->width = 10;
    grid->height = 10;
    grid->has_margin = 0;
    grid->margin = 0.0f;

    int row0[10] = {0};
    int row1[10] = {0};
    int row2[10] = {0};
    int *grid_table[3] = { row0, row1, row2 };
    grid->grid_table = grid_table;

    // Test region [1,1] to [2,2]
    int ret = func_001EE360(grid, 1.0f, 1.0f, 2.0f, 2.0f, 0);
    assert(ret == 1);
    // 2x2 = 4 cells visited
    assert(g_1ee130_count == 4);

    free(grid);
    printf("zone_spatial_grid_mark_bounds_region_test passed\n");
    return 0;
}
