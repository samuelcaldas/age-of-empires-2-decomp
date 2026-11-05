#include <cassert>
#include <vector>
#include <iostream>

// Stub state to record calls made by func_00220FF0
static std::vector<int> g_call_log;
static int g_func_3887f0_a0 = 0;
static int g_func_3887f0_a1 = 0;
static int g_func_337d40_called = 0;
static std::vector<int> g_25d430_calls;
static int g_21bdd0_called = 0;
static std::vector<int> g_25d060_calls;
static int g_220f70_called = 0;

int D_004E33E0 = 0;
int D_004E33E4 = 0;
int D_004E33E8 = 0;

extern "C" {
void func_003887F0(int a0, int a1) {
    g_func_3887f0_a0 = a0;
    g_func_3887f0_a1 = a1;
}

void func_00337D40(void) {
    g_func_337d40_called++;
}

void func_0025D430(int code) {
    g_25d430_calls.push_back(code);
}

int func_0021BDD0(void) {
    g_21bdd0_called++;
    return 0x175E9;
}

void func_0025D060(int code) {
    g_25d060_calls.push_back(code);
}

void func_00220F70(void) {
    g_220f70_called++;
}

#include "kt_init_sequence_220ff0.h"
}

int main() {
    func_00220FF0();

    assert(g_func_3887f0_a0 == 3);
    assert(g_func_3887f0_a1 == 0x1EC);
    assert(g_func_337d40_called == 1);

    // D_004E33E0 should have been set to 0x19 (25)
    assert(D_004E33E0 == 0x19);
    // D_004E33E4 should have been set to 0x18 (24)
    assert(D_004E33E4 == 0x18);
    // D_004E33E8 should have been set to func_0021BDD0() return value: 0x175E9
    assert(D_004E33E8 == 0x175E9);

    assert(g_25d430_calls.size() == 3);
    assert(g_25d430_calls[0] == 0x1003);
    assert(g_25d430_calls[1] == 0x1004);
    assert(g_25d430_calls[2] == 0x1005);

    assert(g_25d060_calls.size() == 5);
    assert(g_25d060_calls[0] == 0x1010);
    assert(g_25d060_calls[1] == 0x1011);
    assert(g_25d060_calls[2] == 0x1012);
    assert(g_25d060_calls[3] == 0x1013);
    assert(g_25d060_calls[4] == 0x101F);

    assert(g_220f70_called == 5);

    std::cout << "All kt_init_sequence_220ff0 tests passed!" << std::endl;
    return 0;
}
