#include <cassert>
#include <cstring>
#include "zone_spatial_grid_execute_query.h"

static int g_func_123350_called = 0;
static int g_func_1EF180_called = 0;
static int g_func_1EEEA0_called = 0;

extern "C" {
int func_123350(float val) {
    g_func_123350_called++;
    return (int)val;
}

int func_1EF180(SpatialGrid *self, void *p1, void *p2) {
    g_func_1EF180_called++;
    return 1;
}

int func_1EEEA0(SpatialGrid *self, void *p1, void *p2) {
    g_func_1EEEA0_called++;
    return 1;
}
}

struct MockPyramidCell {
    void **items;
    int count;
    int capacity;
};

struct DummyGrid49 {
    char pad_00[0x12B41C];
    char is_initialized;
    char pad_align[3];
    void *world;
    int width;
    int height;
    float f_width;
    float f_height;
    char pad_table[0x12B444 - 0x12B434];
    int level_count;
    MockPyramidCell *cells;
    int total_nodes;
    int level_lut[0x20];
    char pad_levels[8 * 20];
    char pad_12B570[8];
    void *pool;
    char pad_12B57C[4];
    int param1;
    int *param2;
    int param3;
    char pad_align2[2];
    unsigned char has_margin;
    unsigned char flag_63;
    unsigned char flag_64;
    char pad_align3;
    float margin;
    void *query_target;
};

int main() {
    MockPyramidCell mock_cells[64];
    memset(mock_cells, 0, sizeof(mock_cells));

    DummyGrid49 grid;
    memset(&grid, 0, sizeof(grid));
    grid.width = 100;
    grid.height = 100;
    grid.cells = mock_cells;

    g_func_123350_called = 0;
    g_func_1EF180_called = 0;
    g_func_1EEEA0_called = 0;

    int res = func_001EE920((SpatialGrid *)&grid, 0, (void *)0x1234, 0, 0, 10.0f, 10.0f, 20.0f, 20.0f);
    assert(res >= 0);
    assert(grid.query_target == (void *)0x1234);

    return 0;
}
