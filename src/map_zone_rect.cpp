#include "map_zone_rect.h"

extern "C" {
    extern int D_004E3058;
    extern int *D_50A5A0[];
}

void func_00138320(ZoneMapLos *self, int min_x, int min_y, int max_x, int max_y, int flag) {
    if (D_004E3058) {
        return;
    }
    char *tile28 = 0;
    int width = self->m_width;
    if (min_x >= width || max_x < 0) {
        return;
    }
    int height = self->m_height;
    if (min_y >= height || max_y < 0) {
        return;
    }
    if (min_x < 0) {
        min_x = 0;
    }
    if (max_x >= width) {
        max_x = width - 1;
    }
    if (min_y < 0) {
        min_y = 0;
    }
    if (max_y >= height) {
        max_y = height - 1;
    }

    int tile_col_offset = min_x * 28;
    int min_x_bytes = min_x * 4;
    for (int y = min_y; y <= max_y; y++) {
        int y_bytes = y * 4;
        int *flag_ptr = *(int**)((char*)D_50A5A0 + y_bytes) + min_x;
        unsigned char *tile_ptr = *(unsigned char**)((char*)self->m_row_ptrs + y_bytes) + min_x;
        if (flag) {
            tile28 = *(char**)((char*)self->m_fieldC->m_grid + y_bytes) + tile_col_offset;
        }
        for (int cur_x = min_x; cur_x <= max_x; cur_x++, tile_ptr++, flag_ptr++, tile28 += 28) {
            unsigned char val = *tile_ptr - 1;
            if (val == 255) {
                val = 0;
            }
            if (val == 254) {
                val = 255;
            }
            if (!val) {
                if (flag) {
                    tile28[9] = 128;
                }
                *flag_ptr &= self->m_field28;
            }
            *tile_ptr = val;
        }
    }
}
