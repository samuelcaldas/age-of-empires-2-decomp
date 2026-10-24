#include "sub_list.h"

struct TacticalNode {
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    char field_D;
    char field_E;
    char field_F;
    void *field_10;
    char field_14;
    char field_15;
    char field_16;
    char field_17;
};

extern "C" {

int func_144544(TacticalNode *self, int a1, int a2, int a3, int t0) {
    switch (self->field_0) {
    case 1:
        switch (self->field_C) {
        case 0:
            self->field_8 = ((int (*)())self->field_10)();
            break;
        case 1:
            self->field_8 = ((int (*)(int))self->field_10)(a1);
            break;
        case 2:
            self->field_8 = ((int (*)(int, int))self->field_10)(a1, a2);
            break;
        case 3:
            self->field_8 = ((int (*)(int, int, int))self->field_10)(a1, a2, a3);
            break;
        case 4:
            self->field_8 = ((int (*)(int, int, int, int))self->field_10)(a1, a2, a3, t0);
            break;
        default:
            break;
        }
        return self->field_8;
    case 2:
        if (self->field_4 == 0) goto eval;
        return self->field_8;
    eval:
        self->field_8 = ((int (*)())self->field_10)();
        self->field_4 = 1;
        return self->field_8;
    case 3:
        return self->field_8;
    default:
        return self->field_8;
    }
}

int func_00144694(TacticalNode *self) {
    return self->field_C;
}

}
