#pragma exceptions off
#include "zone_spatial_grid_mark_tile_occupants.h"

extern "C" {
void func_1E6EC0(void *self, int packed_coord);
void *func_332E60(void *world, void *item);
float func_1234E0(float f, double d);
float func_1140C8(float f);
float func_1228E8(float f);
int func_113FB8(float f);
float func_123350(float f);
}

struct WorldContainer {
    char pad_4BC8[0x12B438];
    int **tile_grid;
};

struct SubItem {
    char pad_20[0x20];
    float w;
    float h;
};

struct Entity {
    char pad_4[0x4];
    SubItem *sub;
    char pad_44[0x3C];
    float pos_x;
    float pos_y;
};

struct SpatialGrid {
    WorldContainer *world;
};

extern "C" void func_001E6CC0(SpatialGrid *self, int mode_flag, void **items, int count, int filter_mask) {
    if (mode_flag != 0) {
        for (int i = 0; i < count; i++) {
            func_1E6EC0(self, (int)items[i]);
        }
    }
}
