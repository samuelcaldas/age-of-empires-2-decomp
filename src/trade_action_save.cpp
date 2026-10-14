#include "sub_list.h"

struct ActionItem1 {
    short m_s0;
    short m_s2;
    short m_s4;
    short m_s6;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
};

struct ActionItem1Packed {
    int m_s0;
    int m_s2;
    int m_s4;
    int m_s6;
    int m_neg1;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
};

struct ActionItem2 {
    short m_s0;
    short m_s2;
    short m_s4;
    char m_pad6[2];
    int m_i8;
    int m_iC;
    int m_i10;
};

struct ActionItem2Packed {
    int m_s0;
    int m_s2;
    int m_s4;
    int m_i8;
    int m_iC;
    int m_i10;
};

struct ActionItem3 {
    int m_p1;
    int m_p2;
};

struct Vector16 {
    float x, y, z, w;
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
    void *m_target;       // 0x38
    ActionItem1 *m_buf3C; // 0x3C
    ActionItem2 *m_buf40; // 0x40
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
    short m_field68;      // 0x68
    short m_field6A;      // 0x6A
    short m_field6C;      // 0x6C
    unsigned char m_field6E; // 0x6E
    char pad_6F;
    int m_field70;        // 0x70
    int m_field74[3];     // 0x74, 0x78, 0x7C (12 bytes)
    int m_field80[3];     // 0x80, 0x84, 0x88 (12 bytes)
    int m_field8C;        // 0x8C
    char m_field90[0x14]; // 0x90
    short *m_fieldA4;     // 0xA4
    int m_fieldA8;        // 0xA8
    int m_fieldAC;        // 0xAC
    int m_fieldB0;        // 0xB0
    char pad_B4[0x80];    // 0xB4 to 0x134
    int m_field134;       // 0x134
    int m_field138;       // 0x138
    int m_field13C;       // 0x13C
    int m_field140;       // 0x140
    int m_field144;       // 0x144
    int m_field148;       // 0x148
    int m_field14C;       // 0x14C
    int m_field150;       // 0x150
    float m_float154;     // 0x154
    float m_float158;     // 0x158
    int m_field15C;       // 0x15C
    int m_field160;       // 0x160
    void *m_field164;     // 0x164
    int m_field168;       // 0x168
    int m_field16C;       // 0x16C
    short m_field170;     // 0x170
    unsigned char m_field172; // 0x172
    unsigned char m_field173; // 0x173
    ActionItem3 *m_field174; // 0x174
};

extern "C" {

extern Vector16 D_38FB00;
void func_00226F70(void *stream, void *data, int size);
void func_1FDBA0(void *obj, void *stream);

void func_00146400(TradeAction *self, void *stream) {
    Vector16 vec;
    ActionItem1Packed item;
    ActionItem2Packed item2;
    int ival;
    float fval;
    int ival2;
    int has164;

    ival = -1;
    func_00226F70(stream, &ival, 4);

    ival = self->m_field44;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field46;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field48;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field4A;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field4C;
    func_00226F70(stream, &ival, 4);

    func_00226F70(stream, &self->m_float50, 4);
    func_00226F70(stream, &self->m_float54, 4);
    func_00226F70(stream, &self->m_float58, 4);
    func_00226F70(stream, &self->m_float5C, 4);

    ival = self->m_field62;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field60;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field64;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field66;
    func_00226F70(stream, &ival, 4);

    func_00226F70(stream, &self->m_field138, 4);
    func_00226F70(stream, &self->m_field13C, 4);
    func_00226F70(stream, &self->m_field144, 4);
    func_00226F70(stream, &self->m_field140, 4);
    func_00226F70(stream, &self->m_field148, 4);
    func_00226F70(stream, &self->m_field14C, 4);
    func_00226F70(stream, &self->m_field150, 4);

    ival = self->m_field4E;
    func_00226F70(stream, &ival, 4);

    fval = 1.0f;
    func_00226F70(stream, &fval, 4);

    vec = D_38FB00;
    func_00226F70(stream, &vec, 16);

    ival = self->m_field31;
    func_00226F70(stream, &ival, 4);

    for (int i = 0; i < (int)self->m_field31; i++) {
        item.m_s0 = self->m_buf3C[i].m_s0;
        item.m_s2 = self->m_buf3C[i].m_s2;
        item.m_s4 = self->m_buf3C[i].m_s4;
        item.m_s6 = self->m_buf3C[i].m_s6;
        item.m_f8 = self->m_buf3C[i].m_f8;
        item.m_fC = self->m_buf3C[i].m_fC;
        item.m_f10 = self->m_buf3C[i].m_f10;
        item.m_f14 = self->m_buf3C[i].m_f14;
        item.m_neg1 = -1;
        func_00226F70(stream, &item, 36);
    }

    ival = self->m_field32;
    func_00226F70(stream, &ival, 4);

    for (int j = 0; j < (int)self->m_field32; j++) {
        item2.m_s0 = self->m_buf40[j].m_s0;
        item2.m_s2 = self->m_buf40[j].m_s2;
        item2.m_s4 = self->m_buf40[j].m_s4;
        item2.m_i8 = self->m_buf40[j].m_i8;
        item2.m_iC = self->m_buf40[j].m_iC;
        item2.m_i10 = self->m_buf40[j].m_i10;
        func_00226F70(stream, &item2, 24);
    }

    ival2 = self->m_fieldA8;
    func_00226F70(stream, &ival2, 4);

    for (int k = 0; k < self->m_fieldA8; k++) {
        short *v0;
        if (k > self->m_fieldB0 - 1) {
            v0 = self->m_fieldA4;
        } else {
            v0 = self->m_fieldA4;
        }
        ival = *(short *)((char *)v0 + (k << 1));
        func_00226F70(stream, &ival, 4);
    }

    func_00226F70(stream, &self->m_field2D, 1);
    func_00226F70(stream, &self->m_field2E, 1);
    func_00226F70(stream, &self->m_float154, 4);
    func_00226F70(stream, &self->m_float158, 4);
    func_00226F70(stream, &self->m_field15C, 4);
    func_00226F70(stream, &self->m_field2F, 1);
    func_00226F70(stream, &self->m_field160, 4);

    has164 = 0;
    if (self->m_field164 != 0) {
        has164 = 1;
    }
    func_00226F70(stream, &has164, 4);

    if (has164 == 1) {
        func_1FDBA0(self->m_field164, stream);
    }
    func_00226F70(stream, &self->m_field168, 4);

    ival = 1;
    func_00226F70(stream, &ival, 4);

    ival = self->m_field68;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field6A;
    func_00226F70(stream, &ival, 4);

    func_00226F70(stream, &self->m_field70, 4);
    func_00226F70(stream, self->m_field74, 12);

    ival = self->m_field6C;
    func_00226F70(stream, &ival, 4);
    ival = self->m_field6E;
    func_00226F70(stream, &ival, 4);

    func_00226F70(stream, self->m_field80, 12);
    func_00226F70(stream, &self->m_field8C, 4);
    func_00226F70(stream, &self->m_field16C, 4);

    ival = self->m_field172;
    func_00226F70(stream, &ival, 4);

    for (int m = 0; m < (int)self->m_field172; m++) {
        func_00226F70(stream, &self->m_field174[m].m_p1, 4);
        func_00226F70(stream, &self->m_field174[m].m_p2, 4);
    }

    ival = self->m_field170;
    func_00226F70(stream, &ival, 4);
    func_00226F70(stream, &self->m_field30, 1);
}

}
