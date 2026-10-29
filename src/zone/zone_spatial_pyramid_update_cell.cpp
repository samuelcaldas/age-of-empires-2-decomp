#pragma exceptions off

#include "zone_spatial_pyramid_update_cell.h"

extern "C" int func_001D21B0(void *self, unsigned char level, int x, int y) {
    char *zm = (char *)self;
    void ***root = *(void ****)zm;
    char *cell = (char *)root[level][x] + (y << 1);

    cell[1] = 0;

    if ((int)level > 0) {
        cell[0] = 0;
        unsigned char next_lvl = level - 1;
        int x2 = x << 1;
        int y2 = y << 1;

        if (func_001D21B0(self, next_lvl, x2, y2)) {
            cell[1] += 1;
        }
        if (func_001D21B0(self, next_lvl, x2 + 1, y2)) {
            cell[1] += 2;
        }
        if (func_001D21B0(self, next_lvl, x2, y2 + 1)) {
            cell[1] += 4;
        }
        if (func_001D21B0(self, next_lvl, x2 + 1, y2 + 1)) {
            cell[1] += 8;
        }
    } else {
        int max_x = *(int *)(zm + 0xE4);
        if (x >= max_x || y >= *(int *)(zm + 0xE8)) {
            cell[1] += 0xF;
        }
    }

    if ((cell[1] & 0xF) == 0xF) {
        return 1;
    }
    return 0;
}
