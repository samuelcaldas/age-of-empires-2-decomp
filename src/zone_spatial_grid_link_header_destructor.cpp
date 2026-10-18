#pragma exceptions off
#include "zone_spatial_grid_link_header_destructor.h"

extern "C" {
void func_1EC9E0(void *self);
void func_100670(void *ptr);
}

extern "C" void *func_001EC990(void *self, int flag) {
    if (self == 0) {
        return 0;
    }
    func_1EC9E0(self);
    if (flag > 0) {
        func_100670(self);
    }
    return self;
}
