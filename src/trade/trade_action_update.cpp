#include "sub_list.h"

struct TargetObj {
    void *m_vtable;       // 0x0
    char m_pad4[4];       // 0x4
    void *m_game;         // 0x8
    char m_padC[0x2D];    // 0xC
    unsigned char m_state; // 0x39
};

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

struct ActionItem2 {
    short m_s0;
    short m_s2;
    short m_s4;
    char m_pad6[2];
    int m_i8;
    int m_iC;
    int m_i10;
};

struct ActionItem3 {
    int m_p1;
    int m_p2;
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
    float m_float15C;     // 0x15C
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

extern char D_004E305C;
extern int D_004E3060;
extern int D_004E3064;
extern int D_004E3068;

int func_00150670();
int func_001510D0(TradeAction *self, int a1);
int func_0014BCE0(TradeAction *self);
void func_00202B10(void *p1, void *p2);
void func_002690D0(void *p1, void *p2);
int func_00123350(void *p1, void *p2);
void func_0026AD20(void *p1, void *p2, float f1, float f2);
void func_0026AD60(void *p1, void *p2, float f1, float f2);
short func_001471C0(TradeAction *self);
int func_00333B30(void *p1, void *p2, int a2, int a3);
int func_00150F50(TradeAction *self, int a1, int a2);
int func_00151120(TradeAction *self, int a1, int a2, int a3);
int func_001511A0(TradeAction *self, int a1, int a2);
int func_001BBE40(void *p1, void *p2);
int func_001BBF40(void *p1, void *p2);
int func_0014BF10(TradeAction *self);

typedef int (*VirtualMethod_1D8)(void *target);

int func_001471E0(TradeAction *self, int a1) {
    D_004E305C = 0;
    D_004E3060 = 0;
    D_004E3064 = 0;

    void *timer = *(void **)((char *)*(void **)((char *)self->m_target + 8) + 0xB98);
    float dt = *(float *)((char *)timer + 0xAC);
    self->m_float15C += dt;
    self->m_field170 = -1;

    if (self->m_target->m_state >= 3) {
        return 0;
    }

    func_00150670();
    VirtualMethod_1D8 vmethod = *(VirtualMethod_1D8 *)((char *)*(void **)self->m_target + 0x1D8);
    int action = vmethod(self->m_target) & 0xFF;

    if (self->m_field4A != -1) {
        int r = func_001510D0(self, self->m_field4A);
        if (r == 0) {
            self->m_field4A = -1;
            if (self->m_field48 != 600) {
                // fall through
            }
        }
    }
    return 1;
}

}
