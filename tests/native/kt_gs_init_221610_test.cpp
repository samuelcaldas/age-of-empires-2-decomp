#include <cassert>
#include <iostream>

static int g_func_00123888_called = 0;
static int g_func_00102688_called = 0;
static int g_func_00103060_called = 0;
static int g_func_00102E70_called = 0;
static int g_func_00123920_called = 0;
static int g_func_00103358_called = 0;
static int g_func_001032F8_called = 0;
static int g_func_001033F0_called = 0;

extern "C" {
void func_00123888(void) { g_func_00123888_called++; }
void func_00102688(void) { g_func_00102688_called++; }
void func_00103060(void) { g_func_00103060_called++; }
void func_00102E70(void) { g_func_00102E70_called++; }
void func_00123920(void) { g_func_00123920_called++; }
void func_00103358(void) { g_func_00103358_called++; }
void func_001032F8(void) { g_func_001032F8_called++; }
void func_001033F0(void) { g_func_001033F0_called++; }

#include "kt_gs_init_221610.h"
}

int main() {
    func_00221610();
    assert(g_func_00123888_called == 1);

    func_00221630();
    assert(g_func_00102688_called == 1);
    assert(g_func_00103060_called == 1);
    assert(g_func_00102E70_called == 2);
    assert(g_func_00123920_called == 2);
    assert(g_func_00103358_called == 2);
    assert(g_func_001032F8_called == 2);
    assert(g_func_001033F0_called == 2);

    std::cout << "All kt_gs_init_221610 tests passed!" << std::endl;
    return 0;
}
