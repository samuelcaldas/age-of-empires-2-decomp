#include "sub_list.h"

struct ActionItem {
    void *m_p1;
    void *m_p2;
};

struct TradeAction {
    void *m_vtable;
    char m_field04[0x28]; // 0x4 to 0x2B
    char m_field2C;       // 0x2C
    char m_field2D;       // 0x2D
    char m_field2E;       // 0x2E
    char m_field2F;       // 0x2F
    char m_field30;       // 0x30
    char m_field31;       // 0x31
    char m_field32;       // 0x32
    unsigned char m_field33; // 0x33
    unsigned char m_field34; // 0x34
    unsigned char m_field35; // 0x35
    char pad_36[2];       // 0x36-0x37
    void *m_target;       // 0x38
    void *m_buf3C;        // 0x3C
    char *m_buf40;        // 0x40
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
    int m_field74;        // 0x74
    int m_field78;        // 0x78
    int m_field7C;        // 0x7C
    int m_field80;        // 0x80
    int m_field84;        // 0x84
    int m_field88;        // 0x88
    int m_field8C;        // 0x8C
    char m_field90[0x14]; // 0x90
    void *m_fieldA4;      // 0xA4
    int m_fieldA8;        // 0xA8
    int m_fieldAC;        // 0xAC
    int m_fieldB0;        // 0xB0
    char pad_B4[0x80];    // 0xB4 to 0x134
    int m_field134;       // 0x134
    int m_field138;       // 0x138
    int m_field13C;       // 0x13C
    char pad_140[4];
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
    char pad_16C[4];
    short m_field170;     // 0x170
    char m_field172;      // 0x172
    unsigned char m_field173; // 0x173
    ActionItem *m_field174; // 0x174
};

extern "C" {

void func_00100630(void *ptr);
void *func_00100730(unsigned int size);
void func_001FC810(void *ptr);
void func_00145D50(void *ptr);
int func_001AAB30();
void *func_00117CAC(void *dst, int val, int size);
void func_0014BE20(void *self);
void func_0014BE80(void *self, int val);

void func_00146130(TradeAction *self, void *target, unsigned char p2) {
    self->m_target = target;
    self->m_field31 = 0;
    self->m_field32 = 0;
    self->m_field33 = p2;
    self->m_field34 = p2;
    self->m_field35 = p2;
    self->m_field44 = -1;
    self->m_field46 = -1;
    self->m_field48 = -1;
    self->m_field4A = -1;
    self->m_field4C = -1;
    self->m_float50 = -1.0f;
    self->m_float54 = -1.0f;
    self->m_float58 = -1.0f;
    self->m_field62 = -1;
    self->m_field60 = -1;
    self->m_field64 = -1;
    self->m_field66 = -1;
    self->m_float5C = 2.0f;
    self->m_field138 = 0;
    self->m_field13C = 0;
    self->m_field144 = 3000;
    self->m_field148 = 0;
    self->m_field14C = 0;
    self->m_field150 = 1000;
    self->m_field4E = -1;
    self->m_field134 = 0;

    for (int i = 0; i < 39; i++) {
        self->m_field04[i] = 0;
    }
    self->m_field2C = 0;
    self->m_field2D = 0;
    self->m_field2E = 3;
    self->m_float154 = *(float *)((char *)target + 0x44);
    self->m_float158 = *(float *)((char *)target + 0x48);
    self->m_field15C = 0;
    self->m_field2F = 0;
    self->m_field160 = -1;
    self->m_field164 = 0;
    self->m_field168 = 0;
    self->m_field8C = (unsigned int)func_001AAB30() % 500;
    self->m_field172 = 0;
    self->m_field173 = 0;
    self->m_field174 = 0;
    self->m_field170 = -1;
    self->m_field30 = 0;

    self->m_buf3C = func_00100730((long)self->m_field33 * 24);
    self->m_buf40 = (char *)func_00100730((long)self->m_field34 * 20);
    func_00117CAC(self->m_buf40, 0, (int)self->m_field34 * 20);

    for (int j = 0; j < (int)self->m_field34; j++) {
        *(short *)(self->m_buf40 + j * 20) = -1;
    }
    func_0014BE20(self);
    func_0014BE80(self, 1000);
}

void func_00146310(TradeAction *self) {
    if (self->m_buf3C != 0) {
        func_00100630(self->m_buf3C);
        self->m_buf3C = 0;
    }
    if (self->m_buf40 != 0) {
        func_00100630(self->m_buf40);
        self->m_buf40 = 0;
    }
    if (self->m_field164 != 0) {
        func_001FC810(self->m_field164);
        self->m_field164 = 0;
    }
    if (self->m_field174 != 0) {
        for (int i = 0; i < self->m_field173; i++) {
            func_00145D50(&self->m_field174[i]);
        }
        self->m_field174 = 0;
    }
    self->m_field172 = 0;
    self->m_field173 = 0;
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
    self->m_target = 0;
}

}
