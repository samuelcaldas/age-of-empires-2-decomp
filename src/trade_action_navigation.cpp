#pragma exceptions off
#include "sub_list.h"

class TargetObj;

extern "C" {
extern int D_00F99940;
extern int *D_00F99920;

TargetObj* func_1510D0(void *self, int id);
void* func_332e60(void *timer, int a1);
void func_001471B0(void *self, int a1);
void func_14bd90(void *self, int a1, short a2, float f12, float f13, float f14);
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
    virtual int Method180(int a1, int a2);          // 0x180
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
    virtual void Method1AC();                       // 0x1AC
};

struct PosEntry {
    float x;
    float y;
    int pad0;
    int pad1;
};

class TradeAction {
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
    virtual void Method2C(float x, float z, int a1); // 0x2C
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
    virtual void Method5C(int a1);                   // 0x5C

    char pad_04[0x34];                               // 0x4 to 0x37
    TargetObj *m_target;                             // 0x38
    char pad_3C[0x8];                                // 0x3C to 0x43
    short m_field44;                                 // 0x44
    short m_field46;                                 // 0x46
    short m_field48;                                 // 0x48
    char pad_4A[0x16];                               // 0x4A to 0x5F
    short m_field60;                                 // 0x60
    short m_field62;                                 // 0x62
    char pad_64[0x50];                               // 0x64 to 0xB3
    PosEntry m_posEntries[8];                        // 0xB4 to 0x133
    int m_field134;                                  // 0x134
    char pad_138[0x1C];                              // 0x138 to 0x153
    float m_float154;                                // 0x154
    float m_float158;                                // 0x158
};

extern "C" {

int func_00149C20(TradeAction *self, float *s3) {
    TargetObj *target = self->m_target;
    self->Method2C(*(float *)((char *)target + 0x44), *(float *)((char *)target + 0x48), 1);

    int s0 = -1;
    float f20 = 0.0f;

    for (int s1 = 0; s1 < D_00F99940; s1++) {
        TargetObj *v0 = func_1510D0(self, D_00F99920[s1 * 2]);
        if (!v0) {
            continue;
        }

        if (s0 == -1 || *(float *)((char *)v0 + 0x30) < f20) {
            f20 = *(float *)((char *)v0 + 0x30);
            s0 = D_00F99920[s1 * 2];
        }
    }

    if (s3) {
        *s3 = f20;
    }

    return s0;
}

int func_00149D20(TradeAction *self, int a1, int a2) {
    if (self->m_field134 >= 8) {
        self->m_field134 = 0;
    }

    self->m_posEntries[self->m_field134].x = (float)a1;
    self->m_posEntries[self->m_field134].y = (float)a2;
    self->m_field134++;
    return 1;
}

int func_00149D80(TradeAction *self, int a1, int a2) {
    float f2 = (float)a1;
    float f0 = (float)a2;

    for (int v1 = 0; v1 < self->m_field134; v1++) {
        if (self->m_posEntries[v1].x != f2) {
            continue;
        }
        if (self->m_posEntries[v1].y == f0) {
            return 1;
        }
    }

    return 0;
}

int func_00149E00() {
    return 1;
}

int func_00149E10() {
    return 1;
}

int func_00149E20(TradeAction *self, int a1) {
    self->m_field62 = self->m_field48;

    if (!a1 || self->m_field48 + 0x64 == self->m_field44 || self->m_field44 == 0x2C7) {
        self->m_field60 = self->m_field44;
        self->m_field44 = -1;
        self->m_field46 = -1;

        TargetObj *target = self->m_target;
        void *v1 = *(void **)((char *)target + 4);
        if (*(short *)((char *)v1 + 0xE) != 0x12) {
            self->m_float154 = *(float *)((char *)target + 0x44);
            TargetObj *v0 = self->m_target;
            self->m_float158 = *(float *)((char *)v0 + 0x48);
        }
    }

    TargetObj *target = self->m_target;
    target->Method1AC();

    self->m_field48 = -1;
    return 1;
}

int func_00149ED0(TradeAction *self, int a1, int a2) {
    if (!a2 && self->m_field48 == 0x265) {
        return 0;
    }

    self->Method5C(1);

    if (self->m_target->Method180(a1, a2) == 1) {
        void *game = *(void **)((char *)self->m_target + 8);
        void *timer = *(void **)((char *)game + 0xB98);
        void *entity = func_332e60(timer, a1);

        func_001471B0(self, 0x265);

        if (!entity) {
            func_14bd90(self, a1, -1, 0.0f, 0.0f, 0.0f);
        } else {
            void *v0 = *(void **)((char *)entity + 4);
            short type = *(short *)((char *)v0 + 0xE);
            float x = *(float *)((char *)entity + 0x44);
            float y = *(float *)((char *)entity + 0x48);
            float z = *(float *)((char *)entity + 0x4C);
            func_14bd90(self, a1, type, x, y, z);
        }

        return 1;
    }

    return 0;
}

}
