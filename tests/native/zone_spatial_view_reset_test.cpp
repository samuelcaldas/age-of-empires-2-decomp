#include <cassert>
#include <cstring>
#include <new>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int g_method74_called = 0;
static int g_func_1fcd90_called = 0;
static void *g_func_1fcd90_arg = nullptr;

extern "C" {
void func_1FCD90(void *ptr) {
    g_func_1fcd90_called++;
    g_func_1fcd90_arg = ptr;
}
}

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
    virtual void Method74() {
        g_method74_called++;
    }

    char pad[0xA8 - 4];
    void *field_A8;

    SpatialViewObj() {
        std::memset(pad, 0, sizeof(pad));
        field_A8 = nullptr;
    }
};

extern "C" {
void func_001D90C0(SpatialViewObj *self);
}

static void test_reset_with_null() {
    SpatialViewObj obj;
    obj.field_A8 = nullptr;

    g_method74_called = 0;
    g_func_1fcd90_called = 0;
    g_func_1fcd90_arg = nullptr;

    func_001D90C0(&obj);

    assert(g_method74_called == 1);
    assert(g_func_1fcd90_called == 0);
}

static void test_reset_with_non_null() {
    SpatialViewObj obj;
    int dummy = 123;
    obj.field_A8 = &dummy;

    g_method74_called = 0;
    g_func_1fcd90_called = 0;
    g_func_1fcd90_arg = nullptr;

    func_001D90C0(&obj);

    assert(g_method74_called == 1);
    assert(g_func_1fcd90_called == 1);
    assert(g_func_1fcd90_arg == &dummy);
}

int main(int argc, char **argv) {
    test_reset_with_null();
    test_reset_with_non_null();
    return 0;
}
