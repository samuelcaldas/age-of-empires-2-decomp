#include <cassert>
#include <cstdio>
#include <cstring>
#include "zone_spatial_grid_realloc_buffer.h"

typedef char static_assertion_pointer_size[sizeof(void *) == 4 ? 1 : -1];

struct GridBuffer {
    int count;      // 0x00
    void *buf_8byte;// 0x04
    int capacity;   // 0x08
    void *buf_4byte;// 0x0C
};

static int s_alloc_calls = 0;
static int s_free_calls = 0;
static int s_memcpy_calls = 0;

extern "C" {
void *func_100730(unsigned int size) {
    s_alloc_calls++;
    return new char[size];
}

void func_100630(void *ptr) {
    s_free_calls++;
    delete[] (char *)ptr;
}

void *func_117AF8(void *dst, const void *src, int n) {
    s_memcpy_calls++;
    return std::memcpy(dst, src, n);
}
}

static void test_realloc_not_needed() {
    GridBuffer gb;
    std::memset(&gb, 0, sizeof(gb));
    gb.capacity = 10;

    s_alloc_calls = 0;
    func_001E5390(&gb, 5);

    assert(gb.count == 5);
    assert(gb.capacity == 10);
    assert(s_alloc_calls == 0);
}

static void test_realloc_expands_and_copies() {
    GridBuffer gb;
    std::memset(&gb, 0, sizeof(gb));
    gb.capacity = 4;
    gb.count = 2;

    int *b8 = (int *)new char[4 * 8];
    int *b4 = (int *)new char[4 * 4];
    b8[0] = 111;
    b8[1] = 222;
    b4[0] = 333;
    b4[1] = 444;

    gb.buf_8byte = b8;
    gb.buf_4byte = b4;

    s_alloc_calls = 0;
    s_free_calls = 0;
    s_memcpy_calls = 0;

    // new_count = 10 > capacity (4). New capacity = 4 + 32 = 36.
    func_001E5390(&gb, 10);

    assert(gb.count == 10);
    assert(gb.capacity == 36);
    assert(s_alloc_calls == 2);
    assert(s_free_calls == 2);
    assert(s_memcpy_calls == 2);

    int *new_b8 = (int *)gb.buf_8byte;
    int *new_b4 = (int *)gb.buf_4byte;
    assert(new_b8[0] == 111);
    assert(new_b8[1] == 222);
    assert(new_b4[0] == 333);
    assert(new_b4[1] == 444);

    delete[] (char *)gb.buf_8byte;
    delete[] (char *)gb.buf_4byte;
}

int main() {
    test_realloc_not_needed();
    test_realloc_expands_and_copies();
    std::printf("zone_spatial_grid_realloc_buffer_test passed\n");
    return 0;
}
