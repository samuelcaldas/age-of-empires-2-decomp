#ifndef RENDER_MANAGER_SCREEN_MODE_H
#define RENDER_MANAGER_SCREEN_MODE_H

struct SubObj404Item {};

struct SubObj404 {
    char pad_00[0x50];
    short count_50;
    char pad_52[2];
    SubObj404Item **items_54;
};

struct SubObj28 {
    char pad_00[0xAC];
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
};

struct RenderManagerScreenMode {
    virtual void M00() = 0, M01() = 0, M02() = 0, M03() = 0, M04() = 0;
    virtual void M05() = 0, M06() = 0, M07() = 0, M08() = 0, M09() = 0;
    virtual void M10() = 0, M11() = 0, M12() = 0, M13() = 0, M14() = 0;
    virtual void M15() = 0, M16() = 0, M17() = 0, M18() = 0, M19() = 0;
    virtual void Method58(int w, int h) = 0;

    char pad_04[0x24];
    SubObj28 *field_28;
    char pad_2C[0x34];
    int field_60;
    char pad_64[0x18C];
    int field_1F0;
    char pad_1F4[0x210];
    SubObj404 *field_404;
};

extern "C" {
void func_203ED0(void *item, int *out_x, int *out_y, int *out_z);
void func_1F33C0(void *arg);
void func_1F33B0(void *arg);
void func_00A80BB0();

int func_00188590(RenderManagerScreenMode *self, int *out_x, int *out_y, int *out_z);
void func_00188680(RenderManagerScreenMode *self);
void func_001886b0(RenderManagerScreenMode *self);
void func_001886f0(RenderManagerScreenMode *self);
void func_00188720(RenderManagerScreenMode *self);
}

#endif // RENDER_MANAGER_SCREEN_MODE_H
