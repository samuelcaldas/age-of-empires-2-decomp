#pragma exceptions off

#include "zone_spatial_pyramid_reset_level3.h"

extern "C" {
int func_1D21B0(void *self, int level, int x, int y);
}

extern "C" void func_001D2140(void *self) {
    char *zm = (char *)self;
    int s0 = *(int *)(zm + 0xD0);
    while (s0 >= 0) {
        int s1 = *(int *)(zm + 0xE0);
        while (s1 >= 0) {
            func_1D21B0(self, 3, s0, s1);
            s1--;
        }
        s0--;
    }
}
