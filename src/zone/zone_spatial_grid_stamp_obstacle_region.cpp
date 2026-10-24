#pragma exceptions off
#include "zone_spatial_grid_stamp_obstacle_region.h"

typedef void (*ObstacleCallback)(void *ctx);

struct SpatialGrid {
    char pad_00[0x12B438];
    int **grid_table;
    char pad_after[0x12B5A4 - 0x12B438 - 4];
    ObstacleCallback callback_fn;
    void *callback_ctx;
};

extern "C" int func_001EE5B0(SpatialGrid *self, int min_x, int min_y, int max_x, int max_y, int type, int id) {
    int val = ((type << 8) & 0x3F00) | 0x4000 | (id << 16);
    if (type == 5) {
        val |= 0x8000;
    }

    for (int y = min_y; y <= max_y; ++y) {
        int *row = self->grid_table[y];
        for (int x = min_x; x <= max_x; ++x) {
            unsigned char low = *(unsigned char *)&row[x];
            row[x] = low | val;
        }
    }

    if (self->callback_fn != 0) {
        self->callback_fn(self->callback_ctx);
    }
    return 1;
}
