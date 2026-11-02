#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_grid_update_bounds_margin.h"

struct SpatialGrid {
    int dummy;
};

static int g_123350_called = 0;
static int g_1ee660_called = 0;
static int g_1ee780_called = 0;

static int g_min_x = 0;
static int g_min_y = 0;
static int g_max_x = 0;
static int g_max_y = 0;
static int g_p5 = 0;
static int g_sub_p1 = 0;

extern "C" {
int func_123350(float val) {
    g_123350_called++;
    return (int)val;
}

int func_1EE660(SpatialGrid *self, int x0, int y0, int x1, int y1, int p5) {
    g_1ee660_called++;
    g_min_x = x0;
    g_min_y = y0;
    g_max_x = x1;
    g_max_y = y1;
    g_p5 = p5;
    return 1;
}

int func_1EE780(SpatialGrid *self, int p1, int p2, int p3, int p4) {
    g_1ee780_called++;
    g_sub_p1 = p1;
    return 1;
}
}

#include "../../src/zone/zone_spatial_grid_update_bounds_margin.cpp"

int main() {
    SpatialGrid grid;
    Entity entity;
    EntityData data;
    memset(&grid, 0, sizeof(grid));
    memset(&entity, 0, sizeof(entity));
    memset(&data, 0, sizeof(data));

    entity.data = &data;
    data.size_x = 2.0f;
    data.size_y = 3.0f;
    entity.pos_x = 10.0f;
    entity.pos_y = 20.0f;
    entity.sub_obj = (void*)0x9999;

    // Test mode == 0 -> returns 0
    data.mode = 0;
    assert(func_001EDF30(&grid, &entity) == 0);
    assert(g_1ee660_called == 0);

    // Test mode == 3 -> returns 0
    data.mode = 3;
    assert(func_001EDF30(&grid, &entity) == 0);

    // Test mode == 1 -> calls func_1EE660, returns 1
    data.mode = 1;
    int ret = func_001EDF30(&grid, &entity);
    assert(ret == 1);
    assert(g_1ee660_called == 1);
    assert(g_min_x == 8); // 10 - 2
    assert(g_min_y == 17); // 20 - 3
    assert(g_max_x == 11); // 10 + 2 - 1
    assert(g_max_y == 22); // 20 + 3 - 1
    assert(g_1ee780_called == 0);

    // Test mode == 2 with sub_obj != 0 -> calls func_1EE780, clears sub_obj, returns 1
    data.mode = 2;
    entity.sub_obj = (void*)0x9999;
    ret = func_001EDF30(&grid, &entity);
    assert(ret == 1);
    assert(g_1ee660_called == 2);
    assert(g_1ee780_called == 1);
    assert(g_sub_p1 == 0x9999);
    assert(entity.sub_obj == 0);

    // Test mode == 2 with sub_obj == 0 -> returns 0
    ret = func_001EDF30(&grid, &entity);
    assert(ret == 0);
    assert(g_1ee660_called == 3);
    assert(g_1ee780_called == 1);

    printf("zone_spatial_grid_update_bounds_margin_test passed\n");
    return 0;
}
