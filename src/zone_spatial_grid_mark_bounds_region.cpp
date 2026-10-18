#pragma exceptions off
#include "zone_spatial_grid_mark_bounds_region.h"

struct SpatialGrid {
    char pad_00[0x12B424];
    int width;
    int height;
    char pad_12B42C[8];
    void *table1;
    int **grid_table;
    char pad_after[0x12B59E - 0x12B438 - 4];
    unsigned char has_margin;
    char pad_align;
    float margin;
};

extern "C" int func_001EE360(SpatialGrid *self, float fx0, float fy0, float fx1, float fy1, int flag) {
    int mask = (unsigned char)flag;
    float min_x, max_x, min_y, max_y;

    if (fx0 < fx1) {
        mask |= 0x80;
        min_x = fx0;
        max_x = fx1;
    } else {
        min_x = fx1;
        max_x = fx0;
    }

    if (fy0 < fy1) {
        min_y = fy0;
        max_y = fy1;
    } else {
        min_y = fy1;
        max_y = fy0;
    }

    if (self->has_margin != 0) {
        float m = self->margin;
        min_x -= m;
        min_y -= m;
        max_x += m;
        max_y += m;
    }

    int i_min_x = func_123350(min_x);
    if (i_min_x < 0) {
        i_min_x = 0;
    }
    int i_max_x = func_123350(max_x);
    if (i_max_x >= self->width) {
        i_max_x = self->width - 1;
    }

    int i_min_y = func_123350(min_y);
    if (i_min_y < 0) {
        i_min_y = 0;
    }
    int i_max_y = func_123350(max_y);
    if (i_max_y >= self->height) {
        i_max_y = self->height - 1;
    }

    for (int y = i_min_y; y <= i_max_y; ++y) {
        int *row = self->grid_table[y];
        for (int x = i_min_x; x <= i_max_x; ++x) {
            if ((row[x] & mask) != 0) {
                continue;
            }
            func_1EE130(self, x, y);
        }
    }
    return 1;
}
