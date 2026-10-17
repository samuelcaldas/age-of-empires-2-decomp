#ifndef RENDER_MANAGER_STATE_H
#define RENDER_MANAGER_STATE_H

struct EngineCtx {
    char pad_00[0x54];
    int field_54;
    char pad_58[4];
    int field_5C;
};

struct RenderManagerState {
    void *vtable;
    char pad_04[0x24];
    void *ctx_28;
    volatile int field_2C;
    char pad_30[0x4C];
    int field_7C;
};

extern int D_004E8624;
extern int D_004E8940;

extern "C" {
int func_001853e0(RenderManagerState *self);
int func_001853f0(RenderManagerState *self);
int func_00185340(RenderManagerState *self);
int func_00185430(RenderManagerState *self);
int func_00185460(RenderManagerState *self);
}

#endif
