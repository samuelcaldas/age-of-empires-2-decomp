#pragma once

struct TacticalItem_342820 {
    char name[16];      // 0x00 - 0x0F
    int field_10;       // 0x10
    int field_14;       // 0x14
    int field_18;       // 0x18
    char field_1C[7];   // 0x1C - 0x22
    char pad_23;        // 0x23
    int field_24;       // 0x24 - 0x27
};

extern "C" {
void func_11ABBC(void *dst, const char *src);
void func_00342820(TacticalItem_342820 *self);
extern const char D_004D5668[];
}
