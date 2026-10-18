#ifndef ZONE_SPATIAL_GRID_INIT_TABLES_H
#define ZONE_SPATIAL_GRID_INIT_TABLES_H

struct WorldMapInfo {
    char pad_00[8];
    int width;
    int height;
};

struct GameWorld {
    char pad_00[0x3C];
    WorldMapInfo *map_info;
};

struct SpatialGrid;

extern "C" {
int func_001ED3D0(SpatialGrid *self, GameWorld *world);
void func_117CAC(void *dst, int val, int size);
int func_1F1ED0(SpatialGrid *self);
int func_1E6340(SpatialGrid *self);
int func_1F2320(SpatialGrid *self);
}

#endif
