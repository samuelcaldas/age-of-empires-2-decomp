#pragma exceptions off

#include "render_manager_device.h"

extern "C" {
int func_344580(void *dev);
int func_344840(void *dev);
int func_3448D0(void *dev);
int func_3447F0(void *dev);
int func_3445F0(void *dev);
int func_3445C0(void *dev, int a1);
int func_344640(void *dev, int a1, int a2);
int func_344920(void *dev);

void func_00185030(RenderManagerDevice *self) {
    void *dev = self->device;
    if (dev != 0) {
        func_344580(dev);
    }
}

void func_00185060(RenderManagerDevice *self, int *out1, int *out2, int *out3) {
    *out1 = func_344840(self->device);
    *out2 = func_3448D0(self->device);
    *out3 = func_3447F0(self->device);
}

int func_001850d0(RenderManagerDevice *self, int unused, int arg2, int arg3) {
    (void)unused;
    if (func_3445F0(self->device)) {
        if (func_3445C0(self->device, arg2)) {
            if (func_344640(self->device, arg3, 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int func_00185150(RenderManagerDevice *self) {
    return func_344920(self->device);
}
}
