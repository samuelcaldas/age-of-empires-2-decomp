#include <cassert>
#include <cmath>
#include <cstring>
#include "zone_spatial_view_set_orient.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_3151E0(float *cross, const float *v2, const float *v1) {
    cross[0] = v2[1] * v1[2] - v2[2] * v1[1];
    cross[1] = v2[2] * v1[0] - v2[0] * v1[2];
    cross[2] = v2[0] * v1[1] - v2[1] * v1[0];
}
}

static void test_set_orient_perpendicular() {
    char obj[0x60];
    std::memset(obj, 0, sizeof(obj));

    Vec3f v1 = { 1.0f, 0.0f, 0.0f };
    Vec3f v2 = { 0.0f, 1.0f, 0.0f };

    int res = func_001D8CA0(obj, &v1, &v2, 1);
    assert(res == 1);

    float *f = (float *)obj;
    assert(f[0x40 / 4] == 1.0f);
    assert(f[0x44 / 4] == 0.0f);
    assert(f[0x48 / 4] == 0.0f);

    assert(f[0x10 / 4] == 1.0f);
    assert(f[0x14 / 4] == 0.0f);
    assert(f[0x18 / 4] == 0.0f);

    assert(f[0x4C / 4] == 0.0f);
    assert(f[0x50 / 4] == 1.0f);
    assert(f[0x54 / 4] == 0.0f);
}

static void test_set_orient_not_orthogonal() {
    char obj[0x60];
    std::memset(obj, 0, sizeof(obj));

    Vec3f v1 = { 1.0f, 0.0f, 0.0f };
    Vec3f v2 = { 1.0f, 0.0f, 0.0f };

    int res = func_001D8CA0(obj, &v1, &v2, 1);
    assert(res == 0);
}

int main(int argc, char **argv) {
    test_set_orient_perpendicular();
    test_set_orient_not_orthogonal();
    return 0;
}
