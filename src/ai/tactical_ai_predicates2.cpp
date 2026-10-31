#include "sub_list.h"

extern "C" {
int strcmp(const char *s1, const char *s2);
void func_144340(void *ptr, int a1, void *a2);
int func_00142C80(void *ptr);
int func_00142C90(void *ptr);
int func_00142CA0(void *ptr);
int func_00142830(void *ptr);
void func_1442E0(void *ptr);
void func_144180(void *ptr);
void *func_00142730(void *ptr, const char *name, int a2);
extern const char D_490ED0[];
extern const char D_490EF0[];
extern const char D_490F08[];
extern const char D_490F10[];
}

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x194];
    int field_198;
    char pad_19C[0x4];
    char field_1A0[0x100];
};

extern "C" {

int func_143860(TacticalAI2 *self) {
    int type;
    if (strcmp(self->field_1A0, D_490ED0) == 0) {
        type = 1;
    } else if (strcmp(self->field_1A0, D_490EF0) == 0) {
        type = 2;
    } else if (strcmp(self->field_1A0, D_490F08) == 0) {
        type = 3;
    } else if (strcmp(self->field_1A0, D_490F10) == 0) {
        type = 4;
    } else {
        func_144340(self, 5, self->field_1A0);
        return 0;
    }

    switch (type) {
    case 1:
    case 2:
        if (func_00142C90(self)) {
            func_144340(self, 0x13, 0);
            return 0;
        }
        if (!func_00142830(self)) {
            return 0;
        }
        func_1442E0(self);
        {
            int defined = 0;
            if (func_00142730(self, self->field_1A0, 5)) {
                defined = 1;
            }
            if (type == 1) {
                self->field_198 = (self->field_198 != 0 && defined);
            } else {
                self->field_198 = (self->field_198 != 0 && !defined);
            }
        }
        break;

    case 3:
        if (func_00142C80(self)) {
            func_144340(self, 0x17, 0);
            return 0;
        }
        {
            bool val = false;
            if (func_00142CA0(self)) {
                if ((self->field_198 != 0) ^ 1) {
                    val = true;
                }
            }
            self->field_198 = val;
        }
        break;

    case 4:
        if (func_00142C80(self)) {
            func_144340(self, 0x18, 0);
            return 0;
        }
        func_144180(self);
        break;

    default:
        break;
    }
    return 1;
}

}
