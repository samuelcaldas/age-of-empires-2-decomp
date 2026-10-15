#pragma exceptions off
#include "sub_list.h"

#define V_SLOT_10(base) \
    virtual int v##base##0(); virtual int v##base##1(); virtual int v##base##2(); virtual int v##base##3(); virtual int v##base##4(); \
    virtual int v##base##5(); virtual int v##base##6(); virtual int v##base##7(); virtual int v##base##8(); virtual int v##base##9();

class TargetObj {
public:
    V_SLOT_10(0)
    V_SLOT_10(1)
    V_SLOT_10(2)
    V_SLOT_10(3)
    V_SLOT_10(4)
    V_SLOT_10(5)
    V_SLOT_10(6)
    V_SLOT_10(7)
    V_SLOT_10(8)
    V_SLOT_10(9)
    V_SLOT_10(10)
    V_SLOT_10(11)
    virtual int v120(); virtual int v121(); virtual int v122();
    virtual void* Method1F4(void *buf); // offset 500 = 0x1F4 (slot 123)

    void *m_node;          // 0x4
    void *m_game;          // 0x8
};

struct RouteEntry {
    char pad_00[4];
    short m_type;      // 0x4
    char pad_06[2];
    int m_target_id;   // 0x8
    char pad_0C[8];
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19();
    virtual int v20();
    virtual int Method5C(int a1);                         // 0x5C (slot 21)

    char pad_04[50 - 4];
    unsigned char m_field32; // offset 50 (0x32)
    char pad_33;
    unsigned char m_field34; // offset 52 (0x34)
    unsigned char m_field35; // offset 53 (0x35)
    char pad_36[56 - 54];
    TargetObj *m_target;     // offset 56 (0x38)
    char pad_3C[64 - 60];
    RouteEntry *m_field40;   // offset 64 (0x40)
    short m_field44;         // offset 68 (0x44)
    short m_field46;         // offset 70 (0x46)
    short m_field48;         // offset 72 (0x48)
    char pad_4A[312 - 74];
    int m_field138;          // offset 312 (0x138)
    char pad_13C[356 - 316];
    void *m_field164;        // offset 356 (0x164)
    char m_field168[32];     // offset 360 (0x168)
};

extern "C" {
void func_0014BCE0(void *self);
void* func_332e60(void *timer, int a1);
void func_00100630(void *p);
void* func_00100730(int sz);
void func_001FC810(void *obj);

void func_00150F50(TradeAction *self, int a1) {
    for (int t0 = 0; t0 < (int)self->m_field32; t0++) {
        RouteEntry *entry = (RouteEntry *)((char *)self->m_field40 + t0 * 20);
        if (entry->m_type != 506) {
            continue;
        }

        int target_id = entry->m_target_id;
        if (target_id == 610) {
            if (self->m_field48 != 610 && self->m_field48 != 616) {
                continue;
            }
        }

        if (self->m_field44 != -1) {
            continue;
        }

        if (self->m_field48 != target_id) {
            continue;
        }

        func_0014BCE0(self);
        self->Method5C(1);
        self->m_field138 = a1;
        break;
    }

    if (self->m_field35 < self->m_field32) {
        func_00100630(self->m_field40);
        self->m_field34 = self->m_field35;
        self->m_field40 = (RouteEntry *)func_00100730((int)self->m_field34 * 20);
    }

    for (int i = 0; i < (int)self->m_field34; i++) {
        *(short *)((char *)self->m_field40 + i * 20) = -1;
    }

    self->m_field32 = 0;
}

TargetObj* func_001510D0(TradeAction *self, int a1) {
    if (!self->m_target) {
        return 0;
    }

    void *game = self->m_target->m_game;
    if (!game) {
        return 0;
    }

    void *timer = *(void **)((char *)game + 0xB98);
    if (!timer) {
        return 0;
    }

    return (TargetObj *)func_332e60(timer, a1);
}

int func_00151120(TradeAction *self) {
    short s = self->m_field48;
    if (s == 617 || s == 600 || s == 610 || s == 613 || s == 609 || s == 620 || s == 619) {
        return 1;
    }
    return 0;
}

int func_001511A0(TradeAction *self) {
    short s = self->m_field44;
    if (s == 617 || s == 700 || s == 710 || s == 713 || s == 709 || s == 720 || s == 719) {
        return 1;
    }
    return 0;
}

int func_00151220(TradeAction *self) {
    return *(void **)((char *)self + 0x164) != 0 ? 1 : 0;
}

int func_00151230(TradeAction *self) {
    void *obj = *(void **)((char *)self + 0x164);
    if (obj) {
        func_001FC810(obj);
    }

    TargetObj *target = self->m_target;
    void *res = target->Method1F4((char *)self + 0x168);
    *(void **)((char *)self + 0x164) = res;
    if (res) {
        return 1;
    }
    return 0;
}

int func_00151290() {
    return 0;
}

}
