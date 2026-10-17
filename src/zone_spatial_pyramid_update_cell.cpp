#pragma exceptions off

#include "zone_spatial_pyramid_update_cell.h"

extern "C" int func_001D21B0(void *self, int level, int x, int y) {
    char *zm = (char *)self;
    unsigned char lvl = (unsigned char)level;
    void ***root = *(void ****)(zm + 0x0);
    char *cell = (char *)root[lvl][x] + y * 2;

    cell[1] = 0;

    if ((int)lvl > 0) {
        cell[0] = 0;
        int next_lvl = lvl - 1;
        int x2 = x * 2;
        int y2 = y * 2;

        if (func_001D21B0(self, next_lvl, x2, y2) != 0) {
            cell[1] += 1;
        }
        if (func_001D21B0(self, next_lvl, x2 + 1, y2) != 0) {
            cell[1] += 2;
        }
        if (func_001D21B0(self, next_lvl, x2, y2 + 1) != 0) {
            cell[1] += 4;
        }
        if (func_001D21B0(self, next_lvl, x2 + 1, y2 + 1) != 0) {
            cell[1] += 8;
        }
    } else {
        int max_x = *(int *)(zm + 0xE4);
        int max_y = *(int *)(zm + 0xE8);
        if (x < max_x && y < max_y) {
            cell[1] += 0xF;
        }
    }

    if ((cell[1] & 0xF) == 0xF) {
        return 1;
    }
    return 0;
}
