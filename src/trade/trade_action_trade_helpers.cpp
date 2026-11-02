#pragma exceptions off
#include "sub_list.h"

struct ActionEntry {
    short m_pad0;     // 0x0
    short m_type;     // 0x2
    short m_field4;   // 0x4
    short m_field6;   // 0x6
    float m_f8;       // 0x8
    float m_fC;       // 0xC
    float m_f10;      // 0x10
    float m_f14;      // 0x14
};

class HelperTarget {
public:
    virtual void vfn0();
    char pad_04[0x24 - 0x4];
    short m_field24; // 0x24 (offset 36)
};

class HelperObj {
public:
    virtual void vfn0(); virtual void vfn1(); virtual void vfn2(); virtual void vfn3();
    virtual void vfn4(); virtual void vfn5(); virtual void vfn6(); virtual void vfn7();
    virtual void vfn8(); virtual void vfn9(); virtual void vfn10(); virtual void vfn11();
    virtual void vfn12(); virtual void vfn13(); virtual void vfn14(); virtual void vfn15();
    virtual void vfn16();
    virtual void Method4C(void *arg); // 0x4C (vfn 18, offset 0x48 + 4 = 0x4C)
    virtual void vfn19(); // offset 0x50
    virtual void vfn20(); virtual void vfn21(); virtual void vfn22(); virtual void vfn23();
    virtual void vfn24(); virtual void vfn25(); virtual void vfn26(); virtual void vfn27();
    virtual void vfn28(); virtual void vfn29(); virtual void vfn30(); virtual void vfn31();
    virtual void vfn32(); virtual void vfn33(); virtual void vfn34(); virtual void vfn35();
    virtual void vfn36(); virtual void vfn37(); virtual void vfn38(); virtual void vfn39();
    virtual void vfn40(); virtual void vfn41(); virtual void vfn42(); virtual void vfn43();
    virtual void vfn44(); virtual void vfn45(); virtual void vfn46(); virtual void vfn47();
    virtual void vfn48(); virtual void vfn49(); virtual void vfn50(); virtual void vfn51();
    virtual void vfn52(); virtual void vfn53(); virtual void vfn54(); virtual void vfn55();
    virtual void vfn56(); virtual void vfn57(); virtual void vfn58(); virtual void vfn59();
    virtual void vfn60(); virtual void vfn61(); virtual void vfn62(); virtual void vfn63();
    virtual void vfn64(); virtual void vfn65(); virtual void vfn66(); virtual void vfn67();
    virtual void vfn68(); virtual void vfn69(); virtual void vfn70(); virtual void vfn71();
    virtual void vfn72(); virtual void vfn73(); virtual void vfn74(); virtual void vfn75();
    virtual void vfn76(); virtual void vfn77(); virtual void vfn78(); virtual void vfn79();
    virtual void vfn80(); virtual void vfn81(); virtual void vfn82(); virtual void vfn83();
    virtual void vfn84(); virtual void vfn85(); virtual void vfn86(); virtual void vfn87();
    virtual void vfn88(); virtual void vfn89(); virtual void vfn90(); virtual void vfn91();
    virtual void vfn92(); virtual void vfn93(); virtual void vfn94(); virtual void vfn95();
    virtual void vfn96(); virtual void vfn97(); virtual void vfn98(); virtual void vfn99();
    virtual void vfn100(); virtual void vfn101(); virtual void vfn102(); virtual void vfn103();
    virtual void vfn104(); virtual void vfn105(); virtual void vfn106(); virtual void vfn107();
    virtual void vfn108(); virtual void vfn109(); virtual void vfn110(); virtual void vfn111();
    virtual void vfn112(); virtual void vfn113(); virtual void vfn114(); virtual void vfn115();
    virtual void vfn116(); virtual void vfn117(); virtual void vfn118(); virtual void vfn119();
    virtual void vfn120(); virtual void vfn121(); virtual void vfn122(); virtual void vfn123();
    virtual void vfn124(); virtual void vfn125(); virtual void vfn126(); virtual void vfn127();
    virtual void vfn128(); virtual void vfn129(); virtual void vfn130(); virtual void vfn131();
    virtual void vfn132(); virtual void vfn133(); virtual void vfn134(); virtual void vfn135();
    virtual void vfn136(); virtual void vfn137(); virtual void vfn138(); virtual void vfn139();
    virtual void vfn140(); virtual void vfn141(); virtual void vfn142(); virtual void vfn143();
    virtual void vfn144(); virtual void vfn145(); virtual void vfn146(); virtual void vfn147();
    virtual void vfn148(); virtual void vfn149(); virtual void vfn150(); virtual void vfn151();
    virtual void vfn152(); virtual void vfn153(); virtual void vfn154(); virtual void vfn155();
    virtual void vfn156(); virtual void vfn157(); virtual void vfn158(); virtual void vfn159();
    virtual void vfn160(); virtual void vfn161(); virtual void vfn162(); virtual void vfn163();
    virtual void vfn164(); virtual void vfn165(); virtual void vfn166(); virtual void vfn167();
    virtual void vfn168(); virtual void vfn169(); virtual void vfn170(); virtual void vfn171();
    virtual void vfn172(); virtual void vfn173(); virtual void vfn174(); virtual void vfn175();
    virtual void vfn176(); virtual void vfn177(); virtual void vfn178();
    virtual void* Method2D0(); // 0x2D0 (offset 0x2D0)

