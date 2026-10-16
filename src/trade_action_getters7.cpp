#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_00332da0(void *ptr);
int func_00188070(void *ctx);
int func_00123350(float val);
int func_002a0b30(void *mgr, int id);
int func_0029df60(void *mgr, int id);
extern void *D_004E3180;

int select_trade_increment(int mode, int flag) {
    if (mode == 1) return 0;
    if (mode == 2) return (flag == 1) ? 600 : 240;
    if (mode == 3) return (flag == 1) ? 1200 : 900;
    if (mode == 4) return (flag == 1) ? 1800 : 1260;
    return 0;
}

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

    if (value <= 0) {
        apply_trade_limits(index, table_slot);
        return;
    }

    int field_bec = *reinterpret_cast<int *>(base + 0x0BEC);
    if (field_bec == 1) {
        apply_trade_limits(index, table_slot);
        return;
    }

    void *p1 = *reinterpret_cast<void **>(base + 0xB0);
    if (p1) {
        void *p2 = *reinterpret_cast<void **>(static_cast<char *>(p1) + 0xAC);
        if (p2) {
            void *ptr = *reinterpret_cast<void **>(static_cast<char *>(p2) + 0xB98);
            if (ptr) {
                int mode = func_00332da0(ptr);
                if (mode >= 1 && mode <= 4) {
                    int flag = func_00188070(D_004E3180);
                    if (index == 0x68) {
                        int inc = select_trade_increment(mode, flag);
                        *table_slot += inc;
                    }
                }
            }
        }
    }

    if (index == 0x68 || index == 0x14 || index == 0xE6) {
        float scale_factor = 1.0f;
        if (index == 0x68) scale_factor = 0.5f;
        else if (index == 0x14) scale_factor = 0.75f;
        else if (index == 0xE6) scale_factor = 0.25f;
        func_00123350(scale_factor * static_cast<float>(*table_slot));
    }

    if (p1 && (index == 0x56 || index == 0x57 || index == 0x69 || index == 0x68 || index == 0x75 || index == 0x14 || index == 0xCC)) {
        func_002a0b30(static_cast<char *>(p1) + 0x3624, 0x56);
        func_0029df60(static_cast<char *>(p1) + 0x3624, 0x57);
    }

    apply_trade_limits(index, table_slot);
}
}
