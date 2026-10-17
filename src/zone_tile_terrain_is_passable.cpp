#pragma exceptions off

#include "zone_tile_terrain_is_passable.h"

extern "C" int func_001D5E50(void *self, int x, int y) {
    char *zm = (char *)self;
    char **rows = *(char ***)(zm + 0x98);
    char *cell = rows[y] + x * 28;

    unsigned char terrain = *(unsigned char *)(cell + 5);
    float *thresholds = *(float **)(zm + 0x9C);
    float thresh = thresholds[terrain];

    if (thresh <= 0.0f) {
        return 0;
    }
    return 1;
}
