#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SubObj {
    char pad0[4];
    SubObj *next;
    char pad1[0x10 - 8];
    int field_10;
    char pad2[0x25 - 0x14];
    char field_25;
    char field_26;
    char field_27;
};

struct SpatialViewObj {
    char pad[0xA8];
    SubObj *sub;
};

static int g_func_1fc610_calls = 0;
static int g_func_1fcd90_calls = 0;

extern "C" {
void func_1FC610(void *ptr) {
    g_func_1fc610_calls++;
}

void func_1FCD90(void *ptr) {
    g_func_1fcd90_calls++;
}

void func_001D9110(SpatialViewObj *self);
}

static void test_clear_sub_null() {
    SpatialViewObj view;
    std::memset(&view, 0, sizeof(view));
    view.sub = nullptr;

    g_func_1fc610_calls = 0;
    g_func_1fcd90_calls = 0;

    func_001D9110(&view);

    assert(g_func_1fc610_calls == 0);
    assert(g_func_1fcd90_calls == 0);
}

static void test_clear_sub_chain() {
    SpatialViewObj view;
    SubObj n1, n2;
    std::memset(&view, 0, sizeof(view));
    std::memset(&n1, 0, sizeof(n1));
    std::memset(&n2, 0, sizeof(n2));

    view.sub = &n1;
    n1.next = &n2;
    n2.next = nullptr;
    n2.field_25 = 2;

    g_func_1fc610_calls = 0;
    g_func_1fcd90_calls = 0;

    func_001D9110(&view);

    assert(g_func_1fc610_calls == 1);
    assert(view.sub == &n2);
    assert(n2.field_10 == 1);
    assert(n2.field_26 == 2);
    assert(n2.field_27 == 10);
}

int main(int argc, char **argv) {
    test_clear_sub_null();
    test_clear_sub_chain();
    return 0;
}
