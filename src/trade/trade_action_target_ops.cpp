#pragma exceptions off
#include "sub_list.h"

class TargetObj;

extern "C" {
extern int *D_50A5A0[];

void func_001471B0(void *self, int a1);
void func_0014BD20(void *self, int a1, float x, float y, float z);
void* func_332e60(void *timer, int a1);
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
    virtual int Method412(int a1, int a2); // 0x19C (slot 101)
};

class TradeAction {
public:
    virtual void vfn0();
    char pad_04[0x34];
    TargetObj *m_target; // 0x38
    char pad_3C[0xC];
    short m_field48;     // 0x48
    short m_field4A;     // 0x4A
    short m_field4C;     // 0x4C
    char pad_4E[2];      // 0x4E
    float m_float50;     // 0x50
    float m_float54;     // 0x54
    float m_float58;     // 0x58
    char pad_5C[0x8];    // 0x5C..0x63
    short m_field64;     // 0x64
    short m_field66;     // 0x66
};

extern "C" {

int func_0014BC10(TradeAction *self, int a1, int a2, int a3) {
    if (!a3 && self->m_field48 != -1) {
        return 0;
    }

    if (self->m_target->Method412(a1, a2) == 1) {
        func_001471B0(self, 0x26F);
        func_0014BD20(self, -1, (float)a1, (float)a2, 1.0f);
        return 1;
    }

    return 0;
}

void func_0014BCD0(TradeAction *self) {
    if (self->m_field4A != -1) {
        self->m_field64 = self->m_field4A;
        self->m_field66 = self->m_field4C;
        self->m_field4A = -1;
        self->m_field4C = -1;
        self->m_float50 = -1.0f;
        self->m_float54 = -1.0f;
        self->m_float58 = -1.0f;
    }
}

void func_0014BD10(TradeAction *self, short a1, float f12, float f13, float f14) {
    self->m_field64 = self->m_field4A;
    self->m_field66 = self->m_field4C;
    self->m_field4A = a1;
    self->m_float50 = f12;
    self->m_float54 = f13;
    self->m_float58 = f14;

    TargetObj *target = self->m_target;
    void *game = *(void **)((char *)target + 8);
    void *timer = *(void **)((char *)game + 0xB98);
    void *entity = func_332e60(timer, self->m_field4A);
    if (entity) {
        void *v1 = *(void **)((char *)entity + 4);
        self->m_field4C = *(short *)((char *)v1 + 0xE);
    }
}

void func_0014BD80(TradeAction *self, short a1, short a2, float f12, float f13, float f14) {
    self->m_field64 = self->m_field4A;
    self->m_field66 = self->m_field4C;
    self->m_field4A = a1;
    self->m_field4C = a2;
    self->m_float50 = f12;
    self->m_float54 = f13;
    self->m_float58 = f14;
}

int func_0014BDB0(TradeAction *self, int a1, int a2, int a3) {
    int cell = D_50A5A0[a3][a2];
    void *game = *(void **)((char *)self->m_target + 8);

    if (cell & *(int *)((char *)game + 0xC28)) {
        return 0xF;
    }

    if (cell & *(int *)((char *)game + 0xC24)) {
        return 0x80;
    }

    return 0;
}

}
