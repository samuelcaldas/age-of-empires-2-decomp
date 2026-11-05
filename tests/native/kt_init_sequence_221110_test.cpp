#include <cassert>
#include <vector>
#include <iostream>

static int g_func_00221630_called = 0;
static int g_func_00103358_called = 0;
static int g_func_00102688_called = 0;
static int g_func_00103060_called = 0;
static int g_func_00102E70_called = 0;
static int g_func_00223F50_called = 0;
static int g_func_00223F70_called = 0;
static int g_func_00133FB8_called = 0;
static int g_func_00224940_called = 0;
static int g_func_002201E0_called = 0;
static int g_func_002222D0_called = 0;
static int g_func_00224150_called = 0;
static int g_func_00117CAC_called = 0;
static int g_func_00387100_called = 0;
static int g_func_0036D4E0_called = 0;
static int g_func_00221CF0_called = 0;

int D_004E26E0 = 0;

extern "C" {
void func_00221630(void) { g_func_00221630_called++; }
void func_00103358(void) { g_func_00103358_called++; }
void func_00102688(void) { g_func_00102688_called++; }
void func_00103060(void) { g_func_00103060_called++; }
void func_00102E70(void) { g_func_00102E70_called++; }
int func_00223F50(void) { g_func_00223F50_called++; return 0; }
int func_00223F70(void) { g_func_00223F70_called++; return 0; }
void func_00133FB8(void) { g_func_00133FB8_called++; }
void func_00224940(void) { g_func_00224940_called++; }
void func_002201E0(void) { g_func_002201E0_called++; }
void func_002222D0(void) { g_func_002222D0_called++; }
void func_00224150(void) { g_func_00224150_called++; }
void func_00117CAC(void) { g_func_00117CAC_called++; }
void func_00387100(void) { g_func_00387100_called++; }
void func_0036D4E0(void) { g_func_0036D4E0_called++; }
void func_00221CF0(void) { g_func_00221CF0_called++; }

#include "kt_init_sequence_221110.h"
}

int main() {
    func_00221110();

    assert(g_func_00221630_called == 1);
    assert(g_func_00103358_called == 1);
    assert(g_func_00102688_called == 1);
    assert(g_func_00103060_called == 1);
    assert(g_func_00102E70_called == 2);
    assert(g_func_00223F50_called == 1);
    assert(g_func_00223F70_called == 1);
    assert(g_func_00224940_called == 1);
    assert(g_func_002201E0_called == 1);
    assert(g_func_002222D0_called == 1);
    assert(g_func_00224150_called == 1);
    assert(g_func_00117CAC_called == 1);
    assert(g_func_00387100_called == 1);
    assert(g_func_0036D4E0_called == 1);
    assert(g_func_00221CF0_called == 1);

    std::cout << "All kt_init_sequence_221110 tests passed!" << std::endl;
    return 0;
}
