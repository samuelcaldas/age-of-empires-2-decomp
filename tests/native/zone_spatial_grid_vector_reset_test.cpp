#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_vector_reset.h"

struct FastVector {
    void *buffer;
    short count;
    short cap;
    char flag;
};

static int g_free_called = 0;
static void *g_free_arg = 0;

extern "C" void func_1EBA20(void *self) {
    g_free_called++;
    g_free_arg = self;
}

static void test_reset_with_buffer() {
    g_free_called = 0;
    g_free_arg = 0;

    int dummy = 123;
    FastVector vec;
    vec.buffer = &dummy;
    vec.count = 5;
    vec.cap = 10;
    vec.flag = 1;

    func_001EB9D0(&vec);

    assert(g_free_called == 1);
    assert(g_free_arg == &vec);
    assert(vec.buffer == 0);
    assert(vec.count == 0);
    assert(vec.cap == 0);
    assert(vec.flag == 0);
}

static void test_reset_without_buffer() {
    g_free_called = 0;
    g_free_arg = 0;

    FastVector vec;
    vec.buffer = 0;
    vec.count = 7;
    vec.cap = 12;
    vec.flag = 2;

    func_001EB9D0(&vec);

    assert(g_free_called == 0);
    assert(g_free_arg == 0);
    assert(vec.buffer == 0);
    assert(vec.count == 0);
    assert(vec.cap == 0);
    assert(vec.flag == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_id = std::atoi(argv[1]);
    switch (case_id) {
        case 0:
            test_reset_with_buffer();
            break;
        case 1:
            test_reset_without_buffer();
            break;
        default:
            return 1;
    }
    return 0;
}
