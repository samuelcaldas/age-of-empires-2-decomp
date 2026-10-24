#pragma exceptions off

#include "zone_spatial_pyramid_search_radius.h"

extern "C" {
int func_123350(float f);
int func_1D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2);
}

extern "C" int func_001D3C70(void *self, void *mgr, float x, float y, float r1, float r2) {
    float total_r = r1 + r2;
    int ix0 = func_123350(x - total_r);
    int iy0 = func_123350(y - total_r);
    int ix1 = func_123350(x + total_r);
    int iy1 = func_123350(y + total_r);

    return func_1D3310(self, ix0, iy0, ix1, iy1, 0, 0);
}
