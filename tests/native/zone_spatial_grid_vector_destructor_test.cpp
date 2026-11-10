#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_vector_destructor.h"

static int g_reset_call_count = 0;
static void *g_reset_last_self = 0;

static int g_free_call_count = 0;
static void *g_free_last_ptr = 0;

extern "C" {
void func_1EB9C0(void *self) {
    g_reset_call_count++;
    g_reset_last_self = self;
}

void func_100670(void *ptr) {
    g_free_call_count++;
    g_free_last_ptr = ptr;
}
}

static void test_null_self() {
    g_reset_call_count = 0;
    g_free_call_count = 0;
    void *ret = func_001EB920(0, 1);
    assert(ret == 0);
    assert(g_reset_call_count == 0);
    assert(g_free_call_count == 0);
}

static void test_destruct_no_free() {
    g_reset_call_count = 0;
    g_free_call_count = 0;
    int dummy = 42;
    void *ret = func_001EB920(&dummy, 0);
    assert(ret == &dummy);
    assert(g_reset_call_count == 1);
    assert(g_reset_last_self == &dummy);
    assert(g_free_call_count == 0);
}

static void test_destruct_with_free() {
    g_reset_call_count = 0;
    g_free_call_count = 0;
    int dummy = 99;
    void *ret = func_001EB920(&dummy, 1);
    assert(ret == &dummy);
    assert(g_reset_call_count == 1);
    assert(g_reset_last_self == &dummy);
    assert(g_free_call_count == 1);
    assert(g_free_last_ptr == &dummy);
}

static void test_destruct_negative_flag() {
    g_reset_call_count = 0;
    g_free_call_count = 0;
    int dummy = 123;
    void *ret = func_001EB920(&dummy, -1);
    assert(ret == &dummy);
    assert(g_reset_call_count == 1);
    assert(g_free_call_count == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int case_num = std::atoi(argv[1]);
    switch (case_num) {
        case 0: test_null_self(); break;
        case 1: test_destruct_no_free(); break;
        case 2: test_destruct_with_free(); break;
        case 3: test_destruct_negative_flag(); break;
        default: return 2;
    }
    return 0;
}
