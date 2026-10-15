#include "sub_list.h"

#pragma exceptions off

extern "C" {
extern const char D_490EA0[];
extern const char D_490EA8[];
extern const char D_490EB8[];
extern const char D_490EC0[];
extern const char D_48E101[];

int func_142980(void *self);
void func_144340(void *self, int code, void *param);
int func_0011AA78(const char *s1, const char *s2);
char *func_0011ABBC(char *dst, const char *src);
int func_001427A0(void *self);
void func_1441B0(void *self);
int func_00142560(void *self, const char *path);
void func_144050(void *self);
int func_143AD0(void *self);
int func_145740(void *sub);
int func_143E00(void *self);
int func_00141250(void *self, int a1, int a2, void *sub);
int func_114378(const char *str);
void *func_00142730(void *self, char *token, int a2);
int func_00142130(void *self, int a1, const char *name, int val);
}

struct Candidate {
    char pad_0[2];
    short field_2;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x3C];
    int field_40;
    char field_44[5];
    char field_49;
    char pad_4A[0x142];
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {

int func_143440(TacticalAI2 *self) {
    char buf1[0x110];
    char buf2[0x100];

    int status = func_142980(self);
    if (status == 2) goto L_step1;
    if (status != 1) goto L_ret0;
    func_144340(self, 0x1A, 0);
L_ret0:
    return 0;

L_step1:
    if (self->field_19C != 1) {
        func_144340(self, 0xD, 0);
        return 0;
    }

    if (func_0011AA78(self->field_1A0, D_490EA0) == 0) {
        status = func_142980(self);
        if (status == 2) goto L_load_param;
        if (status != 1) goto L_load_fail;
        func_144340(self, 0x1A, 0);
    L_load_fail:
        return 0;

    L_load_param:
        if (self->field_19C != 4) {
            func_144340(self, 0xB, 0);
            return 0;
        }

        func_0011ABBC(buf1, self->field_1A0);
        if (!func_001427A0(self)) return 0;
        func_1441B0(self);
        int res = func_00142560(self, buf1);
        func_144050(self);
        return res;
    }

    if (func_0011AA78(self->field_1A0, D_490EA8) == 0) {
        return func_143AD0(self);
    }

    if (func_0011AA78(self->field_1A0, D_490EB8) == 0) {
        int link_res = -1;
        self->field_40 = 0;
        self->field_18C = func_145740(self->field_44);
        int rule_res = func_143E00(self);
        if (!rule_res) return 0;
        self->field_194 = rule_res;
        if (!self->field_198) return 1;
        self->field_49 = (char)rule_res;
        link_res = func_00141250(self, self->field_190, self->field_18C, self->field_44);
        if (link_res == -1) {
            func_144340(self, 6, 0);
            return 0;
        }
        return 1;
    }

    if (func_0011AA78(self->field_1A0, D_490EC0) == 0) {
        status = func_142980(self);
        if (status == 2) goto L_const_name;
        if (status != 1) goto L_name_fail;
        func_144340(self, 0x1A, 0);
    L_name_fail:
        return 0;

    L_const_name:
        if (self->field_19C != 1) {
            func_144340(self, 0xC, 0);
            return 0;
        }

        func_0011ABBC(buf2, self->field_1A0);
        status = func_142980(self);
        if (status == 2) goto L_const_val;
        if (status != 1) goto L_val_fail;
        func_144340(self, 0x1A, 0);
    L_val_fail:
        return 0;

    L_const_val:
        if (self->field_19C != 1) {
            func_144340(self, 0xC, 0);
            return 0;
        }

        int const_val;
        char ch = self->field_1A0[0];
        if (D_48E101[ch] & 4) goto L_atoi_val;
        if ((long)ch == '+') goto L_atoi_val;
        if ((long)ch != '-') goto L_sym_val;

    L_atoi_val:
        const_val = func_114378(self->field_1A0);
        goto L_finish_const;

    L_sym_val: {
        Candidate *sym = (Candidate *)func_00142730(self, self->field_1A0, 2);
        if (!sym) {
            func_144340(self, 3, self->field_1A0);
            return 0;
        }
        const_val = sym->field_2;
    }

    L_finish_const:
        if (!func_001427A0(self)) return 0;
        if (!self->field_198) return 1;
        if (!func_00142130(self, self->field_190, buf2, const_val)) {
            func_144340(self, 0, buf2);
            return 0;
        }
        return 1;
    }

    func_144340(self, 4, self->field_1A0);
    return 0;
}

}
