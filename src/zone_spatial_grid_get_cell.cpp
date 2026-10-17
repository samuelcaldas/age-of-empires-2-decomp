#pragma exceptions off

#include "zone_spatial_grid_get_cell.h"

struct GridBuffer {
    int count;
    char pad[0x8];
    int *data;
};

extern "C" int func_001E5350(const GridBuffer *self, int index) {
    if (index < 0 || index >= self->count) {
        return -1;
    }
    return self->data[index];
}
