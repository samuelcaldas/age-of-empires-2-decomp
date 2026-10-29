#include <cassert>
#include <cstring>
#include "zone_spatial_view_calc_deflection.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct Vec3f {
    float x, y, z;
};

struct SpatialViewObj {
    char pad[0x9C];
    float field_9C;
};

extern "C" {
float func_3154A0(void *v1, void *v2) {
    return 10.0f;
}

void func_3151E0(void *cross, void *v2, void *v1) {
    Vec3f *c = (Vec3f *)cross;
    c->x = 0.0f;
    c->y = 1.0f; // positive -> val stays positive
    c->z = 0.0f;
}
}

static void test_calc_deflection_flag1() {
    SpatialViewObj view;
    std::memset(&view, 0, sizeof(view));
    view.field_9C = 8.0f;

    int v1 = 0, v2 = 0;
    // val = 10, limit = 8 * 0.5 = 4. val > limit -> val = 4. cross.y > 0 -> return -4
    float res = func_001DAC10(&view, &v1, &v2, 1, 0.5f);
    assert(res == -4.0f);
}

static void test_calc_deflection_flag0() {
    SpatialViewObj view;
    std::memset(&view, 0, sizeof(view));
    view.field_9C = 12.0f;

    int v1 = 0, v2 = 0;
    // val = 10, limit = 12. val <= limit -> val = 10. cross.y > 0 -> return -10
    float res = func_001DAC10(&view, &v1, &v2, 0, 1.0f);
    assert(res == -10.0f);
}

int main(int argc, char **argv) {
    test_calc_deflection_flag1();
    test_calc_deflection_flag0();
    return 0;
}
