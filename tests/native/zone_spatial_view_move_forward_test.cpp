#include <cassert>
#include <cmath>
#include "zone_spatial_view_move_forward.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

float D_004E2824 = 1.0e-7f;

extern "C" float __s_abs(float x) {
    return std::fabs(x);
}

extern "C" void func_314FE0(void *out, const void *in, float scale) {
    float *o = (float *)out;
    const float *i = (const float *)in;
    o[0] = i[0] * scale;
    o[1] = i[1] * scale;
    o[2] = i[2] * scale;
}

struct Vector3 {
    float x;
    float y;
    float z;
};

static int s_method90_called = 0;
static int s_method90_p1 = -1;
static int s_method90_p2 = -1;

class MockSpatialViewObj {
public:
    virtual void m0() {}
    virtual void m1() {} virtual void m2() {} virtual void m3() {} virtual void m4() {}
    virtual void m5() {} virtual void m6() {} virtual void m7() {} virtual void m8() {}
    virtual void m9() {} virtual void m10() {} virtual void m11() {} virtual void m12() {}
    virtual void m13() {} virtual void m14() {} virtual void m15() {} virtual void m16() {}
    virtual void m17() {} virtual void m18() {} virtual void m19() {} virtual void m20() {}
    virtual void m21() {} virtual void m22() {} virtual void m23() {} virtual void m24() {}
    virtual void m25() {} virtual void m26() {} virtual void m27() {} virtual void m28() {}
    virtual void m29() {} virtual void m30() {} virtual void m31() {} virtual void m32() {}
    virtual void m33() {}
    virtual void Method90(int p1, int p2) {
        s_method90_called++;
        s_method90_p1 = p1;
        s_method90_p2 = p2;
    }

    char pad_vtable_to_pos[0x34 - 4];
    Vector3 pos;
    Vector3 basis[3];

    MockSpatialViewObj() {
        for (int i = 0; i < (0x34 - 4); i++) pad_vtable_to_pos[i] = 0;
        pos.x = 10.0f; pos.y = 20.0f; pos.z = 30.0f;
        basis[0].x = 1.0f; basis[0].y = 0.0f; basis[0].z = 0.0f;
        basis[1].x = 0.0f; basis[1].y = 1.0f; basis[1].z = 0.0f;
        basis[2].x = 0.0f; basis[2].y = 0.0f; basis[2].z = 1.0f;
    }
};

static void test_move_forward_small() {
    MockSpatialViewObj obj;
    s_method90_called = 0;
    func_001DAF50((SpatialViewObj *)&obj, 1.0e-8f);
    assert(s_method90_called == 0);
    assert(obj.pos.z == 30.0f);
}

static void test_move_forward_normal() {
    MockSpatialViewObj obj;
    s_method90_called = 0;
    func_001DAF50((SpatialViewObj *)&obj, 12.0f);
    assert(s_method90_called == 1);
    assert(s_method90_p1 == 0);
    assert(s_method90_p2 == 1);
    assert(obj.pos.x == 10.0f);
    assert(obj.pos.y == 20.0f);
    assert(obj.pos.z == 42.0f);
}

int main(int argc, char **argv) {
    test_move_forward_small();
    test_move_forward_normal();
    return 0;
}
