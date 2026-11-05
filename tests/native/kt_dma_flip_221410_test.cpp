#include <cassert>
#include <iostream>

static int g_func_00133E10_called = 0;
static int g_func_00223F50_called = 0;
static int g_func_00223F70_called = 0;
static int g_func_00104FA0_called = 0;
static int g_func_00133FB8_called = 0;
static int g_func_00133F38_called = 0;

int D_004E26E0 = 0;

extern "C" {
void func_00133E10(void) { g_func_00133E10_called++; }
int func_00223F50(void) { g_func_00223F50_called++; return 0; }
int func_00223F70(void) { g_func_00223F70_called++; return 0; }
void func_00104FA0(void) { g_func_00104FA0_called++; }
void func_00133FB8(void) { g_func_00133FB8_called++; }
void func_00133F38(void) { g_func_00133F38_called++; }

#include "kt_dma_flip_221410.h"
}

int main() {
    func_00221410();
    assert(g_func_00133E10_called == 1);

    func_00221440();
    assert(g_func_00223F50_called == 1);
    assert(g_func_00223F70_called == 1);
    assert(g_func_00104FA0_called == 1);
    assert(g_func_00133F38_called == 2);

    std::cout << "All kt_dma_flip_221410 tests passed!" << std::endl;
    return 0;
}
