#pragma once
#pragma exceptions off

#include "zone_level_elevation.h"

struct ZoneCell {
    char pad_0[6];          // 0x0..0x5
    char f_6;               // 0x6 (elevation)
    char pad_7[21];         // 28 bytes total
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
};

extern "C" void func_001CBB90(void *self, int x0, int y0, int x1, int y1, int max_slope) {
    ZoneLayout *zm = (ZoneLayout *)self;
    short stride_param = *(short *)((char *)self + 8);
    unsigned char limit = (unsigned char)max_slope;

    short t5 = (short)(-1 - stride_param);
    short t6 = (short)(-stride_param);
    int north_off = (t6 * 8 - t6) * 4;
    int south_off = (stride_param * 8 - stride_param) * 4;
    short v1_off = (short)(1 - stride_param);
    short t2 = (short)(stride_param - 1);
    short t1_off = (short)(stride_param + 1);

    int nw_off = (t5 * 8 - t5) * 4;
    int ne_off = (v1_off * 8 - v1_off) * 4;
    int sw_off = (t2 * 8 - t2) * 4;
    int se_off = (t1_off * 8 - t1_off) * 4;

    int modified;
    do {
        modified = 0;

        if (x0 > 0) x0--;
        if (y0 > 0) y0--;
        if (x1 < zm->width - 1) x1++;
        if (y1 < zm->height - 1) y1++;

        for (int y = y0; y <= y1; y++) {
            int x0_off = (x0 * 8 - x0) * 4;
            ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x0_off);

            for (int x = x0; x <= x1; x++) {
                volatile short nw_flag = 0;
                volatile short ne_flag = 0;
                volatile short se_flag = 0;
                int north_flag = 0;
                int east_flag = 0;
                int south_flag = 0;
                int west_flag = 0;
                int sw_flag = 0;

                unsigned char elev = (unsigned char)cell->f_6;

                if (y > 0) {
                    ZoneCell *north = (ZoneCell *)((char *)cell + north_off);
                    if ((int)elev < (int)(unsigned char)north->f_6) {
                        north_flag = 1;
                    }
                }
                if (y < zm->height - 1) {
                    ZoneCell *south = (ZoneCell *)((char *)cell + south_off);
                    if ((int)elev < (int)(unsigned char)south->f_6) {
                        south_flag = 1;
                    }
                }
                if (x > 0) {
                    ZoneCell *west = (ZoneCell *)((char *)cell - 28);
                    if ((int)elev < (int)(unsigned char)west->f_6) {
                        west_flag = 1;
                    }
                }
                if (x < zm->width - 1) {
                    ZoneCell *east = (ZoneCell *)((char *)cell + 28);
                    if ((int)elev < (int)(unsigned char)east->f_6) {
                        east_flag = 1;
                    }
                }
                if (y > 0) {
                    if (x > 0) {
                        ZoneCell *nw = (ZoneCell *)((char *)cell + nw_off);
                        if ((int)elev < (int)(unsigned char)nw->f_6) {
                            nw_flag = 1;
                        }
                    }
                    if (x < zm->width - 1) {
                        ZoneCell *ne = (ZoneCell *)((char *)cell + ne_off);
                        if ((int)elev < (int)(unsigned char)ne->f_6) {
                            ne_flag = 1;
                        }
                    }
                }
                if (y < zm->height - 1) {
                    if (x > 0) {
                        ZoneCell *sw = (ZoneCell *)((char *)cell + sw_off);
                        if ((int)elev < (int)(unsigned char)sw->f_6) {
                            sw_flag = 1;
                        }
                    }
                    if (x < zm->width - 1) {
                        ZoneCell *se = (ZoneCell *)((char *)cell + se_off);
                        if ((int)elev < (int)(unsigned char)se->f_6) {
                            se_flag = 1;
                        }
                    }
                }

                int saddle = 0;
                if (north_flag != 0 && south_flag != 0) {
                    saddle = 1;
                }
                if (east_flag != 0 && west_flag != 0) {
                    saddle = 1;
                }

                if (saddle != 0) {
                    if ((int)elev < (int)limit) {
                        cell->f_6 = (char)(elev + 1);
                        modified = 1;
                    } else {
                        if (nw_flag != 0) {
                            ZoneCell *nw = (ZoneCell *)((char *)cell + nw_off);
                            nw->f_6 = (char)elev;
                        }
                        if (north_flag != 0) {
                            ZoneCell *north = (ZoneCell *)((char *)cell + north_off);
                            north->f_6 = (char)elev;
                        }
                        if (ne_flag != 0) {
                            ZoneCell *ne = (ZoneCell *)((char *)cell + ne_off);
                            ne->f_6 = (char)elev;
                        }
                        if (east_flag != 0) {
                            ZoneCell *east = (ZoneCell *)((char *)cell + 28);
                            east->f_6 = (char)elev;
                        }
                        if (se_flag != 0) {
                            ZoneCell *se = (ZoneCell *)((char *)cell + se_off);
                            se->f_6 = (char)elev;
                        }
                        if (south_flag != 0) {
                            ZoneCell *south = (ZoneCell *)((char *)cell + south_off);
                            south->f_6 = (char)elev;
                        }
                        if (sw_flag != 0) {
                            ZoneCell *sw = (ZoneCell *)((char *)cell + sw_off);
                            sw->f_6 = (char)elev;
                        }
                        if (west_flag != 0) {
                            ZoneCell *west = (ZoneCell *)((char *)cell - 28);
                            west->f_6 = (char)elev;
                        }
                        modified = 1;
                    }
                }

                cell = (ZoneCell *)((char *)cell + 28);
            }
        }
    } while (modified != 0);
}
