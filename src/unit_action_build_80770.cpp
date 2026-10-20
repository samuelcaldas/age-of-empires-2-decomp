#pragma exceptions off
#include "unit_action_build_80770.h"

extern "C" {
    extern void *__vt__004DC9F0;
    void func_138A50(void *self, int arg1);
    void func_100670(void *self);
}

void *func_00280770(void *self, short count) {
    if (self != 0) {
        *(void **)self = &__vt__004DC9F0;
        func_138A50(self, 0);
        if (count > 0) {
            func_100670(self);
        }
    }
    return self;
}
