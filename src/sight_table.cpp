#include "sight_table.h"

extern "C" {
    extern void *D_0038FA40[];
    extern void *D_0038FAA0[];
}

void* func_00137A40(void *self, int radius, int mode) {
    (void)self;
    if (radius > 20) {
        radius = 20;
    }
    if (radius < 0) {
        radius = 0;
    }
    if (mode) {
        return D_0038FAA0[radius];
    }
    return D_0038FA40[radius];
}
