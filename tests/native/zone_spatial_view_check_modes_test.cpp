#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int g_method90_calls = 0;
static int g_method90_p1 = -1;
static int g_method90_p2 = -1;
static int g_method8c_ret = 0;

class SpatialViewObj {
public:
    virtual void m0() {}
    virtual void m1() {}
    virtual void m2() {}
    virtual void m3() {}
    virtual void m4() {}
    virtual void m5() {}
    virtual void m6() {}
    virtual void m7() {}
    virtual void m8() {}
    virtual void m9() {}
    virtual void Method30(float f) {}
    virtual void m11() {}
    virtual void m12() {}
    virtual void m13() {}
    virtual void m14() {}
    virtual void m15() {}
    virtual void m16() {}
    virtual void m17() {}
    virtual void m18() {}
    virtual void Method54(float f) {}
    virtual void m20() {}
    virtual void m21() {}
    virtual void m22() {}
    virtual void m23() {}
    virtual void m24() {}
    virtual void m25() {}
    virtual void m26() {}
    virtual void Method74() {}
    virtual void m28() {}
    virtual void m29() {}
    virtual void m30() {}
    virtual void m31() {}
    virtual void m32() {}
    virtual int Method8C(int flag) {
        return g_method8c_ret;
    }
    virtual void Method90(int p1, int p2) {
        g_method90_calls++;
        g_method90_p1 = p1;
        g_method90_p2 = p2;
    }
};

extern "C" {
void func_001D93C0(SpatialViewObj *self);
}

static void test_check_modes_ret1() {
    SpatialViewObj view;
    g_method90_calls = 0;
    g_method8c_ret = 1;

    func_001D93C0(&view);

    assert(g_method90_calls == 2);
    assert(g_method90_p1 == 1);
    assert(g_method90_p2 == 0);
}

static void test_check_modes_ret0() {
    SpatialViewObj view;
    g_method90_calls = 0;
    g_method8c_ret = 0;

    func_001D93C0(&view);

    assert(g_method90_calls == 1);
    assert(g_method90_p1 == 0);
    assert(g_method90_p2 == 0);
}

int main(int argc, char **argv) {
    test_check_modes_ret1();
    test_check_modes_ret0();
    return 0;
}
