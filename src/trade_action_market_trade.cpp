#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00332E60(void *mgr, int id);
void func_001471B0(void *self, short actionId);
void func_0014BD20(void *self, int id, float f12, float f13, float f14);
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
    virtual float Method124();                 // 0x124 (vfn 71)
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
    virtual int Method16C(int a1, int a2);   // 0x16C (vfn 89)
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual void vfn107();
    virtual int Method1B8(int a1, int a2, int a3, float f12, int t0, int t1); // 0x1B8 (vfn 108)

    char pad_04[4];        // 0x4
    void *m_game;          // 0x8
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
    virtual int Method54(void *entity);        // 0x54 (vfn 19)

    char pad_04[0x34];     // 0x4 to 0x37
    MarketObj *m_target;   // 0x38
    char pad_3C[0xC];      // 0x3C to 0x47
    short m_actionId;      // 0x48
    short m_field4A;       // 0x4A
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

int func_0014CFF0(TradeActionBase *self, int target_id) {
    if (self->m_field4A == target_id) {
        return 0;
    }

    MarketPlayerMgr *mgr = (MarketPlayerMgr *)self->m_target->m_game;
    StatusEntity *entity = (StatusEntity *)func_00332E60(mgr->m_b98, target_id);
    if (!entity) {
        return 0;
    }

    if (!self->Method54(entity)) {
        return 0;
    }

    if (self->m_actionId != -1) {
        float f0 = self->m_target->Method124();
        if (!self->m_target->Method1B8(target_id, 0, -1, f0, -1, 0)) {
            return 0;
        }
    }

    if (self->m_target->Method16C(target_id, 1) == 1) {
        func_001471B0(self, 0x258);
        if (!entity) {
            float y = 0.0f;
            func_0014BD20(self, target_id, y, y, y);
        } else {
            func_0014BD20(self, target_id, entity->m_posX, entity->m_posY, entity->m_posZ);
        }
        return 1;
    }

    return 0;
}

int func_0014D160(TradeActionBase *self, short target_id, int a2) {
    if (!a2 && self->m_actionId != -1) {
        return 0;
    }

    MarketPlayerMgr *mgr = (MarketPlayerMgr *)self->m_target->m_game;
    StatusEntity *entity = (StatusEntity *)func_00332E60(mgr->m_b98, target_id);
    if (!entity) {
        return 0;
    }

    if (!self->Method54(entity)) {
        return 0;
    }

    if (self->m_target->Method16C(target_id, a2) == 1) {
        func_001471B0(self, 0x258);
        if (!entity) {
            float y = 0.0f;
            func_0014BD20(self, target_id, y, y, y);
        } else {
            func_0014BD20(self, target_id, entity->m_posX, entity->m_posY, entity->m_posZ);
        }
        return 1;
    }

    return 0;
}

}
