#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D07D0(void *self, void *bucket, int new_capacity);

static int g_func_100730_calls = 0;
static int g_func_100630_calls = 0;
static int g_func_117cac_calls = 0;
static char g_alloc_pool[16][128];
static int g_pool_idx = 0;

void *func_100730(int size) {
    g_func_100730_calls++;
    assert(g_pool_idx < 16);
    return g_alloc_pool[g_pool_idx++];
}

void func_100630(void *ptr) {
    g_func_100630_calls++;
}

void *func_117CAC(void *buf, int flag, int size) {
    g_func_117cac_calls++;
    std::memset(buf, 0, size);
    return buf;
}
}

static void reset_test_state() {
    g_func_100730_calls = 0;
    g_func_100630_calls = 0;
    g_func_117cac_calls = 0;
    g_pool_idx = 0;
    std::memset(g_alloc_pool, 0, sizeof(g_alloc_pool));
}

static void test_grow_capacity_flow() {
    reset_test_state();
    char bucket[64];
    std::memset(bucket, 0, sizeof(bucket));

    // Initial capacity = 4, count = 2
    *reinterpret_cast<int *>(bucket + 0x14) = 4;
    *reinterpret_cast<int *>(bucket + 0x10) = 2;

    int old_buf0[4] = {11, 22, 0, 0};
    int old_buf1[4] = {33, 44, 0, 0};
    *reinterpret_cast<void **>(bucket + 0x0) = old_buf0;
    *reinterpret_cast<void **>(bucket + 0x8) = old_buf1;

    // Grow capacity to 8
    func_001D07D0(nullptr, bucket, 8);

    assert(g_func_100730_calls == 2); // allocated 2 new buffers
    assert(g_func_117cac_calls == 2); // zeroed buffers
    assert(g_func_100630_calls == 2); // freed old buffers

    // Capacity updated to 8
    assert(*reinterpret_cast<int *>(bucket + 0x14) == 8);
    // Old items copied to new buffers
    int *new0 = *reinterpret_cast<int **>(bucket + 0x0);
    int *new1 = *reinterpret_cast<int **>(bucket + 0x8);
    assert(new0[0] == 11 && new0[1] == 22);
    assert(new1[0] == 33 && new1[1] == 44);
}

static void test_smaller_capacity_returns_immediately() {
    reset_test_state();
    char bucket[64];
    std::memset(bucket, 0, sizeof(bucket));

    *reinterpret_cast<int *>(bucket + 0x14) = 16; // current capacity = 16

    // Request new_capacity = 8 (< 16)
    func_001D07D0(nullptr, bucket, 8);

    assert(g_func_100730_calls == 0);
    assert(g_func_100630_calls == 0);
    assert(*reinterpret_cast<int *>(bucket + 0x14) == 16);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "smaller") {
        test_smaller_capacity_returns_immediately();
    } else {
        test_grow_capacity_flow();
        test_smaller_capacity_returns_immediately();
    }
    return 0;
}
