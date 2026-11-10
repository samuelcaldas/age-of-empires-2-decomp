#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_destructor.h"

extern "C" {
void func_100670(void *ptr);
}

extern "C" void *func_001ECB90(void *self, short flag) {
    if (self != 0) {
        if (flag > 0) {
            func_100670(self);
        }
    }
    return self;
}
