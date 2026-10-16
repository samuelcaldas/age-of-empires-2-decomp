#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00332da0(int id);
int func_00188070(void *ctx, int id);
int func_00123350(float val);
int func_002a0b30(void *mgr, int id);
int func_0029df60(void *mgr, int id);

void apply_trade_limits(int index, int *slot) {
    if (!slot) return;
    int val = *slot;
    if ((index >= 0x75 && index <= 0x78) || (index >= 0x9C && index <= 0x9F)) {
        if (val < 0) val = 0;
        if (val > 100) val = 100;
    } else if (index == 0x14) {
        if (val > 50) val = 50;
    } else if (index == 0xE6) {
        if (val > 30) val = 30;
    } else if (index == 0xCC) {
        if (val > 8) val = 8;
    } else if (index == 0x2B || index == 0x2C) {
        if (val > 0) val = 1;
    }
    *slot = val;
}

void func_002B6220(void *self, int index, int value) {
    if (!self) {
        return;
    }
    char *base = static_cast<char *>(self);
    if (index < 0 || index >= 239) {
        return;
    }

    int *table_slot = reinterpret_cast<int *>(base + 0x858 + index * 4);
    *table_slot = value;

    // Limits executed on ALL paths (including value <= 0 and BEC == 1)
    apply_trade_limits(index, table_slot);

    if (value <= 0) {
        return;
    }

    int field_bec = *reinterpret_cast<int *>(base + 0x0BEC);
    if (field_bec == 1) {
        return;
    }

    void *mgr = nullptr;
    void *p1 = *reinterpret_cast<void **>(base + 0xB0);
    if (p1) {
        void *p2 = *reinterpret_cast<void **>(static_cast<char *>(p1) + 0xAC);
        if (p2) {
            mgr = *reinterpret_cast<void **>(static_cast<char *>(p2) + 0xB98);
        }
    }

    if (mgr) {
        void *target = func_00332da0(0);
        if (target) {
            int mode_flag = func_00188070(mgr, 0x10);
            if (index == 0x68) {
                int inc = (mode_flag == 1) ? 600 : 240;
                *table_slot += inc;
                apply_trade_limits(index, table_slot);
            }
        }
    }

    func_00123350(1.0f);
    if (p1) {
        func_002a0b30(static_cast<char *>(p1) + 0x3624, 0x14);
        func_0029df60(static_cast<char *>(p1) + 0x3624, 0x1E);
    }
}
}
