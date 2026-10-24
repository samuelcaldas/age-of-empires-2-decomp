#pragma exceptions off
#include "zone_spatial_grid_vector_destructor.h"

extern "C" {
void func_1EB9C0(void *self);
void func_100670(void *ptr);
}

extern "C" void *func_001EB920(void *self, int flag) {
    if (self == 0) {
        return 0;
    }
    func_1EB9C0(self);
    if (flag > 0) {
        func_100670(self);
    }
    return self;
}
