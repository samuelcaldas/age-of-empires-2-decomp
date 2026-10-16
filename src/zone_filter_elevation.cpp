#pragma once
#pragma exceptions off

#include "zone_filter_elevation.h"

extern "C" {
void func_001CBB90(void *self, int x0, int y0, int x1, int y1, int max_slope);
int func_001CB6D0(void *self, int x0, int y0, int x1, int y1, int max_slope);
void func_001CF3E0(void *self, int x0, int y0, int x1, int y1, int p5, int p6, int p7);
}

struct ZoneCell {
    char pad_0[6];
    char f_6;
    char pad_7[21];
};

struct ZoneLayout {
    char pad_0[8];
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
};

static inline void level_neighbors(ZoneCell *cell, int nw, int n, int ne, int e, int se, int s, int sw, int w,
                                   int nw_off, int n_off, int ne_off, int se_off, int s_off, int sw_off, char elev) {
    if (nw != 0) ((ZoneCell *)((char *)cell + nw_off))->f_6 = elev;
    if (n != 0) ((ZoneCell *)((char *)cell + n_off))->f_6 = elev;
    if (ne != 0) ((ZoneCell *)((char *)cell + ne_off))->f_6 = elev;
    if (e != 0) ((ZoneCell *)((char *)cell + 28))->f_6 = elev;
    if (se != 0) ((ZoneCell *)((char *)cell + se_off))->f_6 = elev;
    if (s != 0) ((ZoneCell *)((char *)cell + s_off))->f_6 = elev;
    if (sw != 0) ((ZoneCell *)((char *)cell + sw_off))->f_6 = elev;
    if (w != 0) ((ZoneCell *)((char *)cell - 28))->f_6 = elev;
}

static inline int check_corner_nw(int nw, int ne, int n, int e, int sw, int w, int s, int se) {
    if (nw == 0) return 0;
    if (ne != 0 && n == 0) return 1;
    if (e != 0 && ne == 0) return 1;
    if (sw != 0 && w == 0) return 1;
    if (s != 0 && sw == 0) return 1;
    if (se != 0 && s == 0 && e == 0) return 1;
    return 0;
}

static inline int check_corner_ne(int ne, int se, int e, int s, int nw, int n, int w, int sw) {
    if (ne == 0) return 0;
    if (se != 0 && e == 0) return 1;
    if (s != 0 && se == 0) return 1;
    if (nw != 0 && n == 0) return 1;
    if (w != 0 && nw == 0) return 1;
    if (sw != 0 && w == 0 && s == 0) return 1;
    return 0;
}

static inline int check_corner_se(int se, int sw, int s, int w, int ne, int e, int n, int nw) {
    if (se == 0) return 0;
    if (sw != 0 && s == 0) return 1;
    if (w != 0 && sw == 0) return 1;
    if (ne != 0 && e == 0) return 1;
    if (n != 0 && ne == 0) return 1;
    if (nw != 0 && n == 0 && w == 0) return 1;
    return 0;
}

static inline int check_corner_sw(int sw, int nw, int w, int n, int se, int s, int e, int ne) {
    if (sw == 0) return 0;
    if (nw != 0 && w == 0) return 1;
    if (n != 0 && nw == 0) return 1;
    if (se != 0 && s == 0) return 1;
    if (e != 0 && se == 0) return 1;
    if (ne != 0 && e == 0 && n == 0) return 1;
    return 0;
}

extern "C" void func_001CBFE0(void *self, int x0, int y0, int x1, int y1, int max_slope) {
    ZoneLayout *zm = (ZoneLayout *)self;
    short stride_param = *(short *)((char *)self + 8);

    short v0_a1 = 1 - stride_param;
    short v0_neg = -stride_param;
    short v0_plus1 = stride_param + 1;
    short v0_minus1 = stride_param - 1;
    short v1_sub = -1 - stride_param;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= zm->width) x1 = zm->width - 1;
    if (y1 >= zm->height) y1 = zm->height - 1;

    int north_off = (v0_neg * 8 - v0_neg) * 4;
    int south_off = (stride_param * 8 - stride_param) * 4;
    int nw_off = (v1_sub * 8 - v1_sub) * 4;
    int ne_off = (v0_a1 * 8 - v0_a1) * 4;
    int sw_off = (v0_minus1 * 8 - v0_minus1) * 4;
    int se_off = (v0_plus1 * 8 - v0_plus1) * 4;
    unsigned char limit = (unsigned char)max_slope;

    int modified;
    do {
        x0 -= 2; y0 -= 2; x1 += 2; y1 += 2;
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 >= zm->width) x1 = zm->width - 1;
        if (y1 >= zm->height) y1 = zm->height - 1;

        modified = 0;
        func_001CBB90(zm, x0, y0, x1, y1, max_slope);

        for (int y = y0; y <= y1; y++) {
            int x0_off = (x0 * 8 - x0) * 4;
            ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x0_off);

            for (int x = x0; x <= x1; x++) {
                int north_flag = 0, south_flag = 0, west_flag = 0, east_flag = 0;
                int nw_flag = 0, ne_flag = 0, sw_flag = 0, se_flag = 0;
                unsigned char elev = (unsigned char)cell->f_6;

                if (y > 0 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell + north_off))->f_6) north_flag = 1;
                if (y < zm->height - 1 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell + south_off))->f_6) south_flag = 1;
                if (x > 0 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell - 28))->f_6) west_flag = 1;
                if (x < zm->width - 1 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell + 28))->f_6) east_flag = 1;

                if (y > 0) {
                    if (x > 0 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell + nw_off))->f_6) nw_flag = 1;
                    if (x < zm->width - 1 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell + ne_off))->f_6) ne_flag = 1;
                }
                if (y < zm->height - 1) {
                    if (x > 0 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell + sw_off))->f_6) sw_flag = 1;
                    if (x < zm->width - 1 && (int)elev < (int)(unsigned char)((ZoneCell *)((char *)cell + se_off))->f_6) se_flag = 1;
                }

                int flag = 0;
                if (check_corner_nw(nw_flag, ne_flag, north_flag, east_flag, sw_flag, west_flag, south_flag, se_flag) != 0) flag = 1;
                if (check_corner_ne(ne_flag, se_flag, east_flag, south_flag, nw_flag, north_flag, west_flag, sw_flag) != 0) flag = 1;
                if (check_corner_se(se_flag, sw_flag, south_flag, west_flag, ne_flag, east_flag, north_flag, nw_flag) != 0) flag = 1;
                if (check_corner_sw(sw_flag, nw_flag, west_flag, north_flag, se_flag, south_flag, east_flag, ne_flag) != 0) flag = 1;

                if (flag != 0) {
                    if ((int)elev < (int)limit) {
                        cell->f_6 = (char)(elev + 1);
                        modified = 1;
                    } else {
                        level_neighbors(cell, nw_flag, north_flag, ne_flag, east_flag, se_flag, south_flag, sw_flag, west_flag,
                                        nw_off, north_off, ne_off, se_off, south_off, sw_off, (char)elev);
                        modified = 1;
                    }
                }
                cell = (ZoneCell *)((char *)cell + 28);
            }
        }

        if (func_001CB6D0(zm, x0, y0, x1, y1, max_slope) != 0) {
            modified = 1;
        }
    } while (modified != 0);

    func_001CF3E0(zm, x0, y0, x1, y1, 0, 0, 0);
}
