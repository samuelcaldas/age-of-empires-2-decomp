#pragma exceptions off

#include "render_manager_renderer.h"

extern "C" {
int func_001854b0(RenderManagerInit *self) {
    func_1F3320((void *)func_00A80BB0);
    self->field_6C = &D_00598930;
    func_1AAB80(self->field_6C);

    EngineSubCtx *ctx = self->ctx_28;
    func_1AACC0(self->field_6C, ctx->f0c, self->field_2C, self->field_38, 2, 2, ctx->fa4, ctx->fa8, 0);

    self->field_70 = self->field_6C->f0c;
    func_1ABD90(self->field_70, 0, 0xFF);
    func_1AB1C0(self->field_6C, 0);
    func_1F3340((void *)func_00A80BB0);
    return 1;
}

int func_00185560(void *self) {
    (void)self;
    return 1;
}
}
