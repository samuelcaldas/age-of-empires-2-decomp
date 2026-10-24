#pragma exceptions off
#include "unit_action_build_dd0.h"

extern "C" {
    void func_00272A88(void *self, float amount);
    void func_00194D70(void *self, void *arg1);
}

void func_00272DD0(void *self, void *arg1) {
    func_00272A88(self, -1.0f);
    if (arg1 != 0) {
        func_00194D70(self, arg1);
    }
}
