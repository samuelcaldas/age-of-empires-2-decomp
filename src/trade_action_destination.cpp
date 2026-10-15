#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_001AAB30();
void func_001AAB70(int token);
void func_00150F50(void *self, int a1);
void *func_00332E60(void *mgr, short id);
int func_00202B10(void *ptr);

struct SearchItem {
    int id;
    int field_4;
};

extern SearchItem *D_00F99910[];
extern int D_00F99930[];
}

class TargetObj {
public:
    char pad_00[0x8];
    void *m_game;          // 0x8
    char pad_0C[0x18];     // 0xC to 0x23
    short m_field24;       // 0x24
    char pad_26[0x1E];     // 0x26 to 0x43
    float m_posX;          // 0x44
    float m_posY;          // 0x48
};

class TradeActionBase {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void Method2C(int a1, float f12, float f13); // 0x2C (vfn 9)

    char pad_04[0x34];     // 0x4 to 0x37
    TargetObj *m_target;   // 0x38
    char pad_3C[0x104];    // 0x3C to 0x13F
    unsigned int m_field140; // 0x140
    unsigned int m_field144; // 0x144
    char pad_148[4];       // 0x148 to 0x14B
    int m_field14C;        // 0x14C
    int m_field150;        // 0x150
    char pad_154[0x18];    // 0x154 to 0x16B
    unsigned int m_field16C; // 0x16C
};

struct TargetEntitySub {
    char pad_00[0xE];
    short m_valE;          // 0xE
};

typedef void (*NotifyFn)(void *mgr, short s0, void *s1, int code, short obj_id, int a6, int a7);

extern "C" {

void func_0014BE10(TradeActionBase *self) {
    unsigned int val = self->m_field144;
    unsigned int rem = (unsigned int)func_001AAB30() % (val / 2);
    self->m_field140 = ((val * 3) / 4) + rem;
}

void func_0014BE70(TradeActionBase *self, unsigned int val) {
    if (val < 1000) {
        val = 1000;
    }
    unsigned int rem = (unsigned int)func_001AAB30() % (val / 2);
    self->m_field16C = ((val * 3) / 4) + rem;
}

void func_0014BEE0(void *self) {
    func_00150F50(self, 0);
}

int func_0014BEF0() {
    return -1;
}

void func_0014BF00(TradeActionBase *self) {
    self->Method2C(1, self->m_target->m_posX, self->m_target->m_posY);
    int token = func_001AAB30();

    short s0 = self->m_target->m_field24;
    void *game = self->m_target->m_game;
    void *s1 = *(void **)((char *)game + 0xBA0);
    void *s2 = *(void **)((char *)game + 0xB98);

    for (int i = 0; i < D_00F99930[0]; i++) {
        void *obj = func_00332E60(s2, D_00F99910[0][i].id);
        if (!obj) {
            continue;
        }

        TargetEntitySub *sub = *(TargetEntitySub **)((char *)obj + 4);
        if (sub->m_valE == 0xF) {
            continue;
        }

        short obj_id = *(short *)((char *)obj + 0x24);
        void *action_mgr = *(void **)((char *)self->m_target->m_game + 0x1B30);
        NotifyFn fn = *(NotifyFn *)(*(char **)action_mgr + 0x118);
        fn(action_mgr, s0, s1, 0x20D, obj_id, 0, 0);
    }

    int cond = func_00202B10(*(void **)((char *)self->m_target + 8));
    int limit = 3;
    if (cond) {
        limit = 2;
    }

    for (int s4 = 4; s4 >= limit; s4--) {
        SearchItem *table = D_00F99910[s4];
        int count = D_00F99930[s4];

        for (int j = 0; j < count; j++) {
            void *obj = func_00332E60(s2, table[j].id);
            if (!obj) {
                continue;
            }

            unsigned char st = *(unsigned char *)((char *)obj + 0x39);
            if (st < 3) {
                short obj_id = *(short *)((char *)obj + 0x24);
                void *action_mgr = *(void **)((char *)self->m_target->m_game + 0x1B30);
                NotifyFn fn = *(NotifyFn *)(*(char **)action_mgr + 0x118);
                fn(action_mgr, s0, s1, 0x20D, obj_id, 0, 0);
            }
        }
    }

    func_001AAB70(token);
    self->m_field14C = 0;
    self->m_field150 = 4000 + (func_001AAB30() % 1000);
}

}
