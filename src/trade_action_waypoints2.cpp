#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00332E60(void *mgr, short id);
void func_001471B0(void *self, short actionId);
void func_0014BD90(void *self, short id, short a2, float f12, float f13, float f14);
void func_0014BD20(void *self, short id, float f12, float f13, float f14);
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
    virtual void vfn32(); // 0x88
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
    virtual void vfn64(); // 0x108
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
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual int Method194(short id);           // 0x194 (vfn 99)
    virtual int Method198(short id);           // 0x198 (vfn 100)
    virtual int Method19C(int a1, int a2);     // 0x19C (vfn 101)

    char pad_04[4];        // 0x4
    void *m_field8;        // 0x8
};

struct TradeAction {
    char pad_00[0x38];
    MarketObj *m_market;   // 0x38
    char pad_3C[0xC];      // 0x3C to 0x47
    short m_actionId;      // 0x48
};

struct TargetEntitySub {
    char pad_00[0xE];
    short m_valE;          // 0xE
};

struct WaypointTarget {
    char pad_00[4];
    TargetEntitySub *m_sub; // 0x4
    char pad_08[0x3C];      // 0x8 to 0x43
    float m_posX;           // 0x44
    float m_posY;           // 0x48
    float m_posZ;           // 0x4C
};

struct MarketPlayerMgr {
    char pad_00[0xB98];
    void *m_b98;           // 0xB98
};

extern "C" {

int func_0014A3A0(TradeAction *self, short target_id, int flag) {
    if (!flag && self->m_actionId == 0x25A) {
        return 0;
    }

    if (self->m_market->Method194(target_id) == 1) {
        MarketPlayerMgr *mgr = (MarketPlayerMgr *)self->m_market->m_field8;
        WaypointTarget *entity = (WaypointTarget *)func_00332E60(mgr->m_b98, target_id);
        func_001471B0(self, 0x25A);

        if (!entity) {
            float zero = 0.0f;
            func_0014BD90(self, target_id, -1, zero, zero, zero);
        } else {
            func_0014BD90(self, target_id, entity->m_sub->m_valE, entity->m_posX, entity->m_posY, entity->m_posZ);
        }
        return 1;
    }

    return 0;
}

int func_0014A490(TradeAction *self, short target_id, int flag) {
    if (!flag && self->m_actionId == 0x267) {
        return 0;
    }

    if (self->m_market->Method198(target_id) == 1) {
        MarketPlayerMgr *mgr = (MarketPlayerMgr *)self->m_market->m_field8;
        WaypointTarget *entity = (WaypointTarget *)func_00332E60(mgr->m_b98, target_id);
        func_001471B0(self, 0x267);

        if (!entity) {
            float zero = 0.0f;
            func_0014BD90(self, target_id, -1, zero, zero, zero);
        } else {
            func_0014BD90(self, target_id, entity->m_sub->m_valE, entity->m_posX, entity->m_posY, entity->m_posZ);
        }
        return 1;
    }

    return 0;
}

int func_0014A580(TradeAction *self, int a1, int a2, int a3) {
    if (!a3 && self->m_actionId != -1) {
        return 0;
    }

    if (self->m_market->Method19C(a1, a2) == 1) {
        func_001471B0(self, 0x25D);
        func_0014BD20(self, -1, (float)a1, (float)a2, 1.0f);
        return 1;
    }

    return 0;
}

}
