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

void func_00226D90(void *stream, void *data, int size);
void func_00150770(TradeAction *self, int count);
void func_001508F0(TradeAction *self, void *item, int flag);
void func_00150CC0(TradeAction *self, void *item);
void *func_001FC6C0();
void func_001FDCC0(void *obj, void *stream);

void func_00146A40(TradeAction *self, void *stream) {
    ActionItem1Packed item;
    ActionItem1 item_unpacked;
    ActionItem2Packed item2;
    ActionItem2 item2_unpacked;
    int ival;
    float fval;
    int has164;
    Vector16 vec;
    int ival2;

    func_00226D90(stream, &ival, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field44 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field46 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field48 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field4A = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field4C = ival;

    func_00226D90(stream, &self->m_float50, 4);
    func_00226D90(stream, &self->m_float54, 4);
    func_00226D90(stream, &self->m_float58, 4);
    func_00226D90(stream, &self->m_float5C, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field62 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field60 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field64 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field66 = ival;

    func_00226D90(stream, &self->m_field138, 4);
    func_00226D90(stream, &self->m_field13C, 4);
    func_00226D90(stream, &self->m_field144, 4);
    func_00226D90(stream, &self->m_field140, 4);
    func_00226D90(stream, &self->m_field148, 4);
    func_00226D90(stream, &self->m_field14C, 4);
    func_00226D90(stream, &self->m_field150, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field4E = ival;

    func_00226D90(stream, &fval, 4);

    func_00226D90(stream, &vec, 16);

    func_00226D90(stream, &ival, 4);
    int count1 = (unsigned char)ival;

    for (int i = 0; i < count1; i++) {
        func_00226D90(stream, &item, 36);
        item_unpacked.m_s0 = item.m_s0;
        item_unpacked.m_s2 = item.m_s2;
        item_unpacked.m_s4 = item.m_s4;
        item_unpacked.m_s6 = item.m_s6;
        item_unpacked.m_f8 = item.m_f8;
        item_unpacked.m_fC = item.m_fC;
        item_unpacked.m_f10 = item.m_f10;
        item_unpacked.m_f14 = item.m_f14;
        func_001508F0(self, &item_unpacked, 0);
    }

    func_00226D90(stream, &ival, 4);
    int count2 = (unsigned char)ival;

    for (int j = 0; j < count2; j++) {
        func_00226D90(stream, &item2, 24);
        item2_unpacked.m_s0 = item2.m_s0;
        item2_unpacked.m_s2 = item2.m_s2;
        item2_unpacked.m_s4 = item2.m_s4;
        item2_unpacked.m_i8 = item2.m_i8;
        item2_unpacked.m_iC = item2.m_iC;
        item2_unpacked.m_i10 = item2.m_i10;
        func_00150CC0(self, &item2_unpacked);
    }

    func_00226D90(stream, &ival2, 4);

    for (int k = 0; k < ival2; k++) {
        func_00226D90(stream, &ival, 4);
        self->m_fieldA4[k] = ival;
    }

    func_00226D90(stream, &self->m_field2D, 1);
    func_00226D90(stream, &self->m_field2E, 1);
    func_00226D90(stream, &self->m_float154, 4);
    func_00226D90(stream, &self->m_float158, 4);
    func_00226D90(stream, &self->m_field15C, 4);
    func_00226D90(stream, &self->m_field2F, 1);
    func_00226D90(stream, &self->m_field160, 4);

    func_00226D90(stream, &has164, 4);
    if (has164 != 0) {
        self->m_field164 = func_001FC6C0();
        func_001FDCC0(self->m_field164, stream);
    }
    func_00226D90(stream, &self->m_field168, 4);

    func_00226D90(stream, &ival, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field68 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field6A = ival;

    func_00226D90(stream, &self->m_field70, 4);
    func_00226D90(stream, self->m_field74, 12);

    func_00226D90(stream, &ival, 4);
    self->m_field6C = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field6E = ival;

    func_00226D90(stream, self->m_field80, 12);
    func_00226D90(stream, &self->m_field8C, 4);
    func_00226D90(stream, &self->m_field16C, 4);

    func_00226D90(stream, &ival, 4);
    int count3 = (unsigned char)ival;

    for (int m = 0; m < count3; m++) {
        func_00150770(self, m);
        func_00226D90(stream, &self->m_field174[m].m_p1, 4);
        func_00226D90(stream, &self->m_field174[m].m_p2, 4);
    }

    func_00226D90(stream, &ival, 4);
    self->m_field170 = ival;
    func_00226D90(stream, &self->m_field30, 1);
}

}
