#pragma exceptions off

#include "zone_spatial_node_dtor.h"

extern "C" {
void func_1D7B20(void *self);
void func_100670(void *ptr);
}

extern "C" void *func_001D7AC0(void *self, int flag) {
    if (self == 0) {
        return 0;
    }

    func_1D7B20(self);

    if ((short)flag > 0) {
        func_100670(self);
    }

    return self;
}
