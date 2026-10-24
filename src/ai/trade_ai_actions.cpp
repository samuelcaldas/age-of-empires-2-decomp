#include "sub_list.h"

struct TradeAction {
    void *m_vtable;
    char m_pad04[0x64];
    short m_field68;
    short m_field6A;
    short m_field6C;
    unsigned char m_field6E;
    char m_pad6F;
    int m_field70;
    int m_field74;
    int m_field78;
    int m_field7C;
    int m_field80;
    int m_field84;
    int m_field88;
    int m_field8C;
    char m_field90[0x14];
    void *m_fieldA4;
    int m_fieldA8;
    int m_fieldAC;
    int m_fieldB0;
};

extern "C" {

extern char D_4D79A0[];

int func_00145E20(int a0, int a1) {
    switch (a1) {
    case 0x27:
    case 0x3:
    case 0x1B:
    case 0x31:
    case 0x33:
    case 0x34:
    case 0x36:
        return 0;
    case 0x6:
    case 0x18:
    case 0xC:
    case 0x23:
    case 0x2D:
    case 0x2F:
    case 0x38:
    case 0x39:
    case 0x32:
        return 1;
    case 0x1C:
    case 0x2E:
        return 2;
    case 0:
    case 0x1A:
    case 0x17:
    case 0x24:
    case 0x2C:
        if ((unsigned int)(a0 - 6) < 2) {
            return 4;
        }
        return 3;
    case 0xD:
    case 0x37:
        if (a0 == 0x23 || a0 == 0x1A6 || a0 == 0x224) {
            return 5;
        }
        return 6;
    case 0x4:
    case 0x13:
    case 0x3A:
    case 0x3B:
        return 7;
    case 0x11:
    case 0x12:
    case 0x2B:
        return 8;
    case 0x16:
    case 0x35:
        return 9;
    case 0x14:
        return 10;
    case 0x2:
    case 0x15:
        return 11;
    default:
        return 255;
    }
}

TradeAction *func_001460B0(TradeAction *self) {
    self->m_vtable = D_4D79A0;
    self->m_field74 = 0;
    self->m_field78 = 0;
    self->m_field7C = 0;
    self->m_field80 = 0;
    self->m_field84 = 0;
    self->m_field88 = 0;
    self->m_field68 = -1;
    self->m_field6A = -1;
    self->m_field70 = 0;
    self->m_field74 = 0;
    self->m_field78 = 0;
    self->m_field7C = 0;
    self->m_field6C = -1;
    self->m_field6E = 0xFF;
    self->m_field80 = 0;
    self->m_field84 = 0;
    self->m_field88 = 0;
    self->m_fieldA4 = 0;
    self->m_fieldA8 = 0;
    self->m_fieldAC = 0;
    self->m_fieldB0 = 10;
    self->m_fieldA4 = self->m_field90;
    return self;
}

}
