#pragma exceptions off
#include "sub_list.h"

class TargetObj;

#define V_SLOT_10(base) \
    virtual int v##base##0(); virtual int v##base##1(); virtual int v##base##2(); virtual int v##base##3(); virtual int v##base##4(); \
    virtual int v##base##5(); virtual int v##base##6(); virtual int v##base##7(); virtual int v##base##8(); virtual int v##base##9();

class Base0 {
public:
    virtual void b0();
};

class Base1 {
public:
    virtual void b1_0();
    virtual int Method0C(TargetObj *other); // offset 0xC (slot 1)
    virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5();
    virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9();
    V_SLOT_10(1)
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    V_SLOT_10(5)
    V_SLOT_10(6)
    V_SLOT_10(7)
    virtual int v80(); virtual int v81();
    virtual void Method150(int a1, int a2); // offset 0x150 (slot 82)
};

class SubObj : public Base0, public Base1 {
};

class GameBase {
public:
    char pad[0x1B30];
};

class PlayerDiplomacy : public GameBase {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual int IsAllied(); // offset 0x24 (slot 7)
};

class TargetObj {
public:
    V_SLOT_10(0)
    V_SLOT_10(1)
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    V_SLOT_10(5)
    V_SLOT_10(6)
    virtual int v70();
    virtual float Method124(); // offset 0x124 (slot 71)
    virtual int v72(); virtual int v73(); virtual int v74(); virtual int v75();
    virtual int v76(); virtual int v77(); virtual int v78(); virtual int v79();
    virtual int v80(); virtual int v81(); virtual int v82(); virtual int v83();
    virtual int v84(); virtual int v85(); virtual int v86();
    virtual SubObj* Method164(); // offset 0x164 (slot 87)
    virtual int v88(); virtual int v89();
    V_SLOT_10(9)
    virtual int v100(); virtual int v101(); virtual int v102(); virtual int v103();
    virtual int v104(); virtual int v105(); virtual int v106(); virtual int v107();
    virtual int Method1B8(int a1, int a2, float f12, int a3, int t0, int t1); // offset 0x1B8 (slot 108)
    virtual int v109();
    virtual int v110(); virtual int v111(); virtual int v112(); virtual int v113();
    virtual int v114(); virtual int v115();
    virtual int Method1D8(); // offset 0x1D8 (slot 116)

    void *m_node;                  // 0x4
    PlayerDiplomacy *m_game;       // 0x8
    char pad_0C[0x24 - 0xC];       // 0xC..0x23
    short m_field24;               // 0x24
    char pad_26[0x39 - 0x26];      // 0x26..0x38
    unsigned char m_field39;       // 0x39
    char pad_3A[0x44 - 0x3A];      // 0x3A..0x43
    float x;                       // 0x44
    float y;                       // 0x48
    float z;                       // 0x4C
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8();
    virtual int Method2C(float x, float y, int a1); // offset 0x2C (slot 9)

    char pad_04[0x38 - 0x4];
    TargetObj *m_target; // 0x38
};

extern "C" {
extern int *D_F99910[];
extern int D_F99930[];

TargetObj* func_001510D0(void *self, int a1);
float func_002690D0(TargetObj *a, TargetObj *b);
short func_00147160(void *arg);
short func_00147170(void *arg);
short func_001471A0(void *arg);
short func_001471C0(void *arg);

void func_0014C470(TradeAction *self, int a1) {
    TargetObj *targetEntity = func_001510D0(self, a1);
    if (!targetEntity) {
        return;
    }

    TargetObj *target = self->m_target;
    self->Method2C(target->x, target->y, 1);

    for (int s1 = 1; s1 < 3; s1++) {
        for (int s2 = 0; s2 < D_F99930[s1]; s2++) {
            TargetObj *t = self->m_target;
            int *list = D_F99910[s1];
            short myId = t->m_field24;
            int candidateId = list[s2 * 2];
            if (myId == candidateId) {
                continue;
            }

            TargetObj *cand = func_001510D0(self, candidateId);
            if (!cand) {
                continue;
            }

            if (!cand->Method164()) {
                continue;
            }

            if (!cand->m_game) {
                continue;
            }

            if (cand->m_field39 >= 3) {
                continue;
            }

            short type = *(short *)((char *)cand->m_node + 0xE);
            if (type == 1 || (unsigned short)(type - 2) < 2 || type == 27 || type == 39 || (unsigned short)(type - 18) < 4) {
                continue;
            }

            SubObj *sub = cand->Method164();
            if (sub && !sub->Method0C(targetEntity)) {
                continue;
            }

            if (*(int *)((char *)targetEntity->m_game + 0xBA0) && type == 4) {
                continue;
            }

            PlayerDiplomacy *candPlayer = cand->m_game;
            PlayerDiplomacy *targetPlayer = self->m_target->m_game;

            int candPlayerId = *(int *)((char *)candPlayer + 0xBA0);
            int targetPlayerId = *(int *)((char *)targetPlayer + 0xBA0);

            if (candPlayerId != targetPlayerId && !candPlayer->IsAllied()) {
                continue;
            }

            if (func_002690D0(self->m_target, cand) <= 3.0f) {
                continue;
            }

            if (func_001471A0(*(void **)cand->Method164()) != -1) {
                continue;
            }

            if ((cand->Method1D8() & 0xFF) == 1) {
                continue;
            }

            if (func_00147170(*(void **)cand->Method164()) != -1) {
                continue;
            }

            if (func_00147160(*(void **)cand->Method164()) > 0) {
                continue;
            }

            if (func_001471C0(*(void **)cand->Method164()) != -1) {
                continue;
            }

            float dist = cand->Method124();
            if (cand->Method1B8(a1, 0, dist, -1, -1, 0)) {
                cand->Method164()->Method150(a1, 1);
            }
        }
    }
}

}
