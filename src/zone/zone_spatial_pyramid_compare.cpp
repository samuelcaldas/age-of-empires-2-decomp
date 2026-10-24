#pragma exceptions off

#include "zone_spatial_pyramid_compare.h"

extern "C" int func_001D20D0(void *self, const float *values, int count) {
    char *zm = (char *)self;
    int self_count = *(int *)(zm + 0xA0);
    if (self_count != count) {
        return 1;
    }

    float *arr = *(float **)(zm + 0x9C);
    for (int i = 0; i < self_count; i++) {
        if (arr[i] != values[i]) {
            return 0;
        }
    }

    return 1;
}
