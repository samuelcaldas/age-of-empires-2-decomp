#pragma once
#pragma exceptions off

#include "zone_smooth_elevation.h"

struct ZoneCell {
    char pad_0[6];          // 0x0..0x5
    char f_6;               // 0x6 (elevation)
    char pad_7[21];         // to reach 0x1C (28 bytes)
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
};

extern "C" int func_001CB6D0(void *self, int x0, int y0, int x1, int y1, int max_slope) {
    ZoneLayout *zm = (ZoneLayout *)self;
    short stride_param = *(short *)((char *)self + 8);

    int modified = 0;
    unsigned char limit = (unsigned char)max_slope;

    int t4 = 1 - (int)stride_param;
    int t3 = -(int)stride_param;
    int s1 = (int)stride_param + 1;
    int s2 = (int)stride_param - 1;
    int t2 = -1 - (int)stride_param;

    if (x0 > 0) x0--;
    if (y0 > 0) y0--;
    if (x1 < zm->width - 1) x1++;
    if (y1 < zm->height - 1) y1++;

    int t6_off = (t3 * 8 - t3) * 4;
    int t7_off = (stride_param * 8 - stride_param) * 4;
    int t8_off = (t2 * 8 - t2) * 4;
    int t9_off = (t4 * 8 - t4) * 4;
    int ra_off = (s2 * 8 - s2) * 4;
    int s0_off = (s1 * 8 - s1) * 4;

    for (int y = y0; y <= y1; y++) {
        int x0_off = (x0 * 8 - x0) * 4;
        ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x0_off);

        for (int x = x0; x <= x1; x++) {
            int elev = (int)cell->f_6;
            int trigger = 0;
            int new_elev = elev;

            if (elev < limit) {
                new_elev = elev + 1;
                if (y > 0) {
                    ZoneCell *north = (ZoneCell *)((char *)cell + t6_off);
                    if (new_elev < (int)north->f_6) trigger = 1;
                }
                if (y < zm->height - 1) {
                    ZoneCell *south = (ZoneCell *)((char *)cell + t7_off);
                    if (new_elev < (int)south->f_6) trigger = 1;
                }
                if (x > 0) {
                    ZoneCell *west = (ZoneCell *)((char *)cell - 28);
                    if (new_elev < (int)west->f_6) trigger = 1;
                }
                if (x < zm->width - 1) {
                    ZoneCell *east = (ZoneCell *)((char *)cell + 28);
                    if (new_elev < (int)east->f_6) trigger = 1;
                }
                if (y > 0) {
                    if (x > 0) {
                        ZoneCell *nw = (ZoneCell *)((char *)cell + t8_off);
                        if (new_elev < (int)nw->f_6) trigger = 1;
                    }
                    if (x < zm->width - 1) {
                        ZoneCell *ne = (ZoneCell *)((char *)cell + t9_off);
                        if (new_elev < (int)ne->f_6) trigger = 1;
                    }
                }
                if (y < zm->height - 1) {
                    if (x > 0) {
                        ZoneCell *sw = (ZoneCell *)((char *)cell + ra_off);
                        if (new_elev < (int)sw->f_6) trigger = 1;
                    }
                    if (x < zm->width - 1) {
                        ZoneCell *se = (ZoneCell *)((char *)cell + s0_off);
                        if (new_elev < (int)se->f_6) trigger = 1;
                    }
                }
            } else if (elev > limit) {
                new_elev = elev - 1;
                if (y > 0) {
                    ZoneCell *north = (ZoneCell *)((char *)cell + t6_off);
                    if ((int)north->f_6 < new_elev) trigger = 1;
                }
                if (y < zm->height - 1) {
                    ZoneCell *south = (ZoneCell *)((char *)cell + t7_off);
                    if ((int)south->f_6 < new_elev) trigger = 1;
                }
                if (x > 0) {
                    ZoneCell *west = (ZoneCell *)((char *)cell - 28);
                    if ((int)west->f_6 < new_elev) trigger = 1;
                }
                if (x < zm->width - 1) {
                    ZoneCell *east = (ZoneCell *)((char *)cell + 28);
                    if ((int)east->f_6 < new_elev) trigger = 1;
                }
                if (y > 0) {
                    if (x > 0) {
                        ZoneCell *nw = (ZoneCell *)((char *)cell + t8_off);
                        if ((int)nw->f_6 < new_elev) trigger = 1;
                    }
                    if (x < zm->width - 1) {
                        ZoneCell *ne = (ZoneCell *)((char *)cell + t9_off);
                        if ((int)ne->f_6 < new_elev) trigger = 1;
                    }
                }
                if (y < zm->height - 1) {
                    if (x > 0) {
                        ZoneCell *sw = (ZoneCell *)((char *)cell + ra_off);
                        if ((int)sw->f_6 < new_elev) trigger = 1;
                    }
                    if (x < zm->width - 1) {
                        ZoneCell *se = (ZoneCell *)((char *)cell + s0_off);
                        if ((int)se->f_6 < new_elev) trigger = 1;
                    }
                }
            }

            if (trigger != 0) {
                cell->f_6 = (char)new_elev;
                modified = 1;
            }

            cell = (ZoneCell *)((char *)cell + 28);
        }
    }

    return modified;
}
