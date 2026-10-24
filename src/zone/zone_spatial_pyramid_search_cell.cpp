#pragma exceptions off

#include "zone_spatial_pyramid_search_cell.h"

extern "C" int func_001D3440(void *self, int level, int x, int y, void *p1, void *p2) {
    char *zm = (char *)self;
    unsigned char lvl = (unsigned char)level;
    void ***root = *(void ****)(zm + 0x0);
    char *cell = (char *)root[lvl][x] + y * 2;

    if ((cell[1] & 0x10) != 0) {
        return 1;
    }

    if (lvl == 0) {
        return 0;
    }

    int next_lvl = lvl - 1;
    int x2 = x * 2;
    int y2 = y * 2;

    if (func_001D3440(self, next_lvl, x2, y2, p1, p2) != 0) {
        return 1;
    }
    if (func_001D3440(self, next_lvl, x2 + 1, y2, p1, p2) != 0) {
        return 1;
    }
    if (func_001D3440(self, next_lvl, x2, y2 + 1, p1, p2) != 0) {
        return 1;
    }
    if (func_001D3440(self, next_lvl, x2 + 1, y2 + 1, p1, p2) != 0) {
        return 1;
    }

    return 0;
}
