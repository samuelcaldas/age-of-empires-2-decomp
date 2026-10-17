#include <cassert>
#include <cstring>
#include "zone_spatial_view_transform_point.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialViewObj {
    char pad[0x6C];
    float field_6C;
    char pad1[0x78 - 0x70];
    float field_78;
};

extern "C" {
float func_1DAE20(void *a0, void *a1, float f12, float f13, float f14) {
    return f12 + f13 + f14;
}

void func_314FE0(void *dst, void *src, float f12) {
    Vec3f *d = (Vec3f *)dst;
    d->x = f12;
    d->y = f12 * 2.0f;
    d->z = f12 * 3.0f;
}

void func_3150A0(void *dst, void *m, void *v) {
    Vec3f *d = (Vec3f *)dst;
    Vec3f *src = (Vec3f *)v;
    d->x = src->x + 10.0f;
    d->y = src->y + 20.0f;
    d->z = src->z + 30.0f;
}
}

static void test_transform_point() {
    SpatialViewObj view;
    std::memset(&view, 0, sizeof(view));
    view.field_6C = 1.0f;
    view.field_78 = 2.0f;

    Vec3f out;
    int a0 = 0, a2 = 0;
    func_001DAAB0(&a0, &view, &a2, &out, 1.0f);

    // scaled = 1 + 2 + 1 = 4. scaled * scale = 4.
    // sp60 = (4, 8, 12).
    // sp50 = (14, 28, 42).
    assert(out.x == 14.0f);
    assert(out.y == 28.0f);
    assert(out.z == 42.0f);
}

int main(int argc, char **argv) {
    test_transform_point();
    return 0;
}
