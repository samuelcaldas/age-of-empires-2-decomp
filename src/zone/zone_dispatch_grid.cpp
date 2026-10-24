#pragma exceptions off

#include "zone_dispatch_internal.h"

extern "C" void func_001C9E00(void *self, int x0, int y0, int x1, int y1, int fill_a) {
    // Sorted-bounds rectangle fill: sets cell->f_7=0xCC, cell->f_A=fill_a
    // Sorts (x0,x1) and (y0,y1) ranges, clamps to grid, fills matching cells
    if (x1 < x0) {
        int tmp = x0; x0 = x1; x1 = tmp;
    }
    if (y1 < y0) {
        int tmp = y0; y0 = y1; y1 = tmp;
    }
    if (x1 < 0) return;
    if (y1 < 0) return;
    int width = ((ZoneCellsLayout *)self)->width;
    if (!(x0 < width)) return;
    int height = ((ZoneCellsLayout *)self)->height;
    if (!(y0 < height)) goto done;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (!(x1 < width)) x1 = width - 1;
    if (!(y1 < height)) y1 = height - 1;
    {
        int cell_x_off = (x0 * 8 - x0) * 4;  // x0 * 0x1C (cell stride = 28 bytes)
        int cc = 0xCC;
        for (int y = y0; y <= y1; ) {
            ZoneCell *cell = (ZoneCell *)((char *)((ZoneCellsLayout *)self)->cells_ptr[y] + cell_x_off);
            int x = x0;
            while (!(x1 < x)) {
                cell->f_7 = cc;
                cell->f_A = fill_a;
                cell = (ZoneCell *)((char *)cell + 0x1C);
                x++;
            }
            y++;
        }
    }
done:;
}

extern "C" void func_001C9F00(void *self) {
    int ff = 0xFF;
    register int y = 0;
    while (y < ((ZoneCellsLayout *)self)->height) {
        ZoneCell *cell = ((ZoneCellsLayout *)self)->cells_ptr[y];
        int x = 0;
        while (x < ((ZoneCellsLayout *)self)->width) {
            cell->f_7 = 0;
            cell->f_8 = ff;
            cell->f_E = ff;
            cell->f_9 = 0;
            cell->f_A = 0;
            cell = (ZoneCell *)((char *)cell + 0x1C);
            x++;
        }
        y++;
    }
}

extern "C" void func_001C9F80(void *self) {
    ZoneCellsLayout *zm = (ZoneCellsLayout *)self;
    int width = zm->width;
    int height = zm->height;
    func_001C9FA0(self, 0, 0, width - 1, height - 1);
}
