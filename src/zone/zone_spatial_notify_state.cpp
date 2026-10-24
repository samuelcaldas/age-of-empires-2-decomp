#pragma exceptions off

#include "zone_spatial_notify_state.h"

extern "C" {
void func_194D00(void *self, void *arg1, void *arg2, int zero);
void func_1D8550(void *self, void *arg1, void *arg2);
}

extern "C" void func_001D8410(void *self, void *arg1, void *arg2, int flag) {
    func_194D00(self, arg1, arg2, 0);
    if (flag != 0) {
        func_1D8550(self, arg1, arg2);
    }
}
