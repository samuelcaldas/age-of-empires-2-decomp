#pragma exceptions off

#include "zone_spatial_grid_init_node_buffer.h"

extern "C" {
void func_100670();
}

extern "C" void *func_001E4050(void *self, short count) {
    if (self != 0) {
        if (count > 0) {
            func_100670();
        }
    }
    return self;
}
