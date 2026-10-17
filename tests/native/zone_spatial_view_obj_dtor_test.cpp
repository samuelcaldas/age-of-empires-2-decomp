#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialViewObj {
    void *vtable;
    char pad[0xA8 - 4];
    void *field_A8;
};

void *__vt__004D9610[50];

extern "C" {
void *func_001D8C30(SpatialViewObj *self, int flag);

static int g_func_1fc610_calls = 0;
static int g_func_100670_calls = 0;

void func_1FC610(void *ptr) {
    g_func_1fc610_calls++;
    assert(ptr == reinterpret_cast<void *>(0x5555));
}

void func_100670(void *ptr) {
    g_func_100670_calls++;
}
}

static void test_view_obj_dtor_null() {
    g_func_1fc610_calls = 0;
    g_func_100670_calls = 0;

    assert(func_001D8C30(nullptr, 0) == nullptr);
    assert(g_func_1fc610_calls == 0);
    assert(g_func_100670_calls == 0);
}

static void test_view_obj_dtor_with_delete() {
    g_func_1fc610_calls = 0;
    g_func_100670_calls = 0;

    SpatialViewObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_A8 = reinterpret_cast<void *>(0x5555);

    void *res = func_001D8C30(&obj, 1);
    assert(res == &obj);
    assert(obj.vtable == __vt__004D9610);
    assert(obj.field_A8 == nullptr);
    assert(g_func_1fc610_calls == 1);
    assert(g_func_100670_calls == 1);
}

static void test_view_obj_dtor_without_delete() {
    g_func_1fc610_calls = 0;
    g_func_100670_calls = 0;

    SpatialViewObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.field_A8 = reinterpret_cast<void *>(0x5555);

    void *res = func_001D8C30(&obj, 0);
    assert(res == &obj);
    assert(obj.vtable == __vt__004D9610);
    assert(obj.field_A8 == nullptr);
    assert(g_func_1fc610_calls == 1);
    assert(g_func_100670_calls == 0);
}

int main(int argc, char **argv) {
    test_view_obj_dtor_null();
    test_view_obj_dtor_with_delete();
    test_view_obj_dtor_without_delete();
    return 0;
}
