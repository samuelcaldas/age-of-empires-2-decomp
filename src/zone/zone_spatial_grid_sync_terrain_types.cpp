#pragma exceptions off
#include "zone_spatial_grid_sync_terrain_types.h"

extern "C" {
extern unsigned char D_00392070[];
}

#ifndef __MWERKS__
unsigned char D_00392070[256] = { 0 };
#endif

struct Tile {
    char pad_00[5];
    unsigned char type;
    char pad_06[22];
};

struct WorldMap {
    char pad_00[0x8E8C];
    Tile **tile_rows;
};

struct WorldObj {
    char pad_00[0x3C];
    WorldMap *map;
};

struct SpatialGrid {
    char pad_00[0x12B420];
    WorldObj *world;
    int width;
    int height;
    char pad_12B42C[8];
    void *table1;
    int **grid_rows;
};

extern "C" int func_001ED9C0(SpatialGrid *self) {
    int x;
    WorldMap *map = self->world->map;

    for (int y = 0; y < self->height; ++y) {
        Tile *tiles = map->tile_rows[y];
        int *grid_cells = self->grid_rows[y];
        for (x = 0; x < self->width; ++x) {
            grid_cells[x] = D_00392070[tiles[x].type] | (grid_cells[x] & ~0xFF);
        }
    }
    return 1;
}
