#include "sub_list.h"

#pragma exceptions off

extern "C" {
extern const char D_48E100[];

int func_142980(void *self);
void func_144340(void *self, int code, void *param);
void *func_26B0A0(void *table, char *name, int a2);
int func_0013C650(void *action);
int func_001410E0(void *self, char *str);
int func_114378(const char *str);
void *func_00142730(void *self, char *token, int a2);
int func_001427A0(void *self);
}

struct Obj12 {
    char data[12];
};

struct PredicateItem {
    short type;
    short op_or_node;
    int a1;
    int a2;
    int a3;
    int t0;
};

struct Candidate {
    char pad_0[2];
    short field_2;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x14];
    Obj12 *field_18;
    char pad_1C[0x18];
    void *field_34;
    char pad_38[0x8];
    int field_40;
    char pad_44[0x8];
    PredicateItem field_4C[1];
    char pad_60[0x138];
    int field_198;
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {

int func_00142D10(TacticalAI2 *self) {
    int status = func_142980(self);
    if (status == 2) goto L_step1;
    if (status == 1) {
        func_144340(self, 0x1A, 0);
    }
    return 0;

L_step1:
    if (self->field_19C != 1) {
        func_144340(self, 0xC, 0);
        return 0;
    }

    Candidate *cand = (Candidate *)func_26B0A0(&self->field_34, self->field_1A0, 0);
    if (!cand) {
        func_144340(self, 0x3, self->field_1A0);
        return 0;
    }

    int param_count = func_0013C650(&self->field_18[cand->field_2]);
    self->field_4C[self->field_40].type = 1;
    self->field_4C[self->field_40].op_or_node = cand->field_2;

    for (int i = 0; i < param_count; i++) {
        status = func_142980(self);
        if (status == 2) goto L_param_tok;
        if (status == 1) {
            func_144340(self, 0x1A, 0);
        }
        return 0;

    L_param_tok:
        if (self->field_19C == 1) goto L_tok_ok;
        if (self->field_19C == 4) goto L_tok_ok;
        func_144340(self, 0xC, 0);
        return 0;

    L_tok_ok:
        int val;
        if (self->field_19C == 4) {
            val = 0;
            if (self->field_198 != 0) {
                val = func_001410E0(self, self->field_1A0);
                if (val == -1) {
                    func_144340(self, 0x15, 0);
                    return 0;
                }
            }
        } else {
            char ch = self->field_1A0[0];
            if (D_48E100[ch + 1] & 4) goto L_atoi;
            if ((long)ch == '+') goto L_atoi;
            if ((long)ch != '-') goto L_symbol;
        L_atoi:
            val = func_114378(self->field_1A0);
            goto L_store;

        L_symbol:
            Candidate *sym = (Candidate *)func_00142730(self, self->field_1A0, 2);
            if (!sym) {
                func_144340(self, 0x3, self->field_1A0);
                return 0;
            }
            val = sym->field_2;
        }

    L_store:
        switch (i) {
        case 0:
            self->field_4C[self->field_40].a1 = val;
            break;
        case 1:
            self->field_4C[self->field_40].a2 = val;
            break;
        case 2:
            self->field_4C[self->field_40].a3 = val;
            break;
        case 3:
            self->field_4C[self->field_40].t0 = val;
            break;
        }
    }

    return func_001427A0(self);
}

}
