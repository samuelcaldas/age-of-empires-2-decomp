#pragma exceptions off
#include "zone_spatial_grid_filter_terrain_obstacle.h"

extern "C" {
extern void *D_004E3180;
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
    unsigned int terrain = ((unsigned int)tile & 0x3F00) >> 8;
    if (terrain == 6) {
        void *v0 = *(void **)((char *)D_004E3180 + 0x404);
        void *zone = *(void **)((char *)v0 + 0x3C);
        int **cells = *(int ***)((char *)zone + 0x8E8C);
        int *cell_row = cells[tile_y];
        void *target_cell = (void *)((char *)cell_row + tile_x * 28);
        func_1E7C60(self, target_cell, 0, -1);
    }
}
