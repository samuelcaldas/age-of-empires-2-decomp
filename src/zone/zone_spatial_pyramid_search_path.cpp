#pragma exceptions off

#include "zone_spatial_pyramid_search_path.h"

extern "C" {
int func_1D5610(void *self, int x0, int y0, int x1, int y1, void *out1, void *out2);
}

extern "C" int func_001D51B0(void *self, int x0, int y0, int x1, int y1, void *out1, void *out2) {
    return func_1D5610(self, x0, y0, x1, y1, out1, out2);
}
