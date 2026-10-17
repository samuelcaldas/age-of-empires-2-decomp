#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D1560(void *self);

static int g_func_25de30_calls = 0;
static int g_func_117cac_calls = 0;
static void *g_last_freed_heap = nullptr;
static int g_last_freed_size = 0;

void func_25DE30(void *item, int flag) {
    g_func_25de30_calls++;
    assert(flag == 1);
}

void *func_117CAC(void *heap, int flag, int size) {
    g_func_117cac_calls++;
    assert(flag == 0);
    g_last_freed_heap = heap;
    g_last_freed_size = size;
    return nullptr;
}
}

static void reset_test_state() {
    g_func_25de30_calls = 0;
    g_func_117cac_calls = 0;
    g_last_freed_heap = nullptr;
    g_last_freed_size = 0;
}

static void test_cleanup_null_buffer() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<void **>(zm + 0x903C) = nullptr;

    func_001D1560(zm);

    assert(g_func_25de30_calls == 0);
    assert(g_func_117cac_calls == 0);
}

static void test_cleanup_render_items_flow() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char dummy_heap[1024];
    *reinterpret_cast<void **>(zm + 0x903C) = dummy_heap;
    *reinterpret_cast<int *>(zm + 0x9040) = 50; // total words -> 400 bytes
    *reinterpret_cast<int *>(zm + 0x9044) = 2;  // item count

    // Set up 2 items in items_buf
    char entry1[32];
    char entry2[32];
    std::memset(entry1, 0, sizeof(entry1));
    std::memset(entry2, 0, sizeof(entry2));

    char dummy_sub_item1[16];
    char dummy_sub_item2[16];
    *reinterpret_cast<void **>(entry1 + 0x10) = dummy_sub_item1;
    *reinterpret_cast<void **>(entry2 + 0x10) = dummy_sub_item2;

    *reinterpret_cast<void **>(dummy_heap + 0 * 8) = entry1;
    *reinterpret_cast<void **>(dummy_heap + 1 * 8) = entry2;

    // Set up linked lists for one slot (e.g. slot 0)
    void *node2[2] = { dummy_sub_item2, nullptr };
    void *node1[2] = { dummy_sub_item1, node2 };
    *reinterpret_cast<void **>(zm + 0x90D0) = node1;

    func_001D1560(zm);

    // 2 calls from linked list, 2 calls from items_buf = 4 calls to func_25DE30
    assert(g_func_25de30_calls == 4);
    assert(g_func_117cac_calls == 1);
    assert(g_last_freed_heap == dummy_heap);
    assert(g_last_freed_size == 400);
    assert(*reinterpret_cast<int *>(zm + 0x9044) == 0);

    // Verify slots 0..16 cleared
    for (int i = 0; i < 17; i++) {
        assert(*reinterpret_cast<int *>(zm + 0x9048 + i * 4) == 0);
        assert(*reinterpret_cast<int *>(zm + 0x908C + i * 4) == 0);
        assert(*reinterpret_cast<int *>(zm + 0x90D0 + i * 4) == 0);
    }
}

int main(int argc, char **argv) {
    test_cleanup_null_buffer();
    test_cleanup_render_items_flow();
    return 0;
}
