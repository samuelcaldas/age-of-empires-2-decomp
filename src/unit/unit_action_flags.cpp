#pragma exceptions off
#include "unit_action_flags.h"

void func_0026AC40(ActionRebind *self, int arg1) {
    if (self == 0) {
        return;
    }
    if (arg1 == 2) {
        return;
    }
    func_26AD30(self, 1);
}

int func_0026AD10(ActionRebind *self) {
    return func_00268530(self);
}

char func_26AD20(void *action, int flag) {
    return (*(unsigned short*)((char*)action + 0x3E) & flag) != 0;
}

void func_26AD30(void *action, int flag) {
    if (action != 0) {
        *(unsigned short*)((char*)action + 0x3E) |= (unsigned short)flag;
    }
}

void func_26AD60(void *action, int flag) {
    if (action != 0) {
        *(unsigned short*)((char*)action + 0x3E) &= (unsigned short)~flag;
    }
}

float func_0026AD80() {
    return 0.0f;
}

void func_0026AD90(void *action, void *val) {
    if (action != 0) {
        *(void**)((char*)action + 0) = val;
    }
}
