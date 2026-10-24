#include "sub_list.h"

extern "C" {
char *func_0011ABBC(char *dst, const char *src);
extern const char D_490F1C[];
}

struct ErrorStruct {
    char msg1[0x104];
    int field_104;
    char msg2[0x80];
    int field_188;
};

struct ScopeContext {
    int field_0;
    char buf[0x400];
    char *field_6A8;
    int field_6AC;
    int field_6B0;
    int field_6B8;
    int field_6BC;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x194];
    int field_198;
    char pad_19C[0x108];
    int field_2A4;
    char field_2A8[0x400];
    char *field_6A8;
    int field_6AC;
    int field_6B0;
    ErrorStruct *field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    ScopeContext scopes[10];
    int field_2FB4;
    int field_2FB8[50];
};

extern "C" {

void func_1441B0(TacticalAI2 *self) {
    self->scopes[self->field_6C0].field_0 = self->field_2A4;
    self->scopes[self->field_6C0].field_6AC = self->field_6AC;
    self->scopes[self->field_6C0].field_6A8 = self->field_6A8;
    self->scopes[self->field_6C0].field_6B0 = self->field_6B0;
    func_0011ABBC(self->scopes[self->field_6C0].buf, self->field_2A8);
    self->scopes[self->field_6C0].field_6B8 = self->field_6B8;
    self->scopes[self->field_6C0].field_6BC = self->field_6BC;
    self->field_6C0++;
}

void func_1442E0(TacticalAI2 *self) {
    self->field_2FB8[self->field_2FB4] = self->field_198;
    self->field_2FB4++;
}

void func_144310(TacticalAI2 *self) {
    self->field_6B4->msg1[0] = 0;
    self->field_6B4->field_104 = -1;
    self->field_6B4->msg2[0] = 0;
    self->field_6B4->field_188 = 0x19;
}

void func_144340(TacticalAI2 *self, int a1, const char *a2) {
    if (!self->field_6B4) {
        return;
    }
    if (self->field_6AC) {
        func_0011ABBC(self->field_6B4->msg1, (char *)self->field_6AC);
    } else {
        func_0011ABBC(self->field_6B4->msg1, D_490F1C);
    }

    switch (a1) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 23:
    case 24:
    case 26:
        self->field_6B4->field_104 = self->field_6B0;
        break;
    case 1:
    case 18:
        self->field_6B4->field_104 = -1;
        break;
    default:
        self->field_6B4->field_104 = -1;
        a1 = 0x16;
        break;
    }

    if (a2) {
        func_0011ABBC(self->field_6B4->msg2, a2);
    } else {
        func_0011ABBC(self->field_6B4->msg2, D_490F1C);
    }

    self->field_6B4->field_188 = a1;
}

}
