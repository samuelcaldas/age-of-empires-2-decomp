#pragma exceptions off
#include "render_manager_chat_methods.h"

extern "C" {

void *func_001890a0(ChatLog *self, int idx) {
    if (idx < 0 || idx > 50) {
        return 0;
    }
    return self->field_54[idx];
}

void func_001890e0(ChatLog *self) {
    for (int i = 0; i <= 50; i++) {
        void **p = &self->field_54[i];
        if (*p != 0) {
            func_116F68(*p);
        }
        *p = 0;
    }
    self->field_124 = 0;
}

void func_00189150(ChatLog *self, int val) {
    self->field_0 = val;
}

void func_00189160(ChatLog *self, int idx, int val) {
    if (idx > 0 && idx < 10) {
        self->field_4[idx] = val;
    }
}

int func_00189190(ChatLog *self, int idx) {
    if (idx < 0 || idx > 9) {
        return 0;
    }
    return self->field_4[idx];
}

int func_001891d0(ChatLog *self, int idx) {
    if (idx < 0 || idx > 9) {
        return 0;
    }
    return self->field_2C[idx];
}

void func_00189200() {}

void func_00189210() {}

int func_00189220() {
    return 1;
}

int func_00189230(ChatLog *self) {
    return self->field_124;
}

int func_00189240() {
    return 50;
}

int func_00189250(ChatLog *self) {
    return self->field_120;
}

}
