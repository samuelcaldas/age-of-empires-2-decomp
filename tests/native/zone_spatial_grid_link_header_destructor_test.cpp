#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_link_header_destructor.h"

static int g_base_dtor_call_count = 0;
static void *g_base_dtor_last_self = 0;

static int g_delete_call_count = 0;
static void *g_delete_last_ptr = 0;

extern "C" {
void func_001EC9E0(void *self) {
    g_base_dtor_call_count++;
    g_base_dtor_last_self = self;
}

void func_100670(void *ptr) {
    g_delete_call_count++;
    g_delete_last_ptr = ptr;
}
}

static void test_null_self() {
    g_base_dtor_call_count = 0;
    g_delete_call_count = 0;
    void *ret = func_001EC990(0, 1);
    assert(ret == 0);
    assert(g_base_dtor_call_count == 0);
    assert(g_delete_call_count == 0);
}

static void test_destruct_no_free() {
    g_base_dtor_call_count = 0;
    g_delete_call_count = 0;
    int dummy = 42;
    void *ret = func_001EC990(&dummy, 0);
    assert(ret == &dummy);
    assert(g_base_dtor_call_count == 1);
    assert(g_base_dtor_last_self == &dummy);
    assert(g_delete_call_count == 0);
}

static void test_destruct_with_free() {
    g_base_dtor_call_count = 0;
    g_delete_call_count = 0;
    int dummy = 99;
    void *ret = func_001EC990(&dummy, 1);
    assert(ret == &dummy);
    assert(g_base_dtor_call_count == 1);
    assert(g_base_dtor_last_self == &dummy);
    assert(g_delete_call_count == 1);
    assert(g_delete_last_ptr == &dummy);
}

static void test_destruct_negative_flag() {
    g_base_dtor_call_count = 0;
    g_delete_call_count = 0;
    int dummy = 123;
    void *ret = func_001EC990(&dummy, -1);
    assert(ret == &dummy);
    assert(g_base_dtor_call_count == 1);
    assert(g_base_dtor_last_self == &dummy);
    assert(g_delete_call_count == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_null_self();
        test_destruct_no_free();
        test_destruct_with_free();
        test_destruct_negative_flag();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_null_self();
        break;
    case 1:
        test_destruct_no_free();
        break;
    case 2:
        test_destruct_with_free();
        break;
    case 3:
        test_destruct_negative_flag();
        break;
    default:
        return 1;
    }
    return 0;
}
