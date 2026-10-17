#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D4330(
    void *self, int x, int y, int level, float g_score, float h_score,
    void *parent, int dir, void *t2, void *t3
);

static char g_dummy_alloc[0x2C];
static int g_func_100850_calls = 0;

void *func_100850(int size) {
    g_func_100850_calls++;
    assert(size == 0x2C);
    return g_dummy_alloc;
}
}

static void test_alloc_node_from_heap() {
    g_func_100850_calls = 0;
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 0, 0, 0, 0 };
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;
    *reinterpret_cast<void **>(zm + 0x80) = nullptr;

    void *node = func_001D4330(zm, 0, 0, 0, 5.0f, 10.0f, nullptr, 1, nullptr, nullptr);
    assert(g_func_100850_calls == 1);
    assert(node == g_dummy_alloc);
    assert(*reinterpret_cast<float *>(reinterpret_cast<char *>(node) + 0x1C) == 5.0f);
    assert(*reinterpret_cast<float *>(reinterpret_cast<char *>(node) + 0x18) == 15.0f);
}

static void test_alloc_node_from_free_list() {
    g_func_100850_calls = 0;
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 0, 0, 0, 0 };
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    char free_node[0x2C];
    std::memset(free_node, 0, sizeof(free_node));
    *reinterpret_cast<void **>(zm + 0x80) = free_node;

    void *node = func_001D4330(zm, 0, 0, 0, 2.0f, 3.0f, nullptr, 0, nullptr, nullptr);
    assert(g_func_100850_calls == 0); // taken from free list!
    assert(node == free_node);
}

int main(int argc, char **argv) {
    test_alloc_node_from_heap();
    test_alloc_node_from_free_list();
    return 0;
}
