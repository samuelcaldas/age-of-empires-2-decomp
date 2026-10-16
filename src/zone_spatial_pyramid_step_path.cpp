#pragma exceptions off

#include "zone_spatial_pyramid_step_path.h"

extern "C" {
int func_1D5A30(void *self, int x, int y);
}

extern "C" int func_001D5610(void *self, int x0, int y0, int x1, int y1, void *out1, void *out2) {
    if (func_1D5A30(self, x0, y0) != 0) {
        return 1;
    }
    return 0;
}
