#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

class SpatialViewObj;

static int g_method20_calls = 0;
static int g_method90_calls = 0;

static void mock_method20(void *self, float *a1, float *a2, int a3) {
    g_method20_calls++;
    assert(a1[0] == 1.0f);
    assert(a2[1] == 1.0f);
    assert(a3 == 1);
}

static void mock_method90(void *self, int p1, int p2) {
    g_method90_calls++;
    assert(p1 == 1);
    assert(p2 == 1);
}

void *__vt__004D9610[50];
float D_004E2808 = 3.4028235e+38f;

struct RawSpatialViewObj {
    void *vtable;
    int fields[37];
    float f98;
    float f9C;
    int fA0;
    float fA4;
    int fA8;
    int fAC;
    int fB0;
    int fB4;
    int fB8;
};

extern "C" {
SpatialViewObj *func_001D8AF0(SpatialViewObj *self);
}

static void test_view_obj_ctor() {
    g_method20_calls = 0;
    g_method90_calls = 0;

    std::memset(__vt__004D9610, 0, sizeof(__vt__004D9610));
    // Index 6 (0x18 in Itanium/GCC) and Index 8 (0x20 in MWCC/PS2)
    __vt__004D9610[6] = reinterpret_cast<void *>(&mock_method20);
    __vt__004D9610[8] = reinterpret_cast<void *>(&mock_method20);
    // Index 34 (0x88 in Itanium/GCC) and Index 36 (0x90 in MWCC/PS2)
    __vt__004D9610[34] = reinterpret_cast<void *>(&mock_method90);
    __vt__004D9610[36] = reinterpret_cast<void *>(&mock_method90);

    RawSpatialViewObj obj;
    std::memset(obj.fields, 0xFF, sizeof(obj.fields));

    func_001D8AF0(reinterpret_cast<SpatialViewObj *>(&obj));

    assert(obj.vtable == __vt__004D9610);
    assert(obj.fields[0] == 0);
    assert(obj.fields[36] == 0);
    assert(obj.f98 == D_004E2808);
    assert(obj.f9C == D_004E2808);
    assert(obj.fA4 == D_004E2808);
    assert(obj.fA0 == 0);
    assert(obj.fA8 == 0);
    assert(obj.fB8 == 0);
    assert(g_method20_calls == 1);
    assert(g_method90_calls == 1);
}

int main(int argc, char **argv) {
    test_view_obj_ctor();
    return 0;
}
