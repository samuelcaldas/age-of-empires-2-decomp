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

class TargetObj {
public:
    virtual void vfn0();
    void *m_node;          // 0x4
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19();
    virtual int v20();
    virtual int Method5C(int a1);                                                       // 0x5C (slot 21)
    virtual int Method60(int a1, int a2);                                               // 0x60 (slot 22)
    virtual int Method64(int a1);                                                       // 0x64 (slot 23)
    virtual int Method68(int a1, int a2);                                               // 0x68 (slot 24)
    virtual int Method6C(int a1, int a2);                                               // 0x6C (slot 25)
    virtual int Method70(int a1, int a2);                                               // 0x70 (slot 26)
    virtual int Method74(int a1, int a2);                                               // 0x74 (slot 27)
    virtual int Method78(int a1, int a2);                                               // 0x78 (slot 28)
    virtual int Method7C(int a1, int a2);                                               // 0x7C (slot 29)
    virtual int v30();
    virtual int Method84(int a1, int a2, int a3);                                       // 0x84 (slot 31)
    virtual int Method88(int a1, int a2);                                               // 0x88 (slot 32)
    virtual int Method8C(float f12, float f13, int a1);                                 // 0x8C (slot 33)
    virtual int Method90(int a1, float f12, float f13, float f14);                     // 0x90 (slot 34)
    virtual int v35(); virtual int v36();
    virtual int Method9C(int a1, float f12, float f13, float f14, float f15, int a2);   // 0x9C (slot 37)
    virtual int v38(); virtual int v39();
    virtual int MethodA8(int a1, int a2);                                               // 0xA8 (slot 40)
    virtual int MethodAC(int a1, int a2, float f12);                                   // 0xAC (slot 41)
    virtual int MethodB0(int a1, int a2, float f12);                                   // 0xB0 (slot 42)
    virtual int MethodB4(float f12, float f13, float f14, int a1);                     // 0xB4 (slot 43)
    virtual int MethodB8(int a1, int a2, int a3, int t0);                               // 0xB8 (slot 44)
    virtual int MethodBC(int a1, int a2, int a3);                                       // 0xBC (slot 45)

    char pad_04[0x31 - 0x4];
    unsigned char m_entry_count; // offset 49 = 0x31
    char pad_32[0x38 - 0x32];
    TargetObj *m_target;         // offset 56 = 0x38
    ActionEntry *m_entries;      // offset 60 = 0x3C
    char pad_40[0x44 - 0x40];
    short m_field44;             // offset 68 = 0x44
    short m_field46;             // offset 70 = 0x46
    short m_field48;             // offset 72 = 0x48
    short m_field4A;             // offset 74 = 0x4A
};

extern "C" {
void func_0014BCE0(void *self);
void func_001471B0(void *self, int a1);
int func_123350(float val);

int func_0014CAB0(TradeAction *self, ActionEntry *action, int a2) {
    int s0 = 0;

    switch (action->m_type) {
        case 706:
            func_0014BCE0(self);
            self->Method5C(1);
            s0 = 1;
            break;
        case 710:
            s0 = self->Method9C(1, action->m_f8, action->m_fC, action->m_f10, action->m_f14, 0);
            break;
        case 700:
            s0 = self->Method60(action->m_field6, 1);
            break;
        case 701:
            s0 = self->Method64(action->m_field6);
            break;
        case 729:
            if (*(short *)((char *)self->m_target->m_node + 8) != 0x80) {
                if (action->m_field6 != -1) {
                    s0 = self->MethodB0(action->m_field6, 1, action->m_f14);
                } else {
                    s0 = self->MethodB4(action->m_f8, action->m_fC, action->m_f14, 1);
                }
            }
            break;
        case 718:
            s0 = self->Method78(action->m_field6, 1);
            break;
        case 721:
            s0 = self->Method8C(action->m_f8, action->m_fC, 1);
            break;
        case 722: {
            int x = func_123350(action->m_f8);
            int y = func_123350(action->m_fC);
            s0 = self->MethodB8(action->m_field6, x, y, 1);
            break;
        }
        case 723: {
            int x = func_123350(action->m_f8);
            int y = func_123350(action->m_fC);
            s0 = self->MethodBC(x, y, 1);
            break;
        }
        case 730: {
            int x = func_123350(action->m_f8);
            int y = func_123350(action->m_fC);
            s0 = self->Method84(x, y, 1);
            break;
        }
        case 705: {
            int x = func_123350(action->m_f8);
            int y = func_123350(action->m_fC);
            s0 = self->Method84(x, y, 1);
            func_001471B0(self, 0x276);
            break;
        }
        case 702:
            s0 = self->Method7C(action->m_field6, 1);
            break;
        case 724:
            s0 = self->Method9C(1, action->m_f8, action->m_fC, action->m_f10, action->m_f14, 0);
            break;
        case 712:
            s0 = self->MethodAC(action->m_field6, 1, action->m_f14);
            break;
        case 717:
            s0 = self->Method88(action->m_field6, 1);
            break;
        case 714:
            s0 = self->Method90(1, action->m_f8, action->m_fC, action->m_f10);
            break;
        case 703:
            s0 = self->Method74(action->m_field6, 1);
            break;
        case 704:
            s0 = self->Method70(action->m_field6, 1);
            break;
        case 728:
            self->m_field48 = 628;
            self->m_field44 = 728;
            s0 = 1;
            break;
        case 709:
            s0 = self->Method6C(action->m_field6, 1);
            break;
        case 713:
            s0 = self->Method68(action->m_field6, 1);
            break;
        case 711:
            s0 = self->MethodA8(1, -1);
            break;
        case 707:
            s0 = self->MethodA8(1, -1);
            break;
        default:
            break;
    }

    if (s0 == 1) {
        short actType = action->m_type;
        if (actType == 706) {
            self->m_field44 = -1;
            self->m_field46 = -1;
        } else if (actType == 729) {
            self->m_field44 = 700;
            self->m_field46 = action->m_field4;
        } else if (actType == 700 && *(short *)((char *)self->m_target->m_node + 8) == 125) {
            self->m_field44 = -1;
            self->m_field4A = -1;
            self->m_field46 = action->m_field4;
        } else {
            self->m_field44 = actType;
            self->m_field46 = action->m_field4;
        }
    }

    if (a2 >= 0 && a2 < (int)self->m_entry_count && self->m_entries) {
        for (int i = a2; i < (int)self->m_entry_count - 1; i++) {
            self->m_entries[i] = self->m_entries[i + 1];
        }
        self->m_entry_count--;
    }

    return s0 == 1 ? 1 : 0;
}

}
