#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <vector>
#include "zone_spatial_grid_free_node_array.h"

struct NodeArrayHeader {
    char pad_00[0x14];
    short field_14;
    char pad_16[2];
    int field_18;
    short count;
    char pad_1E[2];
    void *buffer;
    char pad_24[8];
    void *vtable;
};

void *D_4D99B0[4] = {0, 0, 0, 0};

static std::vector<void *> g_freed_buffers;
static int g_delete_calls = 0;
static void *g_delete_ptr = 0;

extern "C" {
void func_116F68(void *ptr) {
    g_freed_buffers.push_back(ptr);
}

void func_100670(void *ptr) {
    g_delete_calls++;
    g_delete_ptr = ptr;
}
}

static void test_layout() {
    assert(offsetof(NodeArrayHeader, field_14) == 0x14);
    assert(offsetof(NodeArrayHeader, field_18) == 0x18);
    assert(offsetof(NodeArrayHeader, count) == 0x1C);
    assert(offsetof(NodeArrayHeader, buffer) == 0x20);
    assert(offsetof(NodeArrayHeader, vtable) == 0x2C);
}

static void test_null_self() {
    g_freed_buffers.clear();
    g_delete_calls = 0;
    void *ret = func_001EB3B0(0, 1);
    assert(ret == 0);
    assert(g_freed_buffers.empty());
    assert(g_delete_calls == 0);
}

static void test_empty_array_no_delete() {
    g_freed_buffers.clear();
    g_delete_calls = 0;
    NodeArrayHeader h;
    h.field_14 = 10;
    h.field_18 = 20;
    h.count = 0;
    h.buffer = 0;
    h.vtable = 0;

    void *ret = func_001EB3B0(&h, 0);
    assert(ret == &h);
    assert(h.vtable == D_4D99B0);
    assert(h.field_14 == 0);
    assert(h.field_18 == 0);
    assert(g_freed_buffers.empty());
    assert(g_delete_calls == 0);
}

static void test_populated_array_no_delete() {
    g_freed_buffers.clear();
    g_delete_calls = 0;
    int dummy_buf = 999;
    NodeArrayHeader h;
    h.field_14 = 5;
    h.field_18 = 15;
    h.count = 4;
    h.buffer = &dummy_buf;
    h.vtable = 0;

    void *ret = func_001EB3B0(&h, 0);
    assert(ret == &h);
    assert(h.vtable == D_4D99B0);
    assert(h.count == 0);
    assert(h.buffer == 0);
    assert(h.field_14 == 0);
    assert(h.field_18 == 0);
    assert(g_freed_buffers.size() == 1);
    assert(g_freed_buffers[0] == &dummy_buf);
    assert(g_delete_calls == 0);
}

static void test_populated_array_with_delete() {
    g_freed_buffers.clear();
    g_delete_calls = 0;
    int dummy_buf = 777;
    NodeArrayHeader h;
    h.field_14 = 1;
    h.field_18 = 2;
    h.count = 3;
    h.buffer = &dummy_buf;
    h.vtable = 0;

    void *ret = func_001EB3B0(&h, 1);
    assert(ret == &h);
    assert(h.vtable == D_4D99B0);
    assert(h.count == 0);
    assert(h.buffer == 0);
    assert(g_freed_buffers.size() == 1);
    assert(g_freed_buffers[0] == &dummy_buf);
    assert(g_delete_calls == 1);
    assert(g_delete_ptr == &h);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_layout();
        test_null_self();
        test_empty_array_no_delete();
        test_populated_array_no_delete();
        test_populated_array_with_delete();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_layout();
        break;
    case 1:
        test_null_self();
        break;
    case 2:
        test_empty_array_no_delete();
        break;
    case 3:
        test_populated_array_no_delete();
        break;
    case 4:
        test_populated_array_with_delete();
        break;
    default:
        return 1;
    }
    return 0;
}
