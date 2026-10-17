#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "sight_table.h"

extern "C" {
    void *D_0038FA40[25];
    void *D_0038FAA0[25];
}

static void test_sight_table_clamping() {
    int dummy0 = 0x1234;
    int dummy20 = 0x5678;
    D_0038FA40[0] = &dummy0;
    D_0038FA40[20] = &dummy20;

    int dummy_mode0 = 0x9999;
    int dummy_mode20 = 0xAAAA;
    D_0038FAA0[0] = &dummy_mode0;
    D_0038FAA0[20] = &dummy_mode20;

    // Normal query mode 0
    assert(func_00137A40(nullptr, 0, 0) == &dummy0);
    assert(func_00137A40(nullptr, 20, 0) == &dummy20);

    // Clamping above 20
    assert(func_00137A40(nullptr, 50, 0) == &dummy20);

    // Clamping below 0
    assert(func_00137A40(nullptr, -5, 0) == &dummy0);

    // Mode != 0
    assert(func_00137A40(nullptr, 0, 1) == &dummy_mode0);
    assert(func_00137A40(nullptr, 20, 1) == &dummy_mode20);
    assert(func_00137A40(nullptr, 100, 1) == &dummy_mode20);
    assert(func_00137A40(nullptr, -1, 1) == &dummy_mode0);
}

int main(int argc, char **argv) {
    (void)argc; (void)argv;
    test_sight_table_clamping();
    return 0;
}
