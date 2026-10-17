#include <cassert>
#include <cstddef>
#include <cstring>
#include <cstdlib>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialNodeManager {
    void **items;
    int count;
    void *field_8;
};

extern "C" {
void func_001D7CE0(SpatialNodeManager *self, void *item, int flag);

void *D_004E3244 = reinterpret_cast<void *>(0x12345678);

static int g_func_1d7bf0_calls = 0;
static void *g_find_return = nullptr;
static int g_node_ctor_calls = 0;
static int g_notify_calls = 0;

void *func_1D7BF0(void *self, void *item, int flag) {
    g_func_1d7bf0_calls++;
    return g_find_return;
}

void *func_100850(unsigned int size) {
    assert(size == 0x124);
    return std::malloc(size);
}

void *func_117AF8(void *dst, const void *src, unsigned int size) {
    return std::memcpy(dst, src, size);
}

void *func_1D1D70(void *node, void *f8, void *item, int flag) {
    g_node_ctor_calls++;
    assert(f8 == reinterpret_cast<void *>(0x8888));
    assert(item == reinterpret_cast<void *>(0x7777));
    assert(flag == 123);
    return node;
}

void func_1EE700(void *mgr, void *callback, void *self) {
    g_notify_calls++;
    assert(mgr == D_004E3244);
}

void func_1D7E70(void *arg) {
}
}

static void test_find_or_create_item_already_exists() {
    g_func_1d7bf0_calls = 0;
    g_find_return = reinterpret_cast<void *>(0x9999);
    g_node_ctor_calls = 0;
    g_notify_calls = 0;

    SpatialNodeManager mgr;
    mgr.items = nullptr;
    mgr.count = 0;
    mgr.field_8 = nullptr;

    func_001D7CE0(&mgr, reinterpret_cast<void *>(0x7777), 123);
    assert(g_func_1d7bf0_calls == 1);
    assert(g_node_ctor_calls == 0);
    assert(g_notify_calls == 0);
    assert(mgr.count == 0);
}

static void test_find_or_create_item_creates_new() {
    g_func_1d7bf0_calls = 0;
    g_find_return = nullptr;
    g_node_ctor_calls = 0;
    g_notify_calls = 0;

    SpatialNodeManager mgr;
    mgr.items = nullptr;
    mgr.count = 0;
    mgr.field_8 = reinterpret_cast<void *>(0x8888);

    func_001D7CE0(&mgr, reinterpret_cast<void *>(0x7777), 123);
    assert(g_func_1d7bf0_calls == 1);
    assert(g_node_ctor_calls == 1);
    assert(g_notify_calls == 1);
    assert(mgr.count == 1);
    assert(mgr.items != nullptr);
    assert(mgr.items[0] != nullptr);

    std::free(mgr.items[0]);
    delete[] mgr.items;
}

int main(int argc, char **argv) {
    test_find_or_create_item_already_exists();
    test_find_or_create_item_creates_new();
    return 0;
}
