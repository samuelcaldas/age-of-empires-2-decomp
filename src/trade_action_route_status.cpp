#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00332E60(void *mgr, short id);
void func_001471B0(void *self, short actionId);
void func_0014BD20(void *self, short id, float f12, float f13, float f14);
float func_002690D0(void *obj, void *target);
}

class MarketObj {
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
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
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
    virtual int Method16C(short a1, int a2);   // 0x16C (vfn 89)

    char pad_04[4];        // 0x4
    void *m_field8;        // 0x8
    char pad_0C[0x40];     // 0xC to 0x4B
    float m_posZ;          // 0x4C
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
    virtual void Method98(short a1, int a2); // 0x98 (vfn 36)

    char pad_04[0x34];     // 0x4 to 0x37
    MarketObj *m_market;   // 0x38
    char pad_3C[0xC];      // 0x3C to 0x47
    short m_actionId;      // 0x48
    short m_field4A;       // 0x4A
    char pad_4C[2];        // 0x4C to 0x4D
    short m_field4E;       // 0x4E
    char pad_50[0xC];      // 0x50 to 0x5B
    float m_field5C;       // 0x5C
};

struct StatusEntity {
    char pad_00[0x44];
    float m_posX;          // 0x44
    float m_posY;          // 0x48
    float m_posZ;          // 0x4C
};

struct MarketPlayerMgr {
    char pad_00[0xB98];
    void *m_b98;           // 0xB98
};

extern "C" {

int func_0014B8F0(TradeActionBase *self, short a1, int a2, float f12) {
    if (!a2 && self->m_actionId != -1) {
        return 0;
    }

    MarketPlayerMgr *mgr = (MarketPlayerMgr *)self->m_market->m_field8;
    StatusEntity *entity = (StatusEntity *)func_00332E60(mgr->m_b98, a1);
    if (!entity) {
        return 0;
    }

    func_001471B0(self, 0x264);
    func_0014BD20(self, a1, entity->m_posX, entity->m_posY, entity->m_posZ);
    self->m_field5C = f12;

    float dist = func_002690D0(self->m_market, entity);
    float bound = self->m_field5C;
    if (dist > bound) {
        self->Method98(self->m_field4A, 1);
    }
    return 1;
}

int func_0014B9E0(TradeActionBase *self, short a1, int a2, float f12) {
    if (!a2 && self->m_actionId != -1) {
        return 0;
    }

    MarketPlayerMgr *mgr = (MarketPlayerMgr *)self->m_market->m_field8;
    StatusEntity *entity = (StatusEntity *)func_00332E60(mgr->m_b98, a1);
    if (!entity) {
        return 0;
    }

    func_001471B0(self, 0x259);
    func_0014BD20(self, a1, entity->m_posX, entity->m_posY, entity->m_posZ);
    self->m_field4E = a1;
    self->m_field5C = f12;
    return 1;
}

int func_0014BAA0(TradeActionBase *self, int a1, float f12, float f13, float f14) {
    if (!a1 && self->m_actionId != -1) {
        return 0;
    }

    func_001471B0(self, 0x259);
    func_0014BD20(self, -1, f12, f13, self->m_market->m_posZ);
    self->m_field4E = -1;
    self->m_field5C = f14;
    return 1;
}

int func_0014BB40(TradeActionBase *self, short a1, int a2, int a3, int t0) {
    if (!t0 && self->m_actionId != -1) {
        return 0;
    }

    if (self->m_market->Method16C(a1, t0) == 1) {
        func_001471B0(self, 0x26E);
        func_0014BD20(self, a1, (float)a2, (float)a3, 1.0f);
        return 1;
    }

    return 0;
}

}
