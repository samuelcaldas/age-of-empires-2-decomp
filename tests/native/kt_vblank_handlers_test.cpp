#include <cassert>
#include <iostream>
#include "kt_vblank_handlers.h"

volatile u64 D_00CA1550[3] = {100, 200, 300};
struct SemaContainer D_00C7F430 = {15, {0, 0, 0, 0, 0, 0}};
struct SemaContainer D_00C80490 = {25, {0, 0, 0, 0, 0, 0}};
int D_004E331C = 0;

static int g_last_signaled_sema = -1;

extern "C" {
int func_104D50(int sema_id) {
    g_last_signaled_sema = sema_id;
    return 0;
}
}

static void test_case_0_vblank_start() {
    g_last_signaled_sema = -1;
    D_00CA1550[1] = 200;
    D_004E331C = 0;

    int ret = func_00220D50();
    assert(ret == 0);
    assert(D_00CA1550[1] == 201);
    assert(g_last_signaled_sema == 15);
    assert(D_004E331C == 1);

    std::cout << "PASS: case 0 vblank start" << std::endl;
}

static void test_case_1_vblank_end() {
    g_last_signaled_sema = -1;
    D_004E331C = 1;

    int ret = func_00220DA0();
    assert(ret == 0);
    assert(g_last_signaled_sema == 25);
    assert(D_004E331C == 0);

    std::cout << "PASS: case 1 vblank end" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_case_0_vblank_start();
        test_case_1_vblank_end();
        return 0;
    }

    switch (argv[1][0]) {
    case '0':
        test_case_0_vblank_start();
        break;
    case '1':
        test_case_1_vblank_end();
        break;
    default:
        std::cerr << "Unknown case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
