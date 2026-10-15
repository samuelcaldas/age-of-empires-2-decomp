#pragma exceptions off
#include "sub_list.h"

struct TacticalAI2;

extern "C" {
extern const char D_48E100[];

int func_142980(void *self);
void func_144340(void *self, int code, void *param);
void *func_26B0A0(void *table, const char *name, int a2);
int func_00142CC0(void *self);
int func_00143020(TacticalAI2 *self, int a1);
int func_001427A0(void *self);
int func_1446A0(void *ptr);
int func_114378(const char *str);
void *func_00142730(void *self, const char *token);
}

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0xC];
    char *field_10;
    char pad_14[0x20];
    char field_34[0xC];
    int field_40;
    char pad_44[0x158];
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {

int func_00143020(TacticalAI2 *self, int a1) {
    if (!a1) {
        int token = func_142980(self);
        if (token != 2) {
            if (token == 1) {
                func_144340(self, 0x1A, 0);
            }
            return 0;
        }
        if (self->field_19C != 2) {
            func_144340(self, 0xF, 0);
            return 0;
        }
    }

    int token = func_142980(self);
    if (token != 2) {
        if (token == 1) {
            func_144340(self, 0x1A, 0);
        }
        return 0;
    }

    if (self->field_19C != 1) {
        func_144340(self, 0xC, 0);
        return 0;
    }

    short *s0 = (short *)func_26B0A0(&self->field_34, self->field_1A0, 1);
    if (s0) {
        *(short *)(self->field_40 * 20 + (char *)self + 0x4C) = 2;
        *(short *)(self->field_40 * 20 + (char *)self + 0x4E) = s0[1];

        if (!func_00142CC0(self)) {
            return 0;
        }

        if (!func_00143020(self, 0)) {
            return 0;
        }

        if (s0[1] != 0) {
            if (!func_00142CC0(self)) {
                return 0;
            }
            if (!func_00143020(self, 0)) {
                return 0;
            }
        }

        return func_001427A0(self);
    }

    short *s2 = (short *)func_26B0A0(&self->field_34, self->field_1A0, 3);
    if (!s2) {
        func_144340(self, 3, self->field_1A0);
        return 0;
    }

    short cond_id = s2[1];
    void *s0_obj = (void *)func_1446A0((char *)self->field_10 + cond_id * 24);

    *(short *)(self->field_40 * 20 + (char *)self + 0x4C) = 3;
    *(short *)(self->field_40 * 20 + (char *)self + 0x4E) = cond_id;

    int s1 = 0;
    while (s1 < (int)s0_obj) {
        int t = func_142980(self);
        if (t != 2) {
            if (t == 1) {
                func_144340(self, 0x1A, 0);
            }
            return 0;
        }

        if (self->field_19C != 1) {
            func_144340(self, 0xC, 0);
            return 0;
        }

        char first = self->field_1A0[0];
        int val;
        if ((D_48E100[first + 1] & 4) || (char)first == '+' || (char)first == '-') {
            val = func_114378(self->field_1A0);
        } else {
            void *sym = func_00142730(self, self->field_1A0);
            if (!sym) {
                func_144340(self, 3, self->field_1A0);
                return 0;
            }
            val = *(short *)((char *)sym + 2);
        }

        switch (s1) {
        case 0:
            *(int *)(self->field_40 * 20 + (char *)self + 0x50) = val;
            break;
        case 1:
            *(int *)(self->field_40 * 20 + (char *)self + 0x54) = val;
            break;
        case 2:
            *(int *)(self->field_40 * 20 + (char *)self + 0x58) = val;
            break;
        case 3:
            *(int *)(self->field_40 * 20 + (char *)self + 0x5C) = val;
            break;
        }

        s1++;
    }

    return func_001427A0(self);
}

}
