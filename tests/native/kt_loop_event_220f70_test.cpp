#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "kt_loop_event_220f70.h"

static std::vector<std::string> g_call_order;

extern "C" {
int func_103358(int a0) {
    g_call_order.push_back("func_103358");
    return 0;
}

int func_12D888(void) {
    g_call_order.push_back("func_12D888");
    return 0;
}
}

static void test_case_0_loop_event_sequence() {
    g_call_order.clear();

    func_00220F70();

    assert(g_call_order.size() == 2);
    assert(g_call_order[0] == "func_103358");
    assert(g_call_order[1] == "func_12D888");

    std::cout << "PASS: case 0 loop event sequence" << std::endl;
}

int main(int argc, char **argv) {
    test_case_0_loop_event_sequence();
    return 0;
}
