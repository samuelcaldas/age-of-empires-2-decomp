#pragma once
#pragma exceptions off

#include "zone_blend_terrain.h"

extern "C" {
void func_1CF830(void *self, void *world, int x, int y, int terrain_type, int p5, int p6);
}

struct ZoneCell {
    char pad_0[5];
    char f_5;               // 0x5 (terrain type)
    char f_6;               // 0x6 (elevation)
    char pad_7[21];         // 28 bytes total
};

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    ZoneCell **cells_ptr;   // 0x8E8C (-0x7174)
    char pad_8E90[0x58];    // 0x8E90..0x8EE7
    void *m_world;          // 0x8EE8 (-0x7118)
};

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

extern "C" void func_001CC6E0(void *self, int x0, int y0, int x1, int y1, int terrain_param) {
    ZoneLayout *zm = (ZoneLayout *)self;
    short stride_param = *(short *)((char *)self + 8);

    short v0_a2 = 1 - stride_param;
    short v0_a1 = -stride_param;
    short v0_t2 = stride_param + 1;
    short v0_a0 = -1 - stride_param;
    short v0_t3 = stride_param - 1;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= zm->width) x1 = zm->width - 1;
    if (y1 >= zm->height) y1 = zm->height - 1;

    unsigned char target_terrain = (unsigned char)terrain_param;

    int north_off = (v0_a1 * 8 - v0_a1) * 4;
    int south_off = (stride_param * 8 - stride_param) * 4;
    int nw_off = (v0_a0 * 8 - v0_a0) * 4;
    int ne_off = (v0_a2 * 8 - v0_a2) * 4;
    int sw_off = (v0_t3 * 8 - v0_t3) * 4;
    int se_off = (v0_t2 * 8 - v0_t2) * 4;

    int modified;
    do {
        if (x0 > 0) x0--;
        if (y0 > 0) y0--;
        if (x1 < zm->width - 1) x1++;
        if (y1 < zm->height - 1) y1++;

        modified = 0;

        for (int pass = 0; pass < 2; pass++) {
            for (int y = y0; y <= y1; y++) {
                int x0_off = (x0 * 8 - x0) * 4;
                ZoneCell *cell = (ZoneCell *)((char *)zm->cells_ptr[y] + x0_off);

                for (int x = x0; x <= x1; x++) {
                    if ((unsigned char)cell->f_5 == target_terrain) {
                        cell = (ZoneCell *)((char *)cell + 28);
                        continue;
                    }

                    int north_match = 0, south_match = 0, west_match = 0, east_match = 0;
                    int nw_match = 0, ne_match = 0, sw_match = 0, se_match = 0;

                    if (y > 0 && (unsigned char)((ZoneCell *)((char *)cell + north_off))->f_5 == target_terrain) north_match = 1;
                    if (y < zm->height - 1 && (unsigned char)((ZoneCell *)((char *)cell + south_off))->f_5 == target_terrain) south_match = 1;
                    if (x > 0 && (unsigned char)((ZoneCell *)((char *)cell - 28))->f_5 == target_terrain) west_match = 1;
                    if (x < zm->width - 1 && (unsigned char)((ZoneCell *)((char *)cell + 28))->f_5 == target_terrain) east_match = 1;

                    if (pass != 0) {
                        if (y > 0) {
                            if (x > 0 && (unsigned char)((ZoneCell *)((char *)cell + nw_off))->f_5 == target_terrain) nw_match = 1;
                            if (x < zm->width - 1 && (unsigned char)((ZoneCell *)((char *)cell + ne_off))->f_5 == target_terrain) ne_match = 1;
                        }
                        if (y < zm->height - 1) {
                            if (x > 0 && (unsigned char)((ZoneCell *)((char *)cell + sw_off))->f_5 == target_terrain) sw_match = 1;
                            if (x < zm->width - 1 && (unsigned char)((ZoneCell *)((char *)cell + se_off))->f_5 == target_terrain) se_match = 1;
                        }
                    }

                    int match = 0;
                    if (pass == 0) {
                        if (north_match != 0 && south_match != 0) match = 1;
                        if (east_match != 0 && west_match != 0) match = 1;
                    } else {
                        if (check_corner_nw(nw_match, ne_match, north_match, east_match, sw_match, west_match, south_match, se_match) != 0) match = 1;
                        if (check_corner_ne(ne_match, se_match, east_match, south_match, nw_match, north_match, west_match, sw_match) != 0) match = 1;
                        if (check_corner_se(se_match, sw_match, south_match, west_match, ne_match, east_match, north_match, nw_match) != 0) match = 1;
                        if (check_corner_sw(sw_match, nw_match, west_match, north_match, se_match, south_match, east_match, ne_match) != 0) match = 1;
                    }

                    if (match != 0) {
                        func_1CF830(zm, zm->m_world, x, y, (int)target_terrain, 0, 0);
                        modified = 1;
                    }

                    cell = (ZoneCell *)((char *)cell + 28);
                }
            }
        }
    } while (modified != 0);
}
