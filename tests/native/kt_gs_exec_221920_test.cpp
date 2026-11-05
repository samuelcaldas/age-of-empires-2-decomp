#include <cassert>
#include <iostream>

static int g_func_00104430_called = 0;
static int g_func_00104D40_called = 0;
static int g_func_001043C8_called = 0;

int D_004E1CA0 = 0;
int D_004E1CA8 = 0;
int D_004E1CAC = 0;

extern "C" {
void func_00104430(void) { g_func_00104430_called++; }
void func_00104D40(void) { g_func_00104D40_called++; }
void func_001043C8(void) { g_func_001043C8_called++; }

#include "kt_gs_exec_221920.h"
}

int main() {
    func_00221920();
    assert(g_func_00104430_called == 1);
    assert(g_func_00104D40_called == 1);
    assert(g_func_001043C8_called == 1);

    std::cout << "All kt_gs_exec_221920 tests passed!" << std::endl;
    return 0;
}
