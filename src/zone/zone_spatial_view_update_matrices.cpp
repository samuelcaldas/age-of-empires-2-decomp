#pragma exceptions off

#include "zone_spatial_view_update_matrices.h"

extern "C" {
void func_1D9430(void *self);
float func_333EB0(void *obj);
float func_1DAE20(void *self, void *field_4, float f12, float f13, float f14);
void func_1DAE30(void *self, float f12);
void func_1DAF50(void *self, float f12);
void func_1DAEC0(void *self, float f12);
extern void *D_004E3180;
}

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

struct Matrix3x4 {
    float m[12];
};

struct SpatialViewObj {
    char pad0[4];
    Matrix3x4 matrix;
    Matrix3x4 matrix_34;
    float field_64;
    float field_68;
    float field_6C;
    char pad1[0x78 - 0x70];
    float field_78;
};

extern "C" int func_001D92F0(SpatialViewObj *self) {
    func_1D9430(self);

    GlobalContext *ctx = (GlobalContext *)D_004E3180;
    float scale0 = func_333EB0(ctx->field_404);
    self->field_6C = func_1DAE20(self, &self->matrix, self->field_6C, self->field_78, scale0);

    float scale1 = func_333EB0(ctx->field_404);
    func_1DAE30(self, self->field_6C * scale1);

    float scale2 = func_333EB0(ctx->field_404);
    func_1DAF50(self, self->field_64 * scale2);

    float scale3 = func_333EB0(ctx->field_404);
    func_1DAEC0(self, self->field_68 * scale3);

    self->matrix = self->matrix_34;

    return 1;
}
