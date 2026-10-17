#pragma exceptions off

#include "zone_spatial_grid_realloc_buffer.h"

struct GridBuffer {
    char pad[0x10];
};

extern "C" void func_001E5390(GridBuffer *self, int new_count) {
}
