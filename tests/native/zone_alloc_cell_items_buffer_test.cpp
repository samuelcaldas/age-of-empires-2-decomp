#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D0DC0(void *self, int size_level);

static int g_func_1d08e0_calls = 0;

void func_1D08E0(void *self, void *bucket, int size) {
    g_func_1d08e0_calls++;
    // Replenish bucket capacity
    *reinterpret_cast<int *>(reinterpret_cast<char *>(bucket) + 0x28) += size;
}
}

static void reset_test_state() {
    g_func_1d08e0_calls = 0;
}

static void test_alloc_from_free_list() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char *bucket = zm + 0x8F24 + 0 * 68; // level 0
    *reinterpret_cast<int *>(bucket + 0x28) = 2; // available = 2

    char dummy_node1[32] = {}, dummy_node2[32] = {};
    *reinterpret_cast<void **>(dummy_node1) = dummy_node2; // next
    *reinterpret_cast<void **>(bucket + 0x18) = dummy_node1; // free list head

    void *allocated = func_001D0DC0(zm, 0);

    assert(allocated == dummy_node1);
    assert(*reinterpret_cast<void **>(bucket + 0x18) == dummy_node2);
    assert(*reinterpret_cast<int *>(bucket + 0x28) == 1);
    assert(g_func_1d08e0_calls == 0);
}

static void test_alloc_from_chunk_carves_slot() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char *bucket = zm + 0x8F24 + 0 * 68;
    *reinterpret_cast<int *>(bucket + 0x28) = 5; // available = 5
    *reinterpret_cast<void **>(bucket + 0x18) = nullptr; // free list empty

    char chunk_buf[256] = {};
    void *buffer_ptrs[4] = {chunk_buf, nullptr, nullptr, nullptr};
    int sizes_array[4] = {10, 0, 0, 0};

    *reinterpret_cast<void ***>(bucket + 0x0) = buffer_ptrs;
    *reinterpret_cast<int **>(bucket + 0x8) = sizes_array;
    *reinterpret_cast<int *>(bucket + 0x1C) = 0; // chunk_idx = 0
    *reinterpret_cast<int *>(bucket + 0x20) = 0; // cur_idx = 0
    *reinterpret_cast<int *>(bucket + 0x30) = 2; // factor = 2 words = 8 bytes

    void *slot0 = func_001D0DC0(zm, 0);
    assert(slot0 == chunk_buf);
    assert(*reinterpret_cast<int *>(bucket + 0x20) == 1);
    assert(*reinterpret_cast<int *>(bucket + 0x28) == 4);

    void *slot1 = func_001D0DC0(zm, 0);
    assert(slot1 == chunk_buf + 8);
    assert(*reinterpret_cast<int *>(bucket + 0x20) == 2);
    assert(*reinterpret_cast<int *>(bucket + 0x28) == 3);
}

static void test_alloc_replenishes_when_empty() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char *bucket = zm + 0x8F24 + 0 * 68;
    *reinterpret_cast<int *>(bucket + 0x28) = 0; // 0 available -> triggers 1D08E0
    *reinterpret_cast<int *>(bucket + 0x2C) = 8; // size to allocate

    char chunk_buf[256] = {};
    void *buffer_ptrs[4] = {chunk_buf, nullptr, nullptr, nullptr};
    int sizes_array[4] = {10, 0, 0, 0};
    *reinterpret_cast<void ***>(bucket + 0x0) = buffer_ptrs;
    *reinterpret_cast<int **>(bucket + 0x8) = sizes_array;
    *reinterpret_cast<int *>(bucket + 0x1C) = 0;
    *reinterpret_cast<int *>(bucket + 0x20) = 0;
    *reinterpret_cast<int *>(bucket + 0x30) = 1;

    void *slot = func_001D0DC0(zm, 0);

    assert(g_func_1d08e0_calls == 1); // called replenishment
    assert(slot == chunk_buf);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "chunk") {
        test_alloc_from_chunk_carves_slot();
    } else if (argc > 1 && std::string(argv[1]) == "replenish") {
        test_alloc_replenishes_when_empty();
    } else {
        test_alloc_from_free_list();
        test_alloc_from_chunk_carves_slot();
        test_alloc_replenishes_when_empty();
    }
    return 0;
}
