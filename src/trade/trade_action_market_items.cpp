#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_00332DA0(void *obj);
int func_00202B10(void *obj);
void *func_001510D0(void *self, int id);

struct SearchItem {
    int id;
    int field_4;
};

#define D_00F99920 (*(SearchItem **)0x00F99920)
#define D_00F99940 (*(int *)0x00F99940)
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
    virtual float Method88(short a1, int a2, int a3, float f12, void *t0); // 0x88 (vfn 32)
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
    virtual float Method108(void *a1);                          // 0x108 (vfn 64)

    char pad_04[4];        // 0x4
    void *m_field8;        // 0x8
    char pad_0C[0x38];     // 0xC to 0x43
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
    MarketObj *m_market;   // 0x38
};

struct FoundItem {
    char pad_00[4];
    struct FoundSubItem *m_sub; // 0x4
    int m_field8;               // 0x8
};

struct FoundSubItem {
    char pad_00[0xF0];
    int m_fieldF0;   // 0xF0
    short m_fieldF4; // 0xF4
};

struct MarketData4 {
    char pad_00[0x1C];
    float m_val1C; // 0x1C
};

struct MarketData8 {
    char pad_00[0xB98];
    void *m_b98; // 0xB98
};

extern "C" {

float func_001499F0(TradeActionBase *self) {
    MarketObj *market = self->m_market;
    MarketData8 *d8 = (MarketData8 *)market->m_field8;
    int s0 = func_00332DA0(d8->m_b98);
    int valid = func_00202B10(self->m_market->m_field8);

    if (!valid || s0 < 3) {
        MarketData4 *d4 = *(MarketData4 **)((char *)self->m_market + 4);
        return 2.0f * d4->m_val1C;
    }

    int rate = 100;
    if (s0 == 3) {
        rate = 75;
    } else if (s0 == 4) {
        rate = 50;
    }

    MarketData4 *d4 = *(MarketData4 **)((char *)self->m_market + 4);
    float val = (d4->m_val1C * (float)rate) / 100.0f;
    if (val < 1.0f) {
        return 1.0f;
    }
    return val;
}

int func_00149AD0(TradeActionBase *self, float *outFloat) {
    self->Method2C(1, self->m_market->m_posX, self->m_market->m_posY);

    int s0 = -1;
    float f20 = 0.0f;

    for (int i = 0; i < D_00F99940; i++) {
        FoundItem *item = (FoundItem *)func_001510D0(self, D_00F99920[i].id);
        if (!item) {
            continue;
        }

        FoundSubItem *sub = item->m_sub;
        float score = self->m_market->Method88(sub->m_fieldF4, sub->m_fieldF0, item->m_field8, self->m_market->Method108(item), item);

        if (s0 == -1 || score > f20) {
            s0 = D_00F99920[i].id;
            f20 = score;
        }
    }

    if (outFloat) {
        *outFloat = f20;
    }

    return s0;
}

}
