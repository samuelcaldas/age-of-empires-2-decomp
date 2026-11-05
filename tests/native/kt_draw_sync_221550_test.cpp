#include <cassert>
#include <iostream>

static int g_func_00104448_called = 0;
static int g_func_001045E8_called = 0;
static int g_func_00104890_called = 0;
static int g_func_00104600_called = 0;
static int g_func_00116F40_called = 0;
static int g_func_00116F68_called = 0;

extern "C" {
void func_00104448(void) { g_func_00104448_called++; }
void func_001045E8(void) { g_func_001045E8_called++; }
void func_00104890(void) { g_func_00104890_called++; }
void func_00104600(void) { g_func_00104600_called++; }
void func_00116F40(void) { g_func_00116F40_called++; }
void func_00116F68(void) { g_func_00116F68_called++; }

#include "kt_draw_sync_221550.h"
}

int main() {
    func_00221550((void *)0x1234);
    func_002215D0();
    assert(g_func_00116F40_called == 1);
    assert(g_func_00116F68_called == 1);

    std::cout << "All kt_draw_sync_221550 tests passed!" << std::endl;
    return 0;
}
