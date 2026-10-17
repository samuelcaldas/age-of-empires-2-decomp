#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D08E0(void *self, void *bucket, int size);

static int g_func_1d07d0_calls = 0;
static int g_func_100730_calls = 0;
static char g_alloc_pool[16][128];
static int g_pool_idx = 0;

void func_1D07D0(void *self, void *bucket, int capacity) {
    g_func_1d07d0_calls++;
    *reinterpret_cast<int *>(reinterpret_cast<char *>(bucket) + 0x14) = capacity;
}

void *func_100730(int bytes) {
    g_func_100730_calls++;
    assert(g_pool_idx < 16);
    return g_alloc_pool[g_pool_idx++];
}
}

static void reset_test_state() {
    g_func_1d07d0_calls = 0;
    g_func_100730_calls = 0;
    g_pool_idx = 0;
    std::memset(g_alloc_pool, 0, sizeof(g_alloc_pool));
}

static void test_add_bucket_array_flow() {
    reset_test_state();
    char bucket[68];
    std::memset(bucket, 0, sizeof(bucket));

    void *buffer_ptrs[8] = {};
    int size_table[8] = {};
    *reinterpret_cast<void ***>(bucket + 0x0) = buffer_ptrs;
    *reinterpret_cast<int **>(bucket + 0x8) = size_table;
    *reinterpret_cast<int *>(bucket + 0x10) = 1; // count = 1
    *reinterpret_cast<int *>(bucket + 0x14) = 4; // capacity = 4
    *reinterpret_cast<int *>(bucket + 0x1C) = -1; // uninitialized first idx
    *reinterpret_cast<int *>(bucket + 0x30) = 2; // factor = 2

    func_001D08E0(nullptr, bucket, 10);

    assert(g_func_1d07d0_calls == 0); // capacity 4 > count 1
    assert(g_func_100730_calls == 1);
    assert(*reinterpret_cast<int *>(bucket + 0x10) == 2); // count = 2
    assert(size_table[1] == 10);
    assert(buffer_ptrs[1] != nullptr);
    assert(*reinterpret_cast<int *>(bucket + 0x1C) == 1);
    assert(*reinterpret_cast<int *>(bucket + 0x24) == 10);
}

static void test_grow_when_full() {
    reset_test_state();
    char bucket[68];
    std::memset(bucket, 0, sizeof(bucket));

    void *buffer_ptrs[8] = {};
    int size_table[8] = {};
    *reinterpret_cast<void ***>(bucket + 0x0) = buffer_ptrs;
    *reinterpret_cast<int **>(bucket + 0x8) = size_table;
    *reinterpret_cast<int *>(bucket + 0x10) = 4; // count = 4
    *reinterpret_cast<int *>(bucket + 0x14) = 4; // capacity = 4 (full)
    *reinterpret_cast<int *>(bucket + 0x1C) = 0;
    *reinterpret_cast<int *>(bucket + 0x30) = 1;

    func_001D08E0(nullptr, bucket, 20);

    assert(g_func_1d07d0_calls == 1); // grew capacity
    assert(g_func_100730_calls == 1);
    assert(*reinterpret_cast<int *>(bucket + 0x10) == 5);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "grow") {
        test_grow_when_full();
    } else {
        test_add_bucket_array_flow();
        test_grow_when_full();
    }
    return 0;
}
