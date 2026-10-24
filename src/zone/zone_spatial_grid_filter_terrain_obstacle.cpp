#pragma exceptions off
#include "zone_spatial_grid_filter_terrain_obstacle.h"

extern "C" {
void func_1E7C60(void *p1, void *p2, int p3, int p4);
}

struct WorldContainer {
    char pad[0x12B438];
    int **tile_grid;
};

struct SpatialGrid {
    WorldContainer *world;
};

extern "C" void func_001E7BD0(SpatialGrid *self, int tile_x, int tile_y) {
    int tile = self->world->tile_grid[tile_y][tile_x];
    int terrain = (tile & 0x3F00) >> 8;
    if (terrain == 6) {
        func_1E7C60(self, 0, 0, 0);
    }
}
