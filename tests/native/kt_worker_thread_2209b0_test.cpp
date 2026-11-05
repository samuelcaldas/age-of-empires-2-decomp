#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "kt_worker_thread_2209b0.h"

static std::vector<std::string> g_call_order;

extern "C" {
int func_1354C8(void) { g_call_order.push_back("func_1354C8"); return 0; }
int func_136628(void) { g_call_order.push_back("func_136628"); return 0; }
int func_2204D0(void) { g_call_order.push_back("func_2204D0"); return 0; }
int func_104D60(void) { g_call_order.push_back("func_104D60"); return 0; }
int func_2204E0(void) { return 0; }
int func_221AC0(void) { return 0; }
int func_104FA0(void) { return 0; }
int func_1032F8(void) { return 0; }
int func_1033F0(void) { return 0; }
int func_36AF60(void) { return 0; }
int func_21FEB0(void) { return 0; }
int func_36E5E0(void) { return 0; }
int func_2241E0(void) { return 0; }
int func_224390(void) { return 0; }
int func_2244E0(void) { return 0; }
int func_36DC10(void) { return 0; }
int func_224590(void) { return 0; }
int func_123908(void) { return 0; }
int func_223F50(void) { return 0; }
int func_21E370(void) { return 0; }
int func_123920(void) { return 0; }
int func_123888(void) { return 0; }
int func_224310(void) { return 0; }
int func_133EC8(void) { return 0; }
int func_137000(void) { return 0; }
int func_135BF0(void) { return 0; }
int func_104D40(void) { return 0; }
int func_12D988(void) { return 0; }
}

static void test_case_0_worker_thread_init_sequence() {
    g_call_order.clear();

    func_002209B0();

    assert(g_call_order.size() == 4);
    assert(g_call_order[0] == "func_1354C8");
    assert(g_call_order[1] == "func_136628");
    assert(g_call_order[2] == "func_2204D0");
    assert(g_call_order[3] == "func_104D60");

    std::cout << "PASS: case 0 worker thread init sequence" << std::endl;
}

int main(int argc, char **argv) {
    test_case_0_worker_thread_init_sequence();
    return 0;
}
