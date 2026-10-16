#pragma exceptions off

#include "zone_spatial_pyramid_process_cell.h"

extern "C" {
void func_1D29F0(void *self, int x, int y, void *p1);
}

extern "C" void func_001D2460(void *self, int level, int x, int y, void *p1, void *p2) {
    char *zm = (char *)self;
    unsigned char lvl = (unsigned char)level;
    void ***root = *(void ****)(zm + 0x0);
    char *cell = (char *)root[lvl][x] + y * 2;

    if (lvl == 0) {
        cell[1] &= 0xF;
        int x0 = *(int *)(zm + 0xF4);
        int y0 = *(int *)(zm + 0xF8);
        int x1 = *(int *)(zm + 0xFC);
        int y1 = *(int *)(zm + 0x100);

        if (x >= x0 && x <= x1 && y >= y0 && y <= y1) {
            func_1D29F0(self, x, y, p1);
            if (*(char *)p1 != 0) {
                cell[1] |= 0x10;
            }
        }
        return;
    }

    int next_lvl = lvl - 1;
    int x2 = x * 2;
    int y2 = y * 2;

    func_001D2460(self, next_lvl, x2, y2, p1, p2);
    func_001D2460(self, next_lvl, x2 + 1, y2, p1, p2);
    func_001D2460(self, next_lvl, x2, y2 + 1, p1, p2);
    func_001D2460(self, next_lvl, x2 + 1, y2 + 1, p1, p2);
}
