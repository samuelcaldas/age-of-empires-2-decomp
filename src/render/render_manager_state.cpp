#pragma exceptions off

#include "render_manager_state.h"

extern "C" {
void func_001842f0();
void func_2264A0(void (*fn)());
void func_00A80BB0();
void func_1F32D0(void *arg);

int func_001853e0(RenderManagerState *self) {
    (void)self;
    return 1;
}

int func_001853f0(RenderManagerState *self) {
    D_004E8624 = 1;
    EngineCtx *ctx = (EngineCtx *)self->ctx_28;
    if (ctx->field_5C == 1) {
        if (ctx->field_54 == 1) {
            self->field_7C = 1;
        }
    }
    return 1;
}

int func_00185430(RenderManagerState *self) {
    (void)self;
    func_2264A0(func_001842f0);
    return 1;
}

int func_00185460(RenderManagerState *self) {
    self->field_2C = 1;
    int v = self->field_2C;
    if (!v) {
        return 0;
    }
    D_004E8940 = v;
    func_1F32D0((void *)func_00A80BB0);
    return 1;
}
}
