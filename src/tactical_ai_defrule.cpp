#include "sub_list.h"

extern "C" {
int func_142980(void *ptr);
void func_144340(void *ptr, int a1, int a2);
int func_00142680(void *self, void *buf);
int func_00142CC0(void *self);
int func_00143020(void *self, int a1);
int func_0011AA78(const char *s1, const char *s2);
int func_00142D10(void *self);
extern char D_48E100[];
extern const char D_490F18[];
}

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x3C];
    unsigned char field_40;
    char pad_41[0x9];
    char field_4A;
    char field_4B;
    char pad_4C[0x140];
    int field_18C;
    char pad_190[0x4];
    int field_194;
    int field_198;
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {

int func_143E00(TacticalAI2 *self) {
    int has_item = 0;
    while (1) {
        int status = func_142980(self);
        if (status != 2) {
            if (status == 1) {
                func_144340(self, 0x1A, 0);
            }
            return 0;
        }
        if (self->field_19C == 2) goto parse_cond;
        if (has_item) goto check_arrow;
        if (!(D_48E100[self->field_1A0[0] + 1] & 3)) goto check_arrow;
        if (self->field_198) {
            self->field_18C = (short)func_00142680(self, self->field_1A0);
        }

    parse_cond:
        if (has_item) {
            if (!func_00142CC0(self)) {
                return 0;
            }
        }
        if (!func_00143020(self, 1)) {
            has_item = 1;
            return 0;
        }
        has_item = 1;
        continue;

    check_arrow:
        if (!has_item) {
            func_144340(self, 0xE, 0);
            return 0;
        }
        if (self->field_19C == 1 && func_0011AA78(self->field_1A0, D_490F18) == 0) {
            break;
        }
        func_144340(self, 7, 0);
        return 0;
    }

    self->field_4A = (self->field_40 & 0xFF) + 1;
    has_item = 0;
    while (1) {
        int status = func_142980(self);
        if (status != 2) {
            if (status == 1) {
                func_144340(self, 0x1A, 0);
            }
            return 0;
        }
        if (self->field_19C == 2) {
            if (!func_00142CC0(self)) {
                return 0;
            }
            if (!func_00142D10(self)) {
                has_item = 1;
                return 0;
            }
            has_item = 1;
            continue;
        }
        self->field_4B = (self->field_40 & 0xFF) + 1;
        if (!has_item) {
            func_144340(self, 0x11, 0);
            return 0;
        }
        if (self->field_19C == 3) goto ret1;
        func_144340(self, 8, 0);
        return 0;
    }
ret1:
    return 1;
}

}
