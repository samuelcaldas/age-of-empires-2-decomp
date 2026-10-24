#include "sub_list.h"

#pragma exceptions off

struct Msg {
    char type;
    char pad;
    short val;
};

struct TacticalAI2Methods {
    void *m_vtable;
    char pad_04[0x18];
    short m_field1C;
    char pad_1E[0x34 - 0x1E];
    char m_field34[8];
    void **m_field3C;
    int m_field40;
    char m_field44[0x25C];
    int m_field2A0;
    int m_field2A4;
    char pad_2A8[0x400];
    int m_field6A8;
    int m_field6AC;
    char pad_6B0[4];
    int m_field6B4;
    char pad_6B8[0x29C8];
    int m_field3080;
};

extern "C" {
    extern char D_4D7768[];

    void func_26AE00(void *ptr, int val);
    void func_00100630(void *ptr);
    void func_1456F0(void *ptr, int val);
    void func_00140D40(void *self, int val);
    void func_00100670(void *self);
    Msg *func_26AF90(void *ptr, int a1, Msg *a2);
    void Save__10TacticalAIFPv(void *self, void *stream);

    void* func_00141F60(void *self, int flag);
    void func_00142050(void *self, void *stream);
    int func_00142060(void *self, int a1, int a2);
    int func_001420C0(void *self, int a1, int a2);
}

void* func_00141F60(void *self, int flag) {
    TacticalAI2Methods *ai = (TacticalAI2Methods*)self;
    if (!ai) {
        return 0;
    }
    ai->m_vtable = D_4D7768;
    for (int i = 0; i < ai->m_field1C; i++) {
        if (ai->m_field3C[i]) {
            func_26AE00(ai->m_field3C[i], 1);
        }
    }
    if (ai->m_field3C) {
        func_00100630(ai->m_field3C);
    }
    ai->m_field2A0 = 0;
    ai->m_field2A4 = 0;
    ai->m_field6A8 = 0;
    ai->m_field6AC = 0;
    ai->m_field6B4 = 0;
    func_1456F0(ai->m_field44, -1);
    ai->m_field3080 = 0;
    func_26AE00(ai->m_field34, -1);
    func_00140D40(ai, 0);
    if ((short)flag > 0) {
        func_00100670(ai);
    }
    return ai;
}

void func_00142050(void *self, void *stream) {
    Save__10TacticalAIFPv(self, stream);
}

int func_00142060(void *self, int a1, int a2) {
    TacticalAI2Methods *ai = (TacticalAI2Methods*)self;
    Msg msg;
    msg.type = 1;
    msg.val = (short)a2;
    Msg *res = func_26AF90(ai->m_field34, a1, &msg);
    if (res->val == msg.val) {
        return 1;
    }
    return 0;
}

int func_001420C0(void *self, int a1, int a2) {
    TacticalAI2Methods *ai = (TacticalAI2Methods*)self;
    Msg msg;
    msg.type = 5;
    msg.val = 1;
    Msg *res = func_26AF90(ai->m_field3C[a1], a2, &msg);
    if (res->val == msg.val) {
        return 1;
    }
    return 0;
}
