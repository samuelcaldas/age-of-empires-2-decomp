#include <cassert>
#include <cstring>
#include <cmath>
#include "zone_spatial_grid_query_raycast_line.h"
#include "zone_spatial_grid_test_raycast_cell.h"
#include "zone_spatial_grid_record_raycast_hit.h"

static int g_func_123350_called = 0;
static int g_func_1EF450_called = 0;
static int g_func_1EFF50_called = 0;
static int g_func_1F1520_called = 0;
static int g_func_1F0620_called = 0;
static int g_func_1F0E00_called = 0;

extern "C" {
int func_123350(float val) {
    g_func_123350_called++;
    return (int)val;
}

int func_1EF450(SpatialGrid *self, float fx0, float fy0, float fx1, float fy1, Point2D *out_pts, int *out_cnt) {
    g_func_1EF450_called++;
    *out_cnt = 0;
    return 1;
}

int func_1EFF50(SpatialGrid *self, int cell_idx, int flags, void *p4, int p5) {
    g_func_1EFF50_called++;
    return 1;
}

int func_1F1520(SpatialGrid *self, int cell_idx, int flags, void *p4, int p5) {
    g_func_1F1520_called++;
    return 1;
}

int func_1F0620(SpatialGrid *self, void *item, void *p3) {
    g_func_1F0620_called++;
    return 1;
}

int func_1F0E00(SpatialGrid *self, void *item, void *p3) {
    g_func_1F0E00_called++;
    return 1;
}
}

struct HitResult {
    void *node;
    int id;
    float x;
    float y;
};

struct DummyGrid52 {
    char pad_00[0x12B584];
    char flag_88;
    char pad_8C[3];
    int count_8C;
    void *array_94;
    HitResult *results;
    int *out_count;
    int max_count;
};

int main() {
    // -------------------------------------------------------------
    // Test 1: func_001F02A0 - record raycast hit
    // -------------------------------------------------------------
    HitResult results[4];
    memset(results, 0, sizeof(results));
    int count = 0;

    DummyGrid52 grid;
    memset(&grid, 0, sizeof(grid));
    grid.results = results;
    grid.out_count = &count;
    grid.max_count = 4;

    HitNode node;
    memset(&node, 0, sizeof(node));
    node.coord = 0x12345678;

    Point2D pos;
    pos.x = 10.5f;
    pos.y = 20.5f;

    int res = func_001F02A0((SpatialGrid *)&grid, &node, &pos);
    assert(res == 1);
    assert(count == 1);
    assert(results[0].node == &node);
    assert(results[0].id == (int)0x12345678);
    assert(std::fabs(results[0].x - 10.5f) < 0.001f);
    assert(std::fabs(results[0].y - 20.5f) < 0.001f);

    // Over-capacity test: when count >= max_count, returns 0
    count = 4;
    int res_full = func_001F02A0((SpatialGrid *)&grid, &node, &pos);
    assert(res_full == 0);
    assert(count == 4);

    return 0;
}
