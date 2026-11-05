#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "kt_frame_update_2207b0.h"

u8 D_00CA157C = 0;
u32 D_00CA1590 = 0;
u32 D_00CA1594 = 0;
u32 D_00CA1598 = 0;
u32 D_00CA159C = 0;
void *D_00CA15B0 = nullptr;
void *D_00C82510 = nullptr;
void *D_00C92D10 = (void *)0x1111;
void *D_00C92D20 = (void *)0x2222;
u32 D_004E3310 = 0;
u32 D_004E3314 = 0;

static std::vector<std::string> g_call_order;

extern "C" {
int func_3741D0(void) {
    g_call_order.push_back("func_3741D0");
    return 0;
}

int func_123920(void) {
    g_call_order.push_back("func_123920");
    return 0;
}

int func_123908(void) {
    g_call_order.push_back("func_123908");
    return 0;
}

int func_221550(void *a0) {
    g_call_order.push_back("func_221550");
    return 0;
}

int func_123888(void) {
    g_call_order.push_back("func_123888");
    return 0;
}

int func_123818(void) {
    g_call_order.push_back("func_123818");
    return 0;
}

int func_133E10(void) {
    g_call_order.push_back("func_133E10");
    return 0;
}

int func_221440(void) {
    g_call_order.push_back("func_221440");
    return 0;
}

int func_220420(void *a0, int a1, void *a2, int a3) {
    if (a1 == 2) {
        assert(a0 == &D_00C92D10);
        assert(a3 == -1);
        g_call_order.push_back("func_220420_vblank_start");
    } else if (a1 == 3) {
        assert(a0 == &D_00C92D20);
        assert(a3 == -1);
        g_call_order.push_back("func_220420_vblank_end");
    } else {
        assert(false && "unexpected vblank handler registration");
    }
    return 0;
}

int func_00220D50(void) { return 0; }
int func_00220DA0(void) { return 0; }
}

static void test_case_0_frame_update_skip_branch() {
    g_call_order.clear();
    D_00CA157C = 0; // skip condition (== 0)
    D_004E3310 = 0;

    func_002207B0();

    assert(D_004E3310 == 1);
    assert(g_call_order.size() == 6);
    assert(g_call_order[0] == "func_3741D0");
    assert(g_call_order[1] == "func_123888");
    assert(g_call_order[2] == "func_123818");
    assert(g_call_order[3] == "func_133E10");
    assert(g_call_order[4] == "func_123818");
    assert(g_call_order[5] == "func_221440");

    std::cout << "PASS: case 0 frame update skip branch" << std::endl;
}

static void test_case_1_vblank_handlers_registration() {
    g_call_order.clear();

    func_002208F0();

    assert(g_call_order.size() == 2);
    assert(g_call_order[0] == "func_220420_vblank_start");
    assert(g_call_order[1] == "func_220420_vblank_end");

    std::cout << "PASS: case 1 vblank handlers registration" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    switch (argv[1][0]) {
    case '0':
        test_case_0_frame_update_skip_branch();
        break;
    case '1':
        test_case_1_vblank_handlers_registration();
        break;
    default:
        std::cerr << "Unknown case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
