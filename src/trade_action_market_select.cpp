#pragma exceptions off
#include "sub_list.h"

#define V_SLOT_10(base) \
    virtual int v##base##0(); virtual int v##base##1(); virtual int v##base##2(); virtual int v##base##3(); virtual int v##base##4(); \
    virtual int v##base##5(); virtual int v##base##6(); virtual int v##base##7(); virtual int v##base##8(); virtual int v##base##9();

class TargetObj {
public:
    V_SLOT_10(0)
    V_SLOT_10(1)
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    V_SLOT_10(5)
    V_SLOT_10(6)
    virtual int v70(); virtual int v71(); virtual int v72(); virtual int v73();
    virtual int v74(); virtual int v75();
    virtual float Method138(); // offset 0x138 (slot 76)
    virtual int v77(); virtual int v78(); virtual int v79();
    V_SLOT_10(8)
    V_SLOT_10(9)
    virtual int v100(); virtual int v101(); virtual int v102(); virtual int v103();
    virtual int v104(); virtual int v105(); virtual int v106(); virtual int v107();
    virtual int Method1B8(int a1, int a2, float f12, int a3, int t0, int t1); // offset 0x1B8 (slot 108)
    virtual int v109();
    V_SLOT_10(11)
    V_SLOT_10(12)
    virtual int v130(); virtual int v131(); virtual int v132(); virtual int v133();
    virtual int v134(); virtual int v135();
    virtual int Method228(); // offset 0x228 (slot 136)

    void *m_node;          // 0x4
    void *m_game;          // 0x8
    char pad_0C[0x24 - 0xC];
    short m_field24;       // 0x24
    char pad_26[0x39 - 0x26];
    unsigned char m_field39; // 0x39
    unsigned char m_field3A; // 0x3A
    char pad_3B[0x44 - 0x3B];
    float x;               // 0x44
    float y;               // 0x48
    float z;               // 0x4C
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8();
    virtual int Method2C(float x, float y, int a1); // offset 0x2C (slot 9)

    char pad_04[0x38 - 0x4];
    TargetObj *m_target;   // 0x38
};

extern "C" {
extern int *D_F99910[];
extern int D_F99930[];
extern int D_004E3064;

void* func_332e60(void *timer, int a1);
int func_123350(float val);

int func_0014EA40(TradeAction *self, int a1, int a2, int a3, int t0, int t1, int *t2) {
    TargetObj *target = self->m_target;
    self->Method2C(target->x, target->y, 1);

    int best_id = -1;
    float best_score = -1.0f;

    int table[9];
    for (int i = 0; i < 9; i++) {
        table[i] = 0;
    }

    void *timer = *(void **)((char *)self->m_target->m_game + 0xB98);

    for (int s0 = 0; s0 < 5; s0++) {
        int count = D_F99930[s0];
        int *list = D_F99910[s0];

        for (int s1 = 0; s1 < count; s1++) {
            unsigned char group = *(unsigned char *)((char *)list + s1 * 8 + 5);
            table[group] = 1;

            int candidate_id = list[s1 * 2];
            if (candidate_id == self->m_target->m_field24) {
                continue;
            }

            TargetObj *cand = (TargetObj *)func_332e60(timer, candidate_id);
            if (!cand) {
                continue;
            }

            if (cand->m_field39 >= 7) {
                continue;
            }

            if (a2 == 0) {
                if (s0 != 2 && s0 != 1) {
                    continue;
                }
            } else if (a2 == 2) {
                if (s0 != 4) {
                    continue;
                }
            } else if (a2 == 3) {
                if (s0 != 1) {
                    continue;
                }
            } else if (a2 == 1) {
                if (s0 != 3) {
                    continue;
                }
            }

            if (a1 != -1 && *(short *)((char *)cand->m_node + 0xE) != a1) {
                continue;
            }

            if (t0 != -1 && *(short *)((char *)cand->m_node + 8) != t0) {
                continue;
            }

            if (a3 != -1 && cand->m_field39 != a3) {
                continue;
            }

            if (t1 != -1 && cand->m_field3A < t1) {
                continue;
            }

            if (a3 == 0) {
                if (*(short *)((char *)cand->m_node + 8) == 50 && cand->m_field3A > 0) {
                    continue;
                }
            }

            if (a1 == 58) {
                if (cand->m_game != self->m_target->m_game && cand->m_field39 == 2) {
                    continue;
                }
                if (cand->Method138() != -1.0f && cand->Method228() == 107) {
                    continue;
                }
            }

            if (self->m_target->Method1B8(cand->m_field24, 0, 0.0f, -1, -1, 0) == 0) {
                continue;
            }

            float score = (float)*(unsigned char *)((char *)list + s1 * 8 + 4);
            if (best_id == -1 || score < best_score) {
                best_id = candidate_id;
                best_score = score;
            }
        }
    }

    D_004E3064 = 0;
    for (int i = 1; i < 9; i++) {
        if (table[i] == 1) {
            D_004E3064++;
        }
    }

    if (t2) {
        *t2 = func_123350(best_score);
    }

    return best_id;
}

int func_0014EE70(void *self) {
    return -1;
}

}
