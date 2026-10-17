#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D7B20(void *self);

static int g_func_1d1fb0_calls = 0;
static int g_func_100630_calls = 0;

void *func_1D1FB0(void *pyramid, int flag) {
    g_func_1d1fb0_calls++;
    assert(flag == 1);
    return pyramid;
}

void func_100630(void *ptr) {
    g_func_100630_calls++;
}

void func_1EE700(void *mgr, void *code, int flag) {
}
}

static void test_node_cleanup_flow() {
    g_func_1d1fb0_calls = 0;
    g_func_100630_calls = 0;

    char node[0x20];
    std::memset(node, 0, sizeof(node));

    void *items[2] = { reinterpret_cast<void *>(0x10), reinterpret_cast<void *>(0x20) };
    *reinterpret_cast<void ***>(node + 0) = items;
    *reinterpret_cast<int *>(node + 4) = 2; // 2 items

    func_001D7B20(node);

    assert(g_func_1d1fb0_calls == 2);
    assert(g_func_100630_calls == 1);
    assert(*reinterpret_cast<void **>(node + 0) == nullptr);
    assert(*reinterpret_cast<int *>(node + 4) == 0);
}

int main(int argc, char **argv) {
    test_node_cleanup_flow();
    return 0;
}
