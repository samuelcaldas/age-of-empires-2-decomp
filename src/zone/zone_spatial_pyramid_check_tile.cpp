#pragma exceptions off

#include "zone_spatial_pyramid_check_tile.h"

extern "C" void func_001D29F0(void *self, int x, int y, void *out_flag) {
    char *zm = (char *)self;
    char **rows = *(char ***)(zm + 0x98);
    char *cell = rows[y] + x * 28;
    unsigned char terrain = *(unsigned char *)(cell + 5);

    float *thresholds = *(float **)(zm + 0x9C);
    if (thresholds != 0) {
        float thresh = thresholds[terrain];
        if (thresh <= 0.0f) {
            *(char *)out_flag = 0;
            return;
        }
    }

    *(char *)out_flag = 1;
}
