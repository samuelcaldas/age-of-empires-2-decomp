#pragma exceptions off

#include "zone_spatial_pyramid_search_step.h"

extern "C" int func_001D3880(void *self, int level, int x, int y, float f12, int t0, int mask) {
    char *zm = (char *)self;
    void ***root = *(void ****)(zm + 0x0);
    char *cell = (char *)root[level][x] + y * 2;

    unsigned char c = (unsigned char)cell[0];
    if ((c & (unsigned char)mask) != 0) {
        return 1;
    }
    return 0;
}
