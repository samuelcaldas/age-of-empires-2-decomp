#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_vector_push_back.h"

struct FastVector {
    void **buffer;
    short count;
    short cap;
    char flag;
};

static int g_is_full_ret = 0;
static void *g_is_full_arg = 0;

extern "C" int func_001EBA00(void *self) {
    g_is_full_arg = self;
    return g_is_full_ret;
}

static void test_push_back_success() {
    g_is_full_ret = 0;
    g_is_full_arg = 0;

    void *buf[4] = {0};
    FastVector vec;
    vec.buffer = buf;
    vec.count = 0;
    vec.cap = 4;
    vec.flag = 0;

    int item1 = 10;
    int idx1 = func_001EBAB0(&vec, &item1);
    assert(idx1 == 0);
    assert(vec.count == 1);
    assert(vec.buffer[0] == &item1);
    assert(g_is_full_arg == &vec);

    int item2 = 20;
    int idx2 = func_001EBAB0(&vec, &item2);
    assert(idx2 == 1);
    assert(vec.count == 2);
    assert(vec.buffer[1] == &item2);
}

static void test_push_back_when_full() {
    g_is_full_ret = 1;
    g_is_full_arg = 0;

    void *buf[4] = {0};
    FastVector vec;
    vec.buffer = buf;
    vec.count = 4;
    vec.cap = 4;
    vec.flag = 0;

    int item = 99;
    int idx = func_001EBAB0(&vec, &item);
    assert(idx == -1);
    assert(vec.count == 4);
    assert(vec.buffer[0] == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_id = std::atoi(argv[1]);
    switch (case_id) {
        case 0:
            test_push_back_success();
            break;
        case 1:
            test_push_back_when_full();
            break;
        default:
            return 1;
    }
    return 0;
}
