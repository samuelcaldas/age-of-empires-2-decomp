#pragma exceptions off

#include "zone_spatial_grid_reset_cells.h"

struct GridBuffer {
    int count;
    char pad[0x8];
    int *data;
};

extern "C" void func_001E5310(GridBuffer *self) {
    for (int i = 0; i < self->count; i++) {
        self->data[i] = -1;
    }
}
