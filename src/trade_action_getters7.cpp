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

float get_scaling_factor(int index, int mode, int flag) {
    if (mode == 0 || mode == 5 || flag != 1) {
        return 1.0f;
    }
    if (mode == 1 && flag != 1) {
        return 1.0f;
    }
    bool is_f20 = (index == 0x24 || index == 0x3A);
    bool is_f21 = (index == 0x10 || index == 0x1A || index == 0x3B || index == 0x3C);
    bool is_f22 = (index == 0x13 || index == 0x14);
    bool is_f23 = (index == 0xE3 || index == 0xE4);

    if (is_f20 || is_f22) {
        if (mode == 1) return 0.8f;
        if (mode == 2) return 0.6f;
        if (mode == 3) return 0.4f;
        if (mode == 4) return 0.2f;
    } else if (is_f21) {
        if (mode == 1) return 0.8f;
        if (mode == 2) return 0.75f;
        if (mode == 3) return 0.5f;
        if (mode == 4) return 0.25f;
    } else if (is_f23) {
        if (mode == 1) return 1.0f;
        if (mode == 2) return 0.75f;
        if (mode == 3) return 0.5f;
        if (mode == 4) return 0.25f;
    }
    return 1.0f;
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

bool is_setup_allowed_id(int index) {
    return index == 0x10 || index == 0x13 || index == 0x14 || index == 0x1A ||
           index == 0x24 || (index >= 0x3A && index <= 0x3C) || index == 0x68 ||
           index == 0xE3 || index == 0xE4;
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

    int field_bec = *reinterpret_cast<int *>(base + 0x0BEC);
    bool skip_setup = (value <= 0 || field_bec == 1 || !is_setup_allowed_id(index));

    int mode = 0;
    int flag = 0;
    char *p1 = *reinterpret_cast<char **>(base + 0xB0);

    if (!skip_setup) {
        char *p2 = *reinterpret_cast<char **>(p1 + 0xAC);
        void *ptr = *reinterpret_cast<void **>(p2 + 0xB98);
        mode = func_00332da0(ptr);
        if (mode >= 1 && mode <= 4) {
            flag = func_00188070(D_004E3180);
            if (index == 0x68) {
                int inc = select_trade_increment(mode, flag);
                *table_slot += inc;
            }
        }
    }

    if (!skip_setup && index != 0x68 && is_setup_allowed_id(index)) {
        float factor = get_scaling_factor(index, mode, flag);
        int scaled = func_00123350(factor * static_cast<float>(*table_slot));
        if (scaled == 0 && *table_slot != 0) {
            scaled = 1;
        }
        *table_slot = scaled;
    }

    if (p1) {
        char *mgr_target = p1 + 0x3624;
        if (index == 0x56 || index == 0x57) {
            func_002a0b30(mgr_target, index);
        } else if (index == 0x69) {
            func_0029df60(mgr_target, value);
        }
    }

    apply_trade_limits(index, table_slot);
}
}
