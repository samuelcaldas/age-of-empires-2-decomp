#pragma exceptions off

#include "zone_spatial_pyramid_raycast.h"

extern "C" {
int func_123350(float f);
int func_1D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2);
}

extern "C" int func_001D2DE0(
    void *self, void *mgr, float x0, float y0, float z0, float x1, float y1, float z1,
    void *out1, void *out2
) {
    int ix0 = func_123350(x0);
    int iy0 = func_123350(y0);
    int ix1 = func_123350(x1);
    int iy1 = func_123350(y1);

    int hit = func_1D3310(self, ix0, iy0, ix1, iy1, out1, out2);
    if (hit == 0) {
        return 0;
    }
    return 1;
}
