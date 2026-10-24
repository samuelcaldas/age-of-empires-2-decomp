#pragma exceptions off
#include "unit_action_build_d10.h"

extern "C" {
    void func_00194D00(void *self, void *target, int flag1, int zero);
    void func_0026AD60(void *self, int flag);
    void func_00117CAC(void *dst, int val, int size);
    void func_00273130(void *self, void *target, int flag1);
}

static void init_d10_state(void *self) {
    *(short *)((char *)self + 0x10C) = 0;
    *(char *)((char *)self + 0x118) = 0;
    *(short *)((char *)self + 0x10E) = -1;
    *(float *)((char *)self + 0x110) = -1.0f;
    *(float *)((char *)self + 0x114) = -1.0f;
    *(int *)((char *)self + 0x120) = 0;
    *(char *)((char *)self + 0x11A) = 0;
    *(short *)((char *)self + 0x124) = 0;
    *(char *)((char *)self + 0x119) = 0;
}

void func_00272D10(void *self, void *target, int flag1, int flag2) {
    func_00194D00(self, target, flag1, 0);

    func_0026AD60(self, 0x100);
    func_0026AD60(self, 0x400);

    init_d10_state(self);
    func_00117CAC((char *)self + 0x100, 0, 12);

    if (flag2 != 0) {
        func_00273130(self, target, flag1);
    }
}
