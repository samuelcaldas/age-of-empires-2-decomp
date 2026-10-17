#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

class MockView;

static int g_method30_called = 0;
static float g_method30_val = -1.0f;
static int g_method54_called = 0;
static float g_method54_val = -1.0f;

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
    virtual void Method30(float f) {
        g_method30_called++;
        g_method30_val = f;
    }
    virtual void m11() {}
    virtual void m12() {}
    virtual void m13() {}
    virtual void m14() {}
    virtual void m15() {}
    virtual void m16() {}
    virtual void m17() {}
    virtual void m18() {}
    virtual void Method54(float f) {
        g_method54_called++;
        g_method54_val = f;
    }
};

extern "C" {
void func_001D9070(SpatialViewObj *self);
}

static void test_clear_rates() {
    SpatialViewObj obj;
    g_method30_called = 0;
    g_method30_val = -1.0f;
    g_method54_called = 0;
    g_method54_val = -1.0f;

    func_001D9070(&obj);

    assert(g_method30_called == 1);
    assert(g_method30_val == 0.0f);
    assert(g_method54_called == 1);
    assert(g_method54_val == 0.0f);
}

int main(int argc, char **argv) {
    test_clear_rates();
    return 0;
}
