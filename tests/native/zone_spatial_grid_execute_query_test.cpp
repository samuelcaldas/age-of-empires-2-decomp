#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_execute_query.h"

static int s_func_1EF180_calls = 0;
static int s_func_1EEEA0_calls = 0;

extern "C" {
int func_123350(float val) {
    return (int)val;
}

int func_1EF180(SpatialGrid *self, void *p1, void *p2) {
    (void)self; (void)p1; (void)p2;
    s_func_1EF180_calls++;
    return 0;
}

int func_1EEEA0(SpatialGrid *self, void *p1, void *p2) {
    (void)self; (void)p1; (void)p2;
    s_func_1EEEA0_calls++;
    return 0;
}
}

struct PyramidCell {
    void **items;
    int count;
    int capacity;
};

struct PyramidLevel {
    int id;
    int shift;
    int dim;
    int offset;
    void *nodes;
};

struct SpatialGridMock {
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
    PyramidCell *cells;
    int total_nodes;
    int level_lut[0x20];
    PyramidLevel levels[8];
    char pad_12B570[8];
    void *pool;
    char pad_12B57C[4];
    int param1;
    int *param2;
    int param3;
    char pad_12B58C[4];
    void *query_target;
    char flag_63;
    char flag_64;
};

int main() {
    SpatialGridMock *grid = (SpatialGridMock *)std::malloc(sizeof(SpatialGridMock));
    std::memset(grid, 0, sizeof(SpatialGridMock));

    PyramidCell cells[10];
    std::memset(cells, 0, sizeof(cells));
    grid->cells = cells;

    SpatialGrid *self = reinterpret_cast<SpatialGrid *>(grid);

    // Test 1: out of bounds query (min_x < 0 or max_x > width) returns 1
    grid->width = 100;
    grid->height = 100;
    int res = func_001EE920(self, 0, NULL, NULL, 0, -5.0f, 0.0f, 10.0f, 10.0f);
    assert(res == 1);

    // Test 2: in-bounds query with empty cells returns 0
    res = func_001EE920(self, 0, NULL, NULL, 0, 5.0f, 5.0f, 10.0f, 10.0f);
    assert(res == 0);

    std::free(grid);
    return 0;
}
