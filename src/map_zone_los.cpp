#pragma exceptions off
#include "map_zone_los.h"

extern "C" {
    extern int D_004E3058;
    extern SightEntry *D_0038FA40[];
    extern SightEntry *D_0038FAA0[];
    extern int *D_50A5A0[];
}

void func_00137E90(void *self) {
    (void)self;
}

void func_00137EA0(MapZone *self, int x, int y, int radius, int mode, int flag) {
    if (D_004E3058) {
        return;
    }
    char *tile28 = 0;
    if (radius > 20) {
        radius = 20;
    }
    SightEntry *entry;
    if (mode) {
        entry = D_0038FAA0[radius];
    } else {
        entry = D_0038FA40[radius];
    }

    int dy = entry->dy;
    while (dy != 999) {
        int ty = y + dy;
        if (ty >= 0) {
            if (ty < self->m_height) {
                int min_x = x + entry->min_dx;
                if (min_x < 0) {
                    min_x = 0;
                }
                int max_x = x + entry->max_dx;
                if (max_x >= self->m_width) {
                    max_x = self->m_width - 1;
                }
                unsigned char *tile_ptr = self->m_row_ptrs[ty] + min_x;
                int *flag_ptr = D_50A5A0[ty] + min_x;
                if (flag) {
                    tile28 = ((ZoneFieldC*)self->pad_0C)->m_grid[ty] + min_x * 28;
                }
                while (min_x <= max_x) {
                    int val = *tile_ptr - 1;
                    int t7 = (unsigned char)val;
                    if (t7 == 255) {
                        t7 = 0;
                    }
                    if ((unsigned char)val == 254) {
                        t7 = 255;
                    }
                    if (!t7) {
                        if (flag) {
                            tile28[9] = 128;
                        }
                        *flag_ptr &= self->pad_28;
                    }
                    *tile_ptr = t7;
                    tile_ptr++;
                    flag_ptr++;
                    min_x++;
                    tile28 += 28;
                }
            }
        }
        entry++;
        dy = entry->dy;
    }
}
