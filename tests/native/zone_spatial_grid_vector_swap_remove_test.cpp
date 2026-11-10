#include <cassert>
#include <cstdlib>
#include "zone_spatial_grid_vector_swap_remove.h"

struct Element {
    char pad_26[0x26];
    short index;
};

struct FastVector {
    void **buffer;
    short count;
    short cap;
    unsigned char flag;
};

static void test_remove_by_valid_index() {
    Element el0, el1, el2;
    el0.index = 0;
    el1.index = 1;
    el2.index = 2;

    void *buf[4] = {&el0, &el1, &el2, 0};
    FastVector vec;
    vec.buffer = buf;
    vec.count = 3;
    vec.cap = 4;
    vec.flag = 0;

    // Remove index 0: el2 should be moved to index 0, el2.index updated to 0
    func_001EBB20(&vec, 0, 0);

    assert(vec.count == 2);
    assert(vec.buffer[0] == &el2);
    assert(el2.index == 0);
    assert(vec.buffer[1] == &el1);
    assert(vec.buffer[2] == 0);
}

static void test_remove_by_element_search() {
    Element el0, el1, el2;
    el0.index = 0;
    el1.index = 1;
    el2.index = 2;

    void *buf[4] = {&el0, &el1, &el2, 0};
    FastVector vec;
    vec.buffer = buf;
    vec.count = 3;
    vec.cap = 4;
    vec.flag = 0;

    // Pass invalid index -1, so it searches for el1
    func_001EBB20(&vec, &el1, -1);

    assert(vec.count == 2);
    assert(vec.buffer[0] == &el0);
    assert(vec.buffer[1] == &el2);
    assert(el2.index == 1);
    assert(vec.buffer[2] == 0);
}

static void test_flag_nonzero_no_op() {
    Element el0;
    el0.index = 0;
    void *buf[4] = {&el0, 0, 0, 0};
    FastVector vec;
    vec.buffer = buf;
    vec.count = 1;
    vec.cap = 4;
    vec.flag = 1; // non-zero flag

    func_001EBB20(&vec, &el0, 0);

    assert(vec.count == 1);
    assert(vec.buffer[0] == &el0);
}

static void test_remove_last_element_search() {
    Element el0, el1;
    el0.index = 0;
    el1.index = 1;

    void *buf[4] = {&el0, &el1, 0, 0};
    FastVector vec;
    vec.buffer = buf;
    vec.count = 2;
    vec.cap = 4;
    vec.flag = 0;

    // Remove last element el1 by search
    func_001EBB20(&vec, &el1, -1);

    assert(vec.count == 1);
    assert(vec.buffer[0] == &el0);
    assert(vec.buffer[1] == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_id = std::atoi(argv[1]);
    switch (case_id) {
        case 0:
            test_remove_by_valid_index();
            break;
        case 1:
            test_remove_by_element_search();
            break;
        case 2:
            test_flag_nonzero_no_op();
            break;
        case 3:
            test_remove_last_element_search();
            break;
        default:
            return 1;
    }
    return 0;
}
