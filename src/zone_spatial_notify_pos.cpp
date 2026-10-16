#pragma exceptions off

#include "zone_spatial_notify_pos.h"

extern "C" {
void func_194C60(void *self, void *arg1, void *arg2, int zero, float x, float y, float z);
void func_1D8520(void *self, void *arg1, void *arg2, float x, float y, float z);
}

extern "C" void func_001D8370(void *self, void *arg1, void *arg2, int flag, float x, float y, float z) {
    func_194C60(self, arg1, arg2, 0, x, y, z);
    if (flag != 0) {
        func_1D8520(self, arg1, arg2, x, y, z);
    }
}
