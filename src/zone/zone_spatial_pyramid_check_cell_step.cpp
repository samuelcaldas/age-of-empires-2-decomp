#pragma exceptions off

#include "zone_spatial_pyramid_check_cell_step.h"

extern "C" int func_001D4E00(void *self, int x, int y, int level, int min_x, int min_y) {
    int dx = x - min_x;
    int dy = y - min_y;
    if (dx < 0) {
        dx = 0;
    }
    if (dy < 0) {
        dy = 0;
    }

    int dist = dx + dy;

    void ***root = *(void ****)self;
    unsigned char *cell = (unsigned char *)root[level][min_x] + (min_y << 1);

    if ((cell[1] & 0xF) == 0xF) {
        return -1;
    }

    if (cell[0]) {
        return -1;
    }

    return dist;
}
