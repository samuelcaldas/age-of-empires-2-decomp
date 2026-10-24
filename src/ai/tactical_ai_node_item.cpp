#include "sub_list.h"

#pragma exceptions off

struct TacticalNode {
    int field_0;
    int field_4;
    int field_8;
    char field_C;
    int (*field_10)();
    char field_14;
    char field_15;
    char field_16;
    char field_17;
};

extern "C" {

void func_00100670(void *ptr);

TacticalNode *func_00144434(TacticalNode *self) {
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_15 = 0;
    self->field_16 = 0;
    self->field_17 = 0;
    return self;
}

TacticalNode *func_00144464(TacticalNode *self, int a1) {
    if (self) {
        self->field_10 = 0;
        if ((short)a1 > 0) {
            func_00100670(self);
        }
    }
    return self;
}

void func_001444B4(TacticalNode *self, int a1) {
    self->field_0 = a1;
    self->field_4 = 0;
    self->field_8 = 0;
}

void func_001444C0(TacticalNode *self, int unused, char a2, int (*a3)(), char t0, char t1, char t2, char t3) {
    self->field_C = a2;
    self->field_10 = a3;
    self->field_14 = t0;
    self->field_15 = t1;
    self->field_16 = t2;
    self->field_17 = t3;
}

void func_001444E4(TacticalNode *self) {
    if (self->field_0 == 3) {
        self->field_8 = self->field_10();
    }
}

void func_001444F0(TacticalNode *self) {
    if (self->field_0 == 3) {
        self->field_8 = self->field_10();
    }
}

void func_00144524(TacticalNode *self) {
    if (self->field_0 == 2) {
        self->field_4 = 0;
    }
}

void func_00144530(TacticalNode *self) {
    self->field_4 = 0;
}

int func_144550(TacticalNode *self, int a1, int a2, int a3, int t0) {
    if (self->field_0 == 3) {
        return self->field_8;
    }
    if (self->field_0 == 2) {
        if (!self->field_4) {
            self->field_8 = self->field_10();
            self->field_4 = 1;
        }
        return self->field_8;
    }
    if (self->field_0 == 1) {
        switch (self->field_C) {
        case 4:
            self->field_8 = ((int (*)(int, int, int, int))self->field_10)(a1, a2, a3, t0);
            break;
        case 3:
            self->field_8 = ((int (*)(int, int, int))self->field_10)(a1, a2, a3);
            break;
        case 2:
            self->field_8 = ((int (*)(int, int))self->field_10)(a1, a2);
            break;
        case 1:
            self->field_8 = ((int (*)(int))self->field_10)(a1);
            break;
        case 0:
            self->field_8 = self->field_10();
            break;
        }
        return self->field_8;
    }
    return self->field_8;
}

int func_001446A0(TacticalNode *self) {
    return (unsigned char)self->field_C;
}

}
