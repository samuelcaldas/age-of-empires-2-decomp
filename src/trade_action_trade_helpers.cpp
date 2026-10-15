#pragma exceptions off
#include "sub_list.h"

struct ActionEntry {
    short m_pad0;     // 0x0
    short m_type;     // 0x2
    short m_field4;   // 0x4
    short m_field6;   // 0x6
    float m_f8;       // 0x8
    float m_fC;       // 0xC
    float m_f10;      // 0x10
    float m_f14;      // 0x14
};

class TargetObj {
public:
    virtual void vfn0();
    char pad_04[0x24 - 0x4];
    short m_field24; // 0x24 (offset 36)
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18();

    char pad_04[49 - 4];
    unsigned char m_entry_count; // offset 49 = 0x31
    char pad_32[56 - 50];
    TargetObj *m_target;         // offset 56 = 0x38
    ActionEntry *m_entries;      // offset 60 = 0x3C
};

extern "C" {
int func_00263700(void *a0, void *a1, void *a2, void *a3);
int func_00263760(void *a0, void *a1, void *a2, void *a3);
void func_002637C0(void *a0);
void func_00263A30(void *a0);
void func_0026A540(void *a0);
void func_00263CC0(void *a0, void *a1);
void func_00226D90(void *a0, void *a1, int sz);

int func_00151BA0(void *a0, void *a1, void *a2);
int func_00151C20(void *a0, void *a1);

int func_00151960(TradeAction *self) {
    int count = (int)self->m_entry_count;
    for (int a2 = 0; a2 < count; a2++) {
        ActionEntry *e = (ActionEntry *)((char *)self->m_entries + a2 * 24);
        if (e->m_field6 < 0) {
            continue;
        }
        if (e->m_pad0 == self->m_target->m_field24) {
            return a2;
        }
    }
    return -1;
}

int func_001519D0(void *self, int a1) {
    if (a1 == 15 || (unsigned int)(a1 - 7) < 4 || a1 == 32) {
        return 1;
    }
    return 0;
}

int func_00151A10(TradeAction *self, int a1) {
    int count = (int)*(unsigned char *)((char *)self + 44);
    for (int v1 = 0; v1 < count; v1++) {
        if (*(unsigned char *)((char *)self + 4 + v1) == a1) {
            return 1;
        }
    }
    return 0;
}

int func_00151A50() {
    return 0;
}

int func_00151A60() {
    return -1;
}

void func_00151A70(void *s1, void *s2, void *s0, void *a3, float f12, float f13, float f14) {
    if (func_00263700(a3, s1, s2, s0)) {
        func_00151BA0(a3, s1, s2);
    }
}

void func_00151B10(void *s1, void *s2, void *s0, void *a3) {
    if (func_00263760(a3, s1, s2, s0)) {
        func_00151C20(s2, a3);
    }
}

void func_00151B80(void *self, void *a1) {
    if (a1) {
        func_002637C0(a1);
    }
}

int func_00151BA0(void *a0, void *a1, void *a2) {
    func_00263A30(a0);
    func_0026A540(a0);
    *(int *)((char *)a0 + 104) = 0;
    if (*(void **)((char *)a0 + 12) == 0) {
        typedef void* (*Vfn2D0)(void *self);
        void *vptr = *(void **)a0;
        Vfn2D0 fn = *(Vfn2D0 *)((char *)vptr + 720);
        *(void **)((char *)a0 + 12) = fn(a0);
        *(int *)((char *)a0 + 16) = 0;
        void *node = *(void **)((char *)a0 + 4);
        void *sub = *(void **)((char *)node + 16);
        typedef void (*Vfn4C)(void *self, void *arg);
        Vfn4C fn2 = *(Vfn4C *)((char *)vptr + 76);
        fn2(a0, sub);
    }
    return 1;
}

int func_00151C20(void *a0, void *a1) {
    func_00263CC0(a1, a0);
    func_00226D90(a1, (char *)a0 + 104, 4);
    return 1;
}

}
