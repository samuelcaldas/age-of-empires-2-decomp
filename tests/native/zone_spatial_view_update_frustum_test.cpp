#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SubObj {
    char pad[0x8];
    void *field_8;
    int field_C;
    char pad1[0x18 - 0x10];
    int field_18;
    float field_1C;
};

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

    char pad[0xA8 - 4];
    SubObj *sub;
    char pad1[0xB0 - 0xAC];
    float field_B0;

    SpatialViewObj() {
        std::memset(pad, 0, sizeof(pad));
        sub = nullptr;
        std::memset(pad1, 0, sizeof(pad1));
        field_B0 = 0.0f;
    }
};

extern "C" {
int func_001D9430(SpatialViewObj *self, void *a1, void *a2);
}

static void test_update_frustum_null() {
    SpatialViewObj view;
    view.sub = nullptr;
    assert(func_001D9430(&view, nullptr, nullptr) == 0);
}

static void test_update_frustum_non_null() {
    SpatialViewObj view;
    SubObj sub;
    std::memset(&sub, 0, sizeof(sub));
    sub.field_1C = 10.0f;
    view.sub = &sub;

    assert(func_001D9430(&view, nullptr, nullptr) == 1);
}

int main(int argc, char **argv) {
    test_update_frustum_null();
    test_update_frustum_non_null();
    return 0;
}
