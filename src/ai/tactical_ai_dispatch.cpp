#include "sub_list.h"

#pragma exceptions off

struct Msg {
    char type;
    char pad;
    short val;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x34 - 4];
    char m_field34[8];
    void **m_field3C;
};

extern "C" {
Msg* func_26AF90(void *ptr, int a1, Msg *a2);
int func_00141170(void *self, int a1, int a2, int a3);

int func_00142130(TacticalAI2 *self, int a1, int a2, int a3) {
    Msg msg;
    msg.type = 2;
    msg.val = (short)a3;
    Msg *res = func_26AF90(self->m_field3C[a1], a2, &msg);
    if (res->val != msg.val) {
        return 0;
    }
    return 1;
}

int func_001421A0(TacticalAI2 *self, int a1, int a2) {
    Msg msg;
    msg.type = 5;
    msg.val = 1;
    Msg *res = func_26AF90(self->m_field34, a1, &msg);
    if (res->val != msg.val) {
        return 0;
    }
    return 1;
}

int func_00142200(TacticalAI2 *self, int a1, int a2) {
    Msg msg;
    msg.type = 2;
    msg.val = (short)a2;
    Msg *res = func_26AF90(self->m_field34, a1, &msg);
    if (res->val != msg.val) {
        return 0;
    }
    return 1;
}

int func_00142260(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    int res1 = func_00141170(self, a2, a3, t0);
    if (res1 == -1) {
        return 0;
    }
    Msg msg;
    msg.type = 3;
    msg.val = res1;
    Msg *res = func_26AF90(self->m_field34, a1, &msg);
    if (res->val != msg.val) {
        return 0;
    }
    return 1;
}

}
