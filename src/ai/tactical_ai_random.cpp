#include "sub_list.h"

#pragma exceptions off

extern "C" {
extern const char D_48E100[];

int func_1AAB30(void);
int func_142980(void *self);
void func_144340(void *self, int code, void *param);
int func_114378(const char *str);
char *func_0011ABBC(char *dst, const char *src);
int func_001427A0(void *self);
void func_1441B0(void *self);
int func_00142560(void *self, const char *path);
void func_144050(void *self);
}

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x198];
    int field_19C;
    char field_1A0[0x100];
};

extern "C" {

int func_143AD0(TacticalAI2 *self) {
    char buf1[0x110];
    char buf2[0x110];
    char buf3[0x110];

    int state = 0;
    int target_weight = (func_1AAB30() % 100) + 1;
    int accum_weight = 0;
    int current_weight = 0;
    int loaded = 0;

    while (1) {
        int status = func_142980(self);
        if (status == 2) goto L_tok_ok;
        if (status != 1) goto L_ret0;
        func_144340(self, 0x1A, 0);
    L_ret0:
        return 0;

    L_tok_ok:
        int type;
        if (self->field_19C == 1) {
            char ch = self->field_1A0[0];
            if ((D_48E100[ch + 1] & 4) || (long)ch == '+') {
                type = 1;
            } else {
                goto L_err;
            }
        } else if (self->field_19C == 4) {
            type = 2;
        } else if (self->field_19C == 3) {
            type = 3;
        } else {
        L_err:
            func_144340(self, 0xC, 0);
            return 0;
        }

        if (state == 2) goto L_state2;
        if (state == 1) goto L_state1;
        if (state == 0) goto L_state0;
        continue;

    L_state0:
        if (type == 2) {
            func_0011ABBC(buf1, self->field_1A0);
            if (!func_001427A0(self)) return 0;
            func_1441B0(self);
            int ret = func_00142560(self, buf1);
            func_144050(self);
            return ret;
        }
        if (type == 1) {
            current_weight = func_114378(self->field_1A0);
            state = 1;
            continue;
        }
        func_144340(self, 0xC, 0);
        return 0;

    L_state1:
        if (type != 2) {
            func_144340(self, 0xC, 0);
            return 0;
        }
        {
            int old_accum = accum_weight;
            accum_weight += current_weight;
            state = 2;
            if (loaded != 0) continue;
            if (!(old_accum < target_weight)) continue;
            if (accum_weight < target_weight) continue;

            func_0011ABBC(buf2, self->field_1A0);
            func_1441B0(self);
            loaded = func_00142560(self, buf2);
            func_144050(self);
            if (!loaded) return 0;
            loaded = 1;
            continue;
        }

    L_state2:
        if (type == 3) {
            return 1;
        }
        if (type == 2) goto L_fallback;
        if (type == 1) goto L_next_weight;
        continue;

    L_next_weight:
        current_weight = func_114378(self->field_1A0);
        state = 1;
        continue;

    L_fallback:
        func_0011ABBC(buf3, self->field_1A0);
        if (!func_001427A0(self)) return 0;
        if (loaded != 0) return 1;
        func_1441B0(self);
        int ret = func_00142560(self, buf3);
        func_144050(self);
        return ret;
    }
}

}
