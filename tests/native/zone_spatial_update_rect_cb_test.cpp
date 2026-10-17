#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D7E70(void *self, int x0, int y0, int x1, int y1);

static int g_update_rect_calls = 0;
static void *g_last_self = nullptr;
static int g_last_x0 = 0;
static int g_last_y0 = 0;
static int g_last_x1 = 0;
static int g_last_y1 = 0;

void func_1D7DD0(void *self, int x0, int y0, int x1, int y1) {
    g_update_rect_calls++;
    g_last_self = self;
    g_last_x0 = x0;
    g_last_y0 = y0;
    g_last_x1 = x1;
    g_last_y1 = y1;
}
}

static void test_update_rect_cb_null() {
    g_update_rect_calls = 0;
    func_001D7E70(nullptr, 1, 2, 3, 4);
    assert(g_update_rect_calls == 0);
}

static void test_update_rect_cb_valid() {
    g_update_rect_calls = 0;
    void *dummy = reinterpret_cast<void *>(0x12345678);
    func_001D7E70(dummy, 10, 20, 30, 40);
    assert(g_update_rect_calls == 1);
    assert(g_last_self == dummy);
    assert(g_last_x0 == 10);
    assert(g_last_y0 == 20);
    assert(g_last_x1 == 30);
    assert(g_last_y1 == 40);
}

int main(int argc, char **argv) {
    test_update_rect_cb_null();
    test_update_rect_cb_valid();
    return 0;
}
