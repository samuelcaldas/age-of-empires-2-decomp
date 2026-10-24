#pragma exceptions off
#include "unit_action_build_e10.h"

extern "C" {
    void func_00272DD0(void *self, void *arg1);
    void func_00194E20(void *self, void *arg1);
    void func_00100670(void *ptr);
}

void *func_00272E10(void *self, int flags) {
    if (self == 0) {
        return 0;
    }

    *(void **)self = (void *)0x4E8CE0;
    func_00272DD0(self, 0);
    func_00194E20(self, 0);

    if ((short)flags > 0) {
        func_00100670(self);
    }
    return self;
}
