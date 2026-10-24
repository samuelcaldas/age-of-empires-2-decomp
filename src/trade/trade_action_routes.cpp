#include "sub_list.h"

struct TargetObj {
    void *m_vtable;        // 0x0
    char m_pad4[0x20];     // 0x4
    short m_field24;       // 0x24
    char m_pad26[0x13];    // 0x26
    unsigned char m_state; // 0x39
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
    virtual void Method5C(int a1); // index 21 -> 0x5C

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
    virtual void MethodD8(void *buf, int a2); // index 52 -> 0xD8

    char m_field04[0x34];  // 0x4 to 0x37
    TargetObj *m_target;   // 0x38
    void *m_buf3C;         // 0x3C
    void *m_buf40;         // 0x40
    short m_field44;       // 0x44
    short m_field46;       // 0x46
    short m_field48;       // 0x48
    short m_field4A;       // 0x4A
    short m_field4C;       // 0x4C
    short m_field4E;       // 0x4E
    float m_float50;       // 0x50
    float m_float54;       // 0x54
    float m_float58;       // 0x58
    float m_float5C;       // 0x5C
    char pad_60[0x44];     // 0x60 to 0xA3
    short *m_fieldA4;      // 0xA4
    int m_fieldA8;         // 0xA8
    int m_fieldAC;         // 0xAC
    int m_fieldB0;         // 0xB0
};

extern "C" {

int func_150920(TradeAction *self, short a1, short a2, short a3, int a4,
                float f1, float f2, float f3, float f4, short a5);
int func_14BCE0(TradeAction *self);
int func_150F50(TradeAction *self, int a1);
int func_150CE0(TradeAction *self, short a1, int a2, short a3, int a4, int a5, int a6);

int func_00147A40(TradeAction *self, short a1, short a2, short a3,
                  int a4, int a5,
                  float f1, float f2, float f3, float f4,
                  int a6) {
    if (self->m_target->m_state > 2) {
        return 0;
    }

    if (!a4) {
        func_150920(self, a1, a2, a3, a5, f1, f2, f3, f4, (short)a6);
        return 1;
    }

    if (a5 == 1) {
        func_150920(self, self->m_target->m_field24, self->m_field44, self->m_field4A,
                    1, self->m_float50, self->m_float54, self->m_float58, self->m_float5C, self->m_field46);
    }

    func_150920(self, a1, a2, a3, 1, f1, f2, f3, f4, (short)a6);

    if (a2 != 0x2D9) {
        func_14BCE0(self);
        self->Method5C(1);
    }

    func_150F50(self, 0);
    self->MethodD8(self->m_buf3C, 0);

    return 1;
}

inline int CheckItem(TradeAction *self, short a1) {
    for (int i = 0; i < self->m_fieldA8 && i < self->m_fieldB0; i++) {
        if (self->m_fieldA4[i] == a1) {
            return 1;
        }
    }
    return 0;
}

int func_00147BC0(TradeAction *self, short a1, int a2, short a3, int a4, int a5, int a6) {
    if (self->m_target->m_state != 2) {
        return 0;
    }

    if (a3 == 0x2BB) {
        if (!CheckItem(self, a1)) {
            return 0;
        }
    }

    if (a3 == 0x1FB) {
        if (a4 != self->m_field48) {
            return 0;
        }
    }

    if (a3 == 0x1FA) {
        if (a4 == 0x262) {
            if (self->m_field48 != 0x262 && self->m_field48 != 0x268) {
                return 1;
            }
        }
    }

    return func_150CE0(self, a1, a2, a3, a4, a5, a6);
}

}
