#pragma exceptions off

#include "zone_spatial_update_rect_cb.h"

extern "C" {
void func_1D7DD0(void *self, int x0, int y0, int x1, int y1);
}

extern "C" void func_001D7E70(void *self, int x0, int y0, int x1, int y1) {
    if (self != 0) {
        func_1D7DD0(self, x0, y0, x1, y1);
    }
}
