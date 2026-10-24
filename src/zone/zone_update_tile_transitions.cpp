#pragma exceptions off

#include "zone_update_tile_transitions.h"

extern "C" {
void func_1D1CC0(void *self, void *cell);
}

extern "C" void func_001D00C0(void *self, int x, int y) {
    char *zm = (char *)self;
    int width = *(int *)(zm + 0x8);
    int height = *(int *)(zm + 0xC);

    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }

    char *cells_base = *(char **)(zm + 0x8E8C);
    char *center_cell = *(char **)(cells_base + y * 4) + x * 28;
    unsigned char terrain = *(unsigned char *)(center_cell + 5);

    char *entry = zm + terrain * 416;
    short fallback = *(short *)(entry + 0x14C);
    if (fallback != -1) {
        terrain = (unsigned char)fallback;
        entry = zm + terrain * 416;
    }

    if (*(int *)(center_cell + 0x10) != 0) {
        func_1D1CC0(self, center_cell);
    }

    for (int dy = y - 1; dy <= y + 1; dy++) {
        if (dy < 0 || dy >= height) {
            continue;
        }

        for (int dx = x - 1; dx <= x + 1; dx++) {
            if (dx < 0 || dx >= width) {
                continue;
            }

            char *cell = *(char **)(cells_base + dy * 4) + dx * 28;
            unsigned char n_terrain = *(unsigned char *)(cell + 5);

            char *n_entry = zm + n_terrain * 416;
            short n_fallback = *(short *)(n_entry + 0x14C);
            if (n_fallback != -1) {
                n_terrain = (unsigned char)n_fallback;
            }

            if (*(int *)(cell + 0x10) != 0) {
                func_1D1CC0(self, cell);
            }
        }
    }
}
