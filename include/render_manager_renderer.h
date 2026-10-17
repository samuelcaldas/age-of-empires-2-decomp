#ifndef RENDER_MANAGER_RENDERER_H
#define RENDER_MANAGER_RENDERER_H

struct EngineSubCtx {
    char pad_00[0x0C];
    void *f0c;
    char pad_10[0x94];
    int fa4;
    int fa8;
};

struct ScreenDesc {
    char pad_00[0x0C];
    void *f0c;
};

struct RenderManagerInit {
    void *vtable;
    char pad_04[0x24];
    EngineSubCtx *ctx_28;
    int field_2C;
    char pad_30[8];
    int field_38;
    char pad_3C[0x30];
    ScreenDesc *field_6C;
    void *field_70;
};

extern ScreenDesc D_00598930;
extern "C" {
void func_00A80BB0();
void func_1F3320(void *arg);
void func_1AAB80(ScreenDesc *desc);
void func_1AACC0(ScreenDesc *desc, void *f0c, int f2c, int f38, char c1, char c2, int t2, int t3, long long stack_arg);
void func_1ABD90(void *f70, int zero, int ff);
void func_1AB1C0(ScreenDesc *desc, int zero);
void func_1F3340(void *arg);

int func_001854b0(RenderManagerInit *self);
int func_00185560(void *self);
}

#endif
