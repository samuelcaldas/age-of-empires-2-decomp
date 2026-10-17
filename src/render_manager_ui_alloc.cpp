#pragma exceptions off

#include "render_manager_ui_alloc.h"

extern "C" {
int func_00185660(RenderManagerUiAlloc *self) {
    void *obj;
    if ((obj = func_100850(0x47C0)) != 0) {
        EngineCtx47C0 *ctx = self->ctx_28;
        func_18A010(obj, self->field_2C, ctx->f38, D_004E8944, ctx->fbc);
    }
    self->field_1AC = obj;
    func_189F20(self->field_1AC, self->field_1044);
    if (self->field_1AC == 0) {
        return 0;
    }

    func_189E00(self->field_1AC, self->field_1B0);
    func_189E40(self->field_1AC, self->field_1B8);
    func_189E60(self->field_1AC, self->field_1BC);
    func_189E70(self->field_1AC, self->field_1C0);
    func_189E50(self->field_1AC, self->field_1B4);

    void *v = self->field_1AC;
    D_004E8948 = v;
    if (self->field_404 != 0) {
        func_32FBC0(self->field_404, self->field_1AC);
    }

    if (D_004E8984 != 0) {
        func_192CD0(self->field_1AC, D_004E8984);
    }

    int res = 1;
    if (D_004E8988 != 0) {
        func_192CD0(self->field_1AC, D_004E8988);
        res = 1;
    }

    return res;
}

void func_00185760(RenderManagerUiAlloc *self) {
    if (self->field_1AC != 0) {
        func_18A570(self->field_1AC, 1);
        self->field_1AC = 0;
        D_004E8948 = 0;
    }
    self->slot_88();
}
}
