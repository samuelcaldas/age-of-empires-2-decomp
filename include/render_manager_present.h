#ifndef RENDER_MANAGER_PRESENT_H
#define RENDER_MANAGER_PRESENT_H

struct SubObj404B {
    char pad_00[0x40];
    short count;
    char pad_42[2];
    void **items;
};

struct RECT {
    int left, top, right, bottom;
};

struct RenderManagerPresent {
    void *vtable;
    char pad_04[0x28];
    int field_2C;
    int field_30;
    int field_34;
    char pad_38[0x34];
    void *field_6C;
    char pad_70[0x18];
    void *field_88;
    char pad_8C[0x378];
    SubObj404B *field_404;
};

extern void *D_004E8944;
extern "C" {
void func_00A80BB0();
void func_25F6C0(void *item, void *field_88);
void func_1F3440(void *arg);
void func_189220(void *d44, void *field_88);
void func_185CF0();
int func_225F80(int f2c, RECT *rect, int zero);
void func_1AB1C0(void *f6c, RECT *rect);

int func_00185bc0(RenderManagerPresent *self);
int func_00185c60(void *self);
int func_00185c70(RenderManagerPresent *self);
void func_00185cf0();
}

#endif
