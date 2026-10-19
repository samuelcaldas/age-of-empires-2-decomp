#include <cassert>
#include <cstdio>

#include "unit_action_build_81a80.h"

static void *g_func_002BFA60_called_with = 0;
static int g_func_002BFA60_call_count = 0;

static int g_dummy_mgr = 0x12345678;
static int g_other_mgr = 0x87654321;

extern "C" {
void *D_004E342C = &g_dummy_mgr;
void *D_4E342C = &g_dummy_mgr;

void func_002BFA60(void *mgr) {
    g_func_002BFA60_called_with = mgr;
    g_func_002BFA60_call_count++;
}
}

int main() {
    g_func_002BFA60_called_with = 0;
    g_func_002BFA60_call_count = 0;

    // Test 1: invoke func_00281A80, assert one target call with current D_004E342C pointer
    func_00281A80();
    assert(g_func_002BFA60_call_count == 1);
    assert(g_func_002BFA60_called_with == &g_dummy_mgr);

    // Test 2: change the global pointer and assert the new pointer is forwarded
    D_004E342C = &g_other_mgr;
    D_4E342C = &g_other_mgr;
    func_00281A80();
    assert(g_func_002BFA60_call_count == 2);
    assert(g_func_002BFA60_called_with == &g_other_mgr);

    // Test 3: verify alias func_281A80 behaves identically
    D_004E342C = &g_dummy_mgr;
    D_4E342C = &g_dummy_mgr;
    func_281A80();
    assert(g_func_002BFA60_call_count == 3);
    assert(g_func_002BFA60_called_with == &g_dummy_mgr);

    std::printf("All func_00281A80 native tests passed!\n");
    return 0;
}
