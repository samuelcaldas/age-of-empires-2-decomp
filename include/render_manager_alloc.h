#ifndef RENDER_MANAGER_ALLOC_H
#define RENDER_MANAGER_ALLOC_H

struct RenderManagerAlloc {
    void *vtable;
    char pad_04[0x24];
    char *ctx_28;
    int field_2C;
    char pad_30[0x40];
    void *field_70;
    char pad_74[8];
    void *field_7C;
    char pad_80[0x158];
    void *field_1D8;
};

extern void *D_004E8944;

extern "C" {
void *func_100850(int size);
void func_1DB460(void *obj, int zero);
int func_1DB500(void *obj, void *f7c, void *f70, void *ctx_arg, int argc738, int arg13);
void func_1860D0(RenderManagerAlloc *self);
void func_188DF0(void *obj, int field_2C);

int func_00185570(RenderManagerAlloc *self);
int func_00185610(RenderManagerAlloc *self);
}

#endif
