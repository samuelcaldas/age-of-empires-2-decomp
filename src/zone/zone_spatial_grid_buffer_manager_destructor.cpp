#pragma exceptions off
#include "zone_spatial_grid_buffer_manager_destructor.h"

extern "C" {
void func_100670(void *ptr);
}

extern "C" void *func_001ECB90(void *self, int flag) {
    if (self != 0 && flag > 0) {
        func_100670(self);
    }
    return self;
}
