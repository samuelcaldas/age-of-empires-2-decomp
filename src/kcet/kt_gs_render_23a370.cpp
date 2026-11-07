#include "kt_gs_render_23a370.h"

extern "C" {

void func_002D5000(...);

int func_0023A370(Struct23A370 *self, int a1) {
    if (a1 < 0 || a1 >= 9) {
        return 0;
    }
    int val = self->field_18F0[a1];
    switch (val) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        case 5: return 5;
        default: return 0;
    }
}

char *func_0023A400(char *self, int a1) {
    return self + (a1 << 8) + 0x10;
}

int func_0023A410(Struct23A370 *self, int a1) {
    if (a1 < 0 || a1 >= 16) {
        return 0;
    }
    return self->field_1930[a1];
}

int func_0023A450(Struct23A370 *self, int a1) {
    if (a1 < 0 || a1 >= 16) {
        return 0;
    }
    return self->field_1970[a1];
}

int func_0023A490(Struct23A370 *self, int a1) {
    if (a1 < 0 || a1 >= 16) {
        return 0;
    }
    return self->field_19B0[a1];
}

void func_0023A4D0(void **self) {
    if (*self != 0) {
        func_002D5000(*self);
    }
}

}
