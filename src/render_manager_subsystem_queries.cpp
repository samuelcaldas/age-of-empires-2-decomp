#pragma exceptions off

#include "render_manager_subsystem_queries.h"

extern "C" {
int func_00186000(void *unused, int a1) {
    (void)unused;
    return func_225560(a1);
}

void *func_00186010(RenderManagerSubsystemQueries *self) {
    SubObj404E *sub = self->field_404;
    if (sub == 0) {
        return 0;
    }
    if (sub->field_50 <= 0) {
        return 0;
    }
    if (sub->field_98 < sub->field_50) {
        if (sub->field_98 >= 0) {
            goto found;
        }
    }
    return 0;
found:
    return sub->field_54[sub->field_98];
}

int func_00186080(RenderManagerSubsystemQueries *self, int a1) {
    for (int i = 0; i < 9; i++) {
        if (a1 == self->field_9CC[i]) {
            return i;
        }
    }
    return -1;
}

int func_001860c0(RenderManagerSubsystemQueries *self) {
    return func_225E80(self->field_2C);
}

void func_001860d0(RenderManagerSubsystemQueries *self) {
    if (!self->field_1E4) {
        func_1DB7D0(self->field_1D8);
        self->field_1E4 = 1;
    }
}

void func_00186110(RenderManagerSubsystemQueries *self) {
    if (self->field_1E4 != 0) {
        func_1DB7C0(self->field_1D8);
        self->field_1E4 = 0;
    }
}

void func_00186150(RenderManagerSubsystemQueries *self, int a1) {
    if (self->field_7C != 0) {
        self->field_1E8 = a1;
    } else {
        self->field_1E8 = 1;
    }
    if (a1 != 0) {
        func_1DB7D0(self->field_1D8);
        func_224300(0);
    }
}

void func_001861a0(RenderManagerSubsystemQueries *self, int a1) {
    self->field_1EC = a1;
    if (a1 != 0) {
        D_004E8980 = a1;
    }
}

int func_001861c0(RenderManagerSubsystemQueries *self) {
    return func_1DB760(self->field_1D8);
}
}
