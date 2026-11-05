#include <cassert>
#include <iostream>

static int g_func_00117CAC_called = 0;
static int g_func_001043B8_called = 0;
static int g_func_0021E500_called = 0;
static int g_func_0021C610_called = 0;
static int g_func_0021C4A0_called = 0;
static int g_func_0021C810_called = 0;
static int g_func_00104FA0_called = 0;
static int g_func_002204E0_called = 0;

int D_004E1CA0 = 0;
int D_004E32E4 = 0;
int D_004E1CA4 = 0;

extern "C" {
void func_00117CAC(void) { g_func_00117CAC_called++; }
void func_001043B8(void) { g_func_001043B8_called++; }
void func_0021E500(void) { g_func_0021E500_called++; }
void func_0021C610(void) { g_func_0021C610_called++; }
void func_0021C4A0(void) { g_func_0021C4A0_called++; }
void func_0021C810(void) { g_func_0021C810_called++; }
void func_00104FA0(void) { g_func_00104FA0_called++; }
void func_002204E0(void) { g_func_002204E0_called++; }

#include "kt_gs_swap_221790.h"
}

int main() {
    func_00221790();
    assert(g_func_00117CAC_called == 2);
    assert(g_func_001043B8_called == 2);
    assert(g_func_0021E500_called == 1);
    assert(g_func_0021C610_called == 1);
    assert(g_func_0021C4A0_called == 1);
    assert(g_func_0021C810_called == 1);

    func_00221880();
    assert(g_func_00104FA0_called == 1);
    assert(g_func_002204E0_called == 1);

    std::cout << "All kt_gs_swap_221790 tests passed!" << std::endl;
    return 0;
}
