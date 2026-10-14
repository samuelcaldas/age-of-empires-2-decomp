#include "sub_list.h"

struct TargetObj {
    char pad[8];
    void *m_field8;
};

struct TradeAction {
    void *m_vtable;
    char m_field04[0x28]; // 0x4 to 0x2B
    char m_field2C;       // 0x2C
    char m_field2D;       // 0x2D
    char m_field2E;       // 0x2E
    char m_field2F;       // 0x2F
    char m_field30;       // 0x30
    unsigned char m_field31; // 0x31
    unsigned char m_field32; // 0x32
    unsigned char m_field33; // 0x33
    unsigned char m_field34; // 0x34
    unsigned char m_field35; // 0x35
    char pad_36[2];       // 0x36-0x37
    TargetObj *m_target;  // 0x38
    void *m_buf3C;        // 0x3C
    void *m_buf40;        // 0x40
    short m_field44;      // 0x44
    short m_field46;      // 0x46
    short m_field48;      // 0x48
    short m_field4A;      // 0x4A
    short m_field4C;      // 0x4C
    short m_field4E;      // 0x4E
    float m_float50;      // 0x50
    float m_float54;      // 0x54
    float m_float58;      // 0x58
    float m_float5C;      // 0x5C
    short m_field60;      // 0x60
    short m_field62;      // 0x62
    short m_field64;      // 0x64
    short m_field66;      // 0x66
};

extern "C" {

void *func_00147140(TradeAction *self) {
    return self->m_target->m_field8;
}

unsigned char func_00147150(TradeAction *self) {
    return self->m_field31;
}

short func_00147160(TradeAction *self) {
    return self->m_field44;
}

void func_00147170(TradeAction *self, short val) {
    self->m_field60 = self->m_field44;
    self->m_field44 = val;
}

short func_00147180(TradeAction *self) {
    return self->m_field46;
}

short func_00147190(TradeAction *self) {
    return self->m_field48;
}

void func_001471A0(TradeAction *self, short val) {
    self->m_field62 = self->m_field48;
    self->m_field48 = val;
}

short func_001471B0(TradeAction *self) {
    return self->m_field4A;
}

short func_001471C0(TradeAction *self) {
    return self->m_field4C;
}

short func_001471D0(TradeAction *self) {
    return self->m_field66;
}

}
