#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D7AC0(void *self, int flag);

static int g_func_1d7b20_calls = 0;
static int g_func_100670_calls = 0;

void func_1D7B20(void *self) {
    g_func_1d7b20_calls++;
}

void func_100670(void *ptr) {
    g_func_100670_calls++;
}
}

static void test_node_dtor_null() {
    g_func_1d7b20_calls = 0;
    g_func_100670_calls = 0;
    assert(func_001D7AC0(nullptr, 0) == nullptr);
    assert(g_func_1d7b20_calls == 0);
    assert(g_func_100670_calls == 0);
}

static void test_node_dtor_with_delete() {
    g_func_1d7b20_calls = 0;
    g_func_100670_calls = 0;
    char node[0x20];
    void *res = func_001D7AC0(node, 1);
    assert(res == node);
    assert(g_func_1d7b20_calls == 1);
    assert(g_func_100670_calls == 1);
}

int main(int argc, char **argv) {
    test_node_dtor_null();
    test_node_dtor_with_delete();
    return 0;
}
