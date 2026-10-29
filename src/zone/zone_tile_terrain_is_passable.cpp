#pragma exceptions off

#include "zone_tile_terrain_is_passable.h"

extern "C" int func_001D5E50(void *self, int x, int y) {
    char *zm = (char *)self;
    int y_off = y << 2;
    char **rows = *(char ***)(zm + 0x98);
    float *thresholds = *(float **)(zm + 0x9C);

    int x_off = (x * 7) << 2;
    char *row = *(char **)((char *)rows + y_off);
    unsigned char terrain = *(unsigned char *)(row + x_off + 5);

    if (thresholds[terrain] <= 0.0f) {
        return 0;
    }
    return 1;
}