    void *m_node;    // 0x4
    void *m_game;    // 0x8
    void *m_fieldC;  // 0xC
    int m_field10;   // 0x10
    char pad_14[0x54]; // 0x14 to 0x67
    int m_field68;   // 0x68
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18();

    char pad_04[49 - 4];
    unsigned char m_entry_count; // offset 49 = 0x31
    char pad_32[56 - 50];
    HelperTarget *m_target;         // offset 56 = 0x38
    ActionEntry *m_entries;      // offset 60 = 0x3C
};

extern "C" {
int func_00263700(void *a0, void *a1, void *a2, void *a3);
int func_00263760(void *a0, void *a1, void *a2, void *a3);
void func_002637C0(void *a0);
void func_00263A30(void *a0);
void func_0026A540(void *a0, int a1);
void func_00263CC0();
int func_226D90(void *a0, void *a1, int sz);

int func_00151BA0(HelperObj *a0, void *a1, void *a2);
int func_00151C20(void *a0, void *a1);

int func_00151960(TradeAction *self) {
    int count = self->m_entry_count;
    int a2 = 0;
    while (a2 < count) {
        ActionEntry *e = (ActionEntry *)((char *)self->m_entries + a2 * 24);
        if (e->m_field6 >= 0 && e->m_pad0 == self->m_target->m_field24) {
            return a2;
        }
        a2++;
    }
    return -1;
}

int func_001519D0(void *self, int a1) {
    if (a1 == 15 || (unsigned)(a1 - 7) <= 3 || a1 == 32) return 1;
    return 0;
}

int func_00151A10(TradeAction *self, int a1) {
    for (int i = 0; i < (int)*(unsigned char *)((char *)self + 44); i++) {
        if (*(unsigned char *)((char *)self + 4 + i) == a1) {
            return 1;
        }
    }
    return 0;
}

int func_00151A50() {
    return 0;
}

int func_00151A60() {
    return -1;
}

void func_00151A70(void *s1, void *s2, void *s0, void *a3, float f12, float f13, float f14) {
    if (func_00263700(a3, s1, s2, s0)) {
        func_00151BA0((HelperObj *)a3, s1, s2);
    }
}

void func_00151B10(void *s1, void *s2, void *s0, void *a3) {
    if (func_00263760(a3, s1, s2, s0)) {
        func_00151C20(s2, a3);
    }
}

void func_00151B80(void *self, void *a1) {
    if (a1) {
        func_002637C0(self);
    }
}

int func_00151BA0(HelperObj *s0, void *a1, void *a2) {
    func_00263A30(s0);
    func_0026A540(s0, 0);
    s0->m_field68 = 0;
    if (!s0->m_fieldC) {
        s0->m_fieldC = s0->Method2D0();
        s0->m_field10 = 0;
        void *node = s0->m_node;
        s0->Method4C(*(void **)((char *)node + 0x10));
    }
    return 1;
}

int func_00151C20(void *a0, void *a1) {
    func_00263CC0();
    func_226D90(a1, (char *)a0 + 104, 4);
    return 1;
}

}
