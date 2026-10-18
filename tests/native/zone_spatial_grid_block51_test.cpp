#include <cassert>
#include <cstring>
#include <cmath>
#include "zone_spatial_grid_trace_ray_tiles.h"

static int g_func_1EF410_called = 0;
static int g_func_123350_called = 0;

extern "C" {
void func_001EF410(float *out_x, float *out_y, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    g_func_1EF410_called++;
    *out_x = (x1 + x2) * 0.5f;
    *out_y = (y1 + y2) * 0.5f;
}

int func_123350(float val) {
    g_func_123350_called++;
    return (int)val;
}
}

struct DummyGrid51 {
    char pad_00[0x12B424];
    int width;
    int height;
    float f_width;
    float f_height;
    void *table1;
    int **grid_table;
};

int main() {
    int cell = 0;
    int *row = &cell;
    int *grid_rows[10] = { row, row, row, row, row, row, row, row, row, row };

    DummyGrid51 grid;
    memset(&grid, 0, sizeof(grid));
    grid.width = 10;
    grid.height = 10;
    grid.f_width = 10.0f;
    grid.f_height = 10.0f;
    grid.grid_table = grid_rows;

    Point2D out_points[32];
    int out_count = 0;

    g_func_1EF410_called = 0;
    g_func_123350_called = 0;

    int res = func_001EF460((SpatialGrid *)&grid, 1.0f, 1.0f, 5.0f, 5.0f, out_points, &out_count);
    assert(res >= 0);

    return 0;
}
