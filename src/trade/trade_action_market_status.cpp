#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_00148050(void *self, void *pos, int a2, int a3, int t0, int t1, int t2, int t3);
}

class ActionMgr {
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
    virtual void Method118(short a1, short a2, short a3); // 0x118 (vfn 68)
};

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
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual void vfn107();
    virtual void vfn108();
    virtual void vfn109();
    virtual void vfn110();
    virtual void vfn111();
    virtual void vfn112();
    virtual void vfn113();
    virtual void vfn114();
    virtual void vfn115();
    virtual void vfn116();
    virtual void vfn117();
    virtual void vfn118();
    virtual void vfn119();
    virtual void vfn120();
    virtual void vfn121();
    virtual void vfn122();
    virtual void vfn123();
    virtual void vfn124();
    virtual void vfn125();
    virtual void vfn126();
    virtual void vfn127();
    virtual void vfn128();
    virtual void vfn129();
    virtual void vfn130();
    virtual void vfn131();
    virtual void vfn132();
    virtual void vfn133();
    virtual void vfn134();
    virtual void Method220(void *pos); // 0x220 (vfn 135)

    char pad_04[4];        // 0x4
    void *m_game;          // 0x8
    char pad_0C[0x38];     // 0xC to 0x43
    float m_posX;          // 0x44
    float m_posY;          // 0x48
};

struct OrderData {
    short a1;
    short a2;
    short a3;
    short pad_06;
    int t0;
    int t1;
    int t2;
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
    virtual void Method28(short a1, short a2, short a3, int t0, int t1, int t2); // 0x28 (vfn 8)
    virtual void Method2C(int a1, float f12, float f13); // 0x2C (vfn 9)
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
    virtual int Method60(int a1, int a2); // 0x60 (vfn 22)
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
    virtual int MethodE8(); // 0xE8 (vfn 56)

    char pad_04[0x2A];     // 0x4 to 0x2D
    unsigned char m_state; // 0x2E
    char pad_2F[9];        // 0x2F to 0x37
    TargetObj *m_target;   // 0x38
};

extern "C" {

void func_0014F640(TradeActionBase *self, OrderData *data) {
    self->Method28(data->a1, data->a2, data->a3, data->t0, data->t1, data->t2);
}

int func_0014F670(TradeActionBase *self, short a1, short a2, short a3) {
    void *game = self->m_target->m_game;
    ActionMgr *mgr = (ActionMgr *)*(void **)((char *)game + 0x1B30);
    mgr->Method118(a1, a2, a3);
    return 1;
}

int func_0014F6C0(TradeActionBase *self, int a1) {
    if (a1 == 1) {
        if (self->MethodE8() == 8) {
            return 6;
        }
    }

    if (self->m_state == 3) {
        self->Method2C(1, self->m_target->m_posX, self->m_target->m_posY);
        return 5;
    }

    float pos[3];
    self->m_target->Method220(pos);
    int res = func_00148050(self, pos, 1, 1, 0, 0, 1, 0);
    if (res == -1) {
        return 5;
    }

    if (self->Method60(res, 1) == 1) {
        return 6;
    }

    return 5;
}

}
