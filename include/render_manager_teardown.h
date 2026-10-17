#ifndef RENDER_MANAGER_TEARDOWN_H
#define RENDER_MANAGER_TEARDOWN_H

struct SubObj404 {
    char pad_00[0x40];
    short count;
    char pad_42[2];
    void **items;
};

struct RenderManagerTeardown {
    void *vtable;
    char pad_04[4];
    int field_08[5];
    char pad_1C[0x6C];
    void *field_88;
    short field_8C;
    char pad_8E[2];
    void **field_90;
    char pad_94[0x370];
    SubObj404 *field_404;
};

extern void *D_004E8944;
extern void *D_004E894C;

extern "C" {
void func_00A80BB0();
void func_189210(void *arg);
void func_1F33D0(void *arg);
void func_25F6C0(void *item, int zero);
void func_25F860(void *item, int one);
void func_116F68(void *ptr);
void func_25F810(void *item, int one);

void func_00185a80(RenderManagerTeardown *self);
}

#endif
