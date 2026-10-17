#include <cassert>
#include <cmath>
#include <cstring>
#include "zone_spatial_view_project_xz.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_315110(void *dst, void *a1, void *a2, void *a3) {
    Vec3f *d = (Vec3f *)dst;
    d->x = 3.0f;
    d->y = 100.0f; // should be cleared to 0
    d->z = 4.0f;
}
}

static void test_project_xz() {
    Vec3f out;
    int a1 = 0, a2 = 0, a3 = 0;
    int res = func_001DAB50(&out, &a1, &a2, &a3);
    assert(res == 1);
    // x = 3, z = 4. len = sqrt(3^2 + 0^2 + 4^2) = 5.
    // normalized: x = 3/5 = 0.6, y = 0, z = 4/5 = 0.8
    assert(std::fabs(out.x - 0.6f) < 1e-4f);
    assert(out.y == 0.0f);
    assert(std::fabs(out.z - 0.8f) < 1e-4f);
}

int main(int argc, char **argv) {
    test_project_xz();
    return 0;
}
