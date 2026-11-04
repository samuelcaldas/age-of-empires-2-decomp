#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_filter_terrain_obstacle.h"

void *D_004E3180 = NULL;

static int s_func_1E7C60_calls = 0;
static void *s_last_p1 = NULL;
static void *s_last_p2 = NULL;
static int s_last_p3 = 0;
static int s_last_p4 = 0;

extern "C" {
void func_1E7C60(void *p1, void *p2, int p3, int p4) {
    s_func_1E7C60_calls++;
    s_last_p1 = p1;
    s_last_p2 = p2;
    s_last_p3 = p3;
    s_last_p4 = p4;
}
}

struct WorldContainerMock {
    char pad[0x12B438];
    int **tile_grid;
};

struct SpatialGridMock {
    WorldContainerMock *world;
};

int main() {
    int row0[4] = {0x0600, 0x0700, 0, 0}; // terrain 6 at (0,0), terrain 7 at (1,0)
    int *tile_grid[1] = {row0};

    WorldContainerMock world;
    std::memset(&world, 0, sizeof(world));
    world.tile_grid = tile_grid;

    SpatialGridMock grid;
    grid.world = &world;

    // Set up D_004E3180 mock
    char global_ctx[0x500];
    std::memset(global_ctx, 0, sizeof(global_ctx));
    D_004E3180 = global_ctx;

    char sub_obj[0x100];
    std::memset(sub_obj, 0, sizeof(sub_obj));
    *(void **)(global_ctx + 0x404) = sub_obj;

    char zone_obj[0x10000];
    std::memset(zone_obj, 0, sizeof(zone_obj));
    *(void **)(sub_obj + 0x3C) = zone_obj;

    char cell_data[100];
    std::memset(cell_data, 0, sizeof(cell_data));
    char *cell_row[1] = {cell_data};
    *(void ***)(zone_obj + 0x8E8C) = (void **)cell_row;

    // Test terrain != 6 -> no call
    s_func_1E7C60_calls = 0;
    func_001E7BD0((SpatialGrid *)&grid, 1, 0);
    assert(s_func_1E7C60_calls == 0);

    // Test terrain == 6 -> calls func_1E7C60
    func_001E7BD0((SpatialGrid *)&grid, 0, 0);
    assert(s_func_1E7C60_calls == 1);
    assert(s_last_p1 == &grid);
    assert(s_last_p2 == (void *)cell_data);
    assert(s_last_p3 == 0);
    assert(s_last_p4 == -1);

    return 0;
}
