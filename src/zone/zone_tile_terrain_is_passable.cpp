#pragma exceptions off
#include "zone_tile_terrain_is_passable.h"

struct Tile {
    char pad[5];
    unsigned char terrain;
    char pad2[22];
};

struct ZoneTileMap {
    char pad[0x98];
    Tile **rows;
    float *thresholds;
};

extern "C" int func_001D5E50(void *self, int x, int y) {
    ZoneTileMap *map = (ZoneTileMap *)self;
    Tile **rows = map->rows; Tile *r = rows[y]; if (map->thresholds[r[x].terrain] > 0.0f) return 1; return 0;
}
