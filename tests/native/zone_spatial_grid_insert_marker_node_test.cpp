#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define func_1F2320 mock_func_1F2320
#define func_117CAC mock_func_117CAC

extern "C" {
void *mock_func_1F2320(void *pool) {
    static char dummyNode[0x100];
    memset(dummyNode, 0, sizeof(dummyNode));
    return dummyNode;
}
void mock_func_117CAC(void *dst, int val, int size) {
    memset(dst, val, size);
}
}

#include "../../src/zone/zone_spatial_grid_insert_marker_node.cpp"

int main() {
    // Allocate buffer for SpatialGrid
    SpatialGrid *grid = (SpatialGrid *)calloc(1, sizeof(SpatialGrid));
    assert(grid != NULL);

    int row0[10] = {0};
    int row1[10] = {0};
    int *grid_table[2] = { row0, row1 };
    grid->grid_table = grid_table;

    PyramidCell cells[16];
    memset(cells, 0, sizeof(cells));
    grid->cells = cells;

    grid->level_lut[0] = 0;
    grid->levels[0].shift = 0;
    grid->levels[0].offset = 0;
    grid->levels[0].id = 0;

    int ret = func_001EE140(grid, 0, 0);
    assert(ret == 1);
    assert(grid->marker_count == 1);
    assert((row0[0] & 0x80) != 0);
    assert(grid->marker_head != NULL);
    assert(grid->marker_head->cell_idx == 0);
    assert(grid->marker_head->type == 2);
    assert(grid->marker_head->min_x == 0.0f);
    assert(grid->marker_head->max_x == 1.0f);

    free(grid);
    printf("zone_spatial_grid_insert_marker_node_test passed\n");
    return 0;
}
