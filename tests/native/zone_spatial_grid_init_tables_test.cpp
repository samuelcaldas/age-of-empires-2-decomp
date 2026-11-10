#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "zone_spatial_grid_init_tables.h"

#define func_117CAC mock_func_117CAC
#define func_1F1ED0 mock_func_1F1ED0
#define func_1E6340 mock_func_1E6340
#define func_1F2320 mock_func_1F2320

static int g_1f1ed0_count = 0;
static int g_1e6340_count = 0;
static int g_1f2320_count = 0;

extern "C" {
void mock_func_117CAC(void *dst, int val, int size) { memset(dst, val, size); }
int mock_func_1F1ED0(SpatialGrid *ptr) { g_1f1ed0_count++; return 1; }
int mock_func_1E6340(SpatialGrid *ptr) { g_1e6340_count++; return 1; }
int mock_func_1F2320(SpatialGrid *ptr) { g_1f2320_count++; return 1; }
}

#include "../../src/zone/zone_spatial_grid_init_tables.cpp"

int main() {
    SpatialGrid *grid = (SpatialGrid *)calloc(1, sizeof(SpatialGrid));
    assert(grid != NULL);

    WorldMapInfo map;
    map.width = 64;
    map.height = 64;

    GameWorld world;
    world.map_info = &map;

    int ret = func_001ED3D0(grid, &world);
    assert(ret == 1);
    assert(grid->world == &world);
    assert(grid->width == 64);
    assert(grid->height == 64);
    assert(grid->f_width == 64.0f);
    assert(grid->f_height == 64.0f);
    assert(grid->level_count > 0);
    assert(g_1f1ed0_count == 1);
    assert(g_1e6340_count == 1);
    assert(g_1f2320_count == 4);

    free(grid);
    printf("zone_spatial_grid_init_tables_test passed\n");
    return 0;
}
