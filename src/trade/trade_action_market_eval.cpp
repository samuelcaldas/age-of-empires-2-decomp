#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern float D_004E2808; // FLT_MAX
extern float D_004E2824; // 1.0e-7f (EPSILON)

short func_001471C0(void *obj);
}

class TargetObj {
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
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual float Method114();               // 0x114
    virtual float Method118();               // 0x118
    virtual float Method11C();               // 0x11C
    virtual float Method120(TargetObj *other); // 0x120
    virtual float Method124();               // 0x124
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void* Method164();               // 0x164

    char pad_04[0x20];                       // 0x4 to 0x23
    short m_field24;                         // 0x24
    char pad_26[0xA];                        // 0x26 to 0x2F
    float m_field30;                         // 0x30
};

struct TradeAction {
    float m_minDistance;     // 0x0
    float m_maxDistance;     // 0x4
    float m_minCost;         // 0x8
    float m_maxCost;         // 0xC
    float m_minMarketDist;   // 0x10
    float m_maxMarketDist;   // 0x14
    float m_minMarketCost;   // 0x18
    float m_maxMarketCost;   // 0x1C
    unsigned char m_field20; // 0x20
    unsigned char m_field21; // 0x21
    unsigned char m_field22; // 0x22
    unsigned char m_field23; // 0x23
    char pad_24[0xC];        // 0x24 to 0x2F
    unsigned char m_count;   // 0x30
    char pad_31[0x41];       // 0x31 to 0x71
    short m_field72;         // 0x72
    float m_field74;         // 0x74
    char pad_78[0x800];      // 0x78 onwards
};

typedef int (*Method154)(void *obj, short id, int flag);

extern "C" {

void func_00148FF0(TradeAction *self, TargetObj *s2, TargetObj *s1, short a3, float f12) {
    if (!s2 || !s2->Method164()) {
        return;
    }

    if (!s1 || !s1->Method164()) {
        return;
    }

    if (self->m_count >= 0x40) {
        return;
    }

    int idx = self->m_count;
    char *entry = (char *)self + idx * 32;

    *(short *)(entry + 0x78) = s1->m_field24;
    *(float *)(entry + 0x80) = f12;

    if (a3 != -1) {
        *(unsigned char *)((char *)self + a3 + 0x24) += 1;
    }

    short id_s0 = s1->m_field24;
    void *v0_s2 = s2->Method164();
    short target_id = func_001471C0(*(void **)v0_s2);
    if (id_s0 == target_id) {
        self->m_field20++;
    }

    float f114 = s1->Method114();
    if (f114 > 0.0f) {
        *(unsigned char *)(entry + 0x7B) = 1;
        if (f12 < self->m_field74) {
            self->m_field74 = f12;
            self->m_field72 = s1->m_field24;
        }
        self->m_field21++;
    } else {
        *(unsigned char *)(entry + 0x7B) = 0;
    }

    float f11C = s1->Method11C();
    if (f11C <= 0.0f) {
        void *s1_obj = s1->Method164();
        Method154 fn = *(Method154 *)(*(char **)((char *)s1_obj + 4) + 0x154);
        if (fn(s1_obj, s2->m_field24, 1) != 1) {
            self->m_field22++;
        }
    } else {
        self->m_field22++;
    }

    float f124 = s2->Method124();
    if (f12 <= f124) {
        self->m_field23++;
    }

    if (f12 < self->m_minDistance) {
        self->m_minDistance = f12;
    }
    if (f12 > self->m_maxDistance) {
        self->m_maxDistance = f12;
    }

    float f21 = s1->Method120(s2);
    if (f21 <= D_004E2824) {
        void *s2_obj = s2->Method164();
        Method154 fn = *(Method154 *)(*(char **)((char *)s2_obj + 4) + 0x154);
        if (fn(s2_obj, s1->m_field24, 0) == 1) {
            *(float *)(entry + 0x7C) = 5.0f;
        } else {
            *(float *)(entry + 0x7C) = D_004E2808;
        }
    } else {
        float f1 = s1->m_field30;
        float f118 = s2->Method118();
        *(float *)(entry + 0x7C) = (f1 / f21) / f118;
    }

    float cost = *(float *)(entry + 0x7C);
    if (cost < self->m_minCost) {
        self->m_minCost = cost;
    }
    if (cost > self->m_maxCost) {
        self->m_maxCost = cost;
    }

    void *s2_obj2 = s2->Method164();
    short s2_target = func_001471C0(*(void **)s2_obj2);
    if (s1->m_field24 == s2_target) {
        *(float *)(entry + 0x90) = 5.0f;
    } else {
        *(float *)(entry + 0x90) = 0.0f;
    }

    if (s1->Method114() > 0.0f) {
        if (f12 < self->m_minMarketDist) {
            self->m_minMarketDist = f12;
        }
        if (f12 > self->m_maxMarketDist) {
            self->m_maxMarketDist = f12;
        }
        if (cost < self->m_minMarketCost) {
            self->m_minMarketCost = cost;
        }
        if (cost > self->m_maxMarketCost) {
            self->m_maxMarketCost = cost;
        }
    }

    self->m_count++;
}

}
