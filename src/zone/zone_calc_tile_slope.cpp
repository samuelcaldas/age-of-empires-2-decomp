#pragma exceptions off

#include "zone_calc_tile_slope.h"

extern "C" unsigned char func_001CFCD0(void *self, int x, int y) {
    char *zm = (char *)self;
    int width = *(int *)(zm + 0x8);
    int height = *(int *)(zm + 0xC);

    if (x < 0 || x >= width || y < 0 || y >= height) {
        return 0;
    }

    char *cells_base = *(char **)(zm + 0x8E8C);
    char *center_cell = *(char **)(cells_base + y * 4) + x * 28;
    int elev = *(unsigned char *)(center_cell + 6);

    int elev_plus_1 = elev + 1;
    int elev_minus_1 = elev - 1;

    // Helper to safely read neighbor elevation with out-of-bounds fallback to center elev
    int n_elev = (y > 0) ? *(unsigned char *)(*(char **)(cells_base + (y - 1) * 4) + x * 28 + 6) : elev;
    int s_elev = (y < height - 1) ? *(unsigned char *)(*(char **)(cells_base + (y + 1) * 4) + x * 28 + 6) : elev;
    int e_elev = (x < width - 1) ? *(unsigned char *)(*(char **)(cells_base + y * 4) + (x + 1) * 28 + 6) : elev;
    int w_elev = (x > 0) ? *(unsigned char *)(*(char **)(cells_base + y * 4) + (x - 1) * 28 + 6) : elev;

    int nw_elev = (x > 0 && y > 0) ? *(unsigned char *)(*(char **)(cells_base + (y - 1) * 4) + (x - 1) * 28 + 6) : elev;
    int ne_elev = (x < width - 1 && y > 0) ? *(unsigned char *)(*(char **)(cells_base + (y - 1) * 4) + (x + 1) * 28 + 6) : elev;
    int sw_elev = (x > 0 && y < height - 1) ? *(unsigned char *)(*(char **)(cells_base + (y + 1) * 4) + (x - 1) * 28 + 6) : elev;
    int se_elev = (x < width - 1 && y < height - 1) ? *(unsigned char *)(*(char **)(cells_base + (y + 1) * 4) + (x + 1) * 28 + 6) : elev;

    if (n_elev == elev_plus_1 && e_elev == elev_plus_1) return 14;
    if (w_elev == elev_plus_1 && s_elev == elev_plus_1) return 13;
    if (n_elev == elev_plus_1 && w_elev == elev_plus_1) return 16;
    if (e_elev == elev_plus_1 && s_elev == elev_plus_1) return 15;

    if (n_elev == elev_plus_1) return 6;
    if (e_elev == elev_plus_1) return 8;
    if (w_elev == elev_plus_1) return 5;
    if (s_elev == elev_plus_1) return 7;

    if (nw_elev == elev_plus_1) {
        if (w_elev == elev_minus_1 && s_elev == elev_minus_1) return 2;
        return 10;
    }
    if (ne_elev == elev_plus_1) {
        if (n_elev == elev_minus_1 && e_elev == elev_minus_1) return 1;
        return 9;
    }
    if (se_elev == elev_plus_1) {
        if (e_elev == elev_minus_1 && s_elev == elev_minus_1) return 3;
        return 11;
    }
    if (sw_elev == elev_plus_1) {
        if (n_elev == elev_minus_1 && w_elev == elev_minus_1) return 4;
        return 12;
    }

    return 0;
}
