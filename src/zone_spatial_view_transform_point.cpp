#pragma exceptions off

#include "zone_spatial_view_transform_point.h"

extern "C" {
float func_1DAE20(void *a0, void *a1, float f12, float f13, float f14);
void func_314FE0(void *dst, void *src, float f12);
void func_3150A0(void *dst, void *m, void *v);
}

struct SpatialViewObj {
    char pad[0x6C];
    float field_6C;
    char pad1[0x78 - 0x70];
    float field_78;
};

extern "C" void func_001DAAB0(void *a0, SpatialViewObj *view, void *a2, Vec3f *out, float scale) {
    float scaled = func_1DAE20(a0, a2, view->field_6C, view->field_78, scale);
    Vec3f sp60;
    func_314FE0(&sp60, a2, scaled * scale);
    Vec3f sp50;
    func_3150A0(&sp50, a0, &sp60);
    out->x = sp50.x;
    out->y = sp50.y;
    out->z = sp50.z;
}
