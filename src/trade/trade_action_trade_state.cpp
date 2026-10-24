#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern float D_004E2930;

void *func_00332E60(void *mgr, short id);
float func_002690D0(void *obj, void *target);
void *func_00100730(int sz);
void func_00100630(void *p);
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
    virtual float Method114(); // 0x114 (vfn 69)

    char pad_04[4];
    void *m_game;              // 0x8
    char pad_0C[0x18];
    short m_field24;           // 0x24
    char pad_26[0x1E];
    float m_posX;              // 0x44
    float m_posY;              // 0x48
};

struct StatusEntity {
    char pad_00[0x44];
    float m_posX;              // 0x44
    float m_posY;              // 0x48
    float m_posZ;              // 0x4C
};

struct MarketPlayerMgr {
    char pad_00[0xB98];
    void *m_b98;               // 0xB98
};

class TradeActionBase {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual int Method1C(short a1, short a2, short a3, float f12, float f13, float f14, float f15, int t0, int t1, short t2); // 0x1C (vfn 5)

    char pad_04[0x34];
    TargetObj *m_target;       // 0x38
    char pad_3C[0xA];
    short m_field46;           // 0x46
    char pad_48[2];
    short m_field4A;           // 0x4A
    char pad_4C[4];
    float m_field50;           // 0x50
    float m_field54;           // 0x54
    float m_field58;           // 0x58
    float m_field5C;           // 0x5C
    char pad_60[0x44];
    short *m_fieldA4;          // 0xA4
    int m_fieldA8;             // 0xA8
    char pad_AC[4];
    int m_fieldB0;             // 0xB0
};

extern "C" {

int func_001515E0(TradeActionBase *self, short a1, int a2, float f12) {
    if (self->m_target->Method114() == 0.0f) {
        return 0;
    }

    if (a1 == self->m_target->m_field24) {
        return 0;
    }

    MarketPlayerMgr *mgr = (MarketPlayerMgr *)self->m_target->m_game;
    StatusEntity *entity = (StatusEntity *)func_00332E60(mgr->m_b98, a1);
    if (!entity) {
        return 0;
    }

    if (!a2) {
        float dist = func_002690D0(self->m_target, entity);
        if (dist >= D_004E2930 * f12) {
            return 0;
        }
    }

    float dist2 = func_002690D0(self->m_target, entity);
    float remaining = f12 - dist2;
    if (remaining < 1.5f) {
        remaining = 1.5f;
    }

    float dx = entity->m_posX - self->m_target->m_posX;
    float dy = entity->m_posY - self->m_target->m_posY;

    int res = self->Method1C(self->m_target->m_field24, 0x2BC, self->m_field4A, self->m_field50, self->m_field54, self->m_field58, self->m_field5C, 0, 1, self->m_field46);

    int count = self->m_fieldA8;
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            if (self->m_fieldA4[i] == self->m_field4A) {
                break;
            }
        }
    }

    return res;
}

}
