#include <cassert>
#include <iostream>
#include "kt_sema_poll.h"

static int g_poll_success_limit = 0;
static int g_poll_calls = 0;

extern "C" {
int func_104D70(int sema_id) {
    g_poll_calls++;
    if (g_poll_calls <= g_poll_success_limit) {
        return sema_id;
    }
    return -1;
}
}

static void test_case_0_immediate_fail() {
    g_poll_calls = 0;
    g_poll_success_limit = 0;

    int ret = func_002204E0(5);
    assert(ret == 0);
    assert(g_poll_calls == 1);
    std::cout << "PASS: case 0 immediate fail" << std::endl;
}

static void test_case_1_multiple_polls() {
    g_poll_calls = 0;
    g_poll_success_limit = 4;

    int ret = func_002204E0(7);
    assert(ret == 4);
    assert(g_poll_calls == 5);
    std::cout << "PASS: case 1 multiple polls" << std::endl;
}

static void test_case_2_delegation_wrapper() {
    g_poll_calls = 0;
    g_poll_success_limit = 2;

    int ret = func_002204D0(3);
    assert(ret == 2);
    assert(g_poll_calls == 3);
    std::cout << "PASS: case 2 delegation wrapper" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_case_0_immediate_fail();
        test_case_1_multiple_polls();
        test_case_2_delegation_wrapper();
        return 0;
    }

    switch (argv[1][0]) {
    case '0':
        test_case_0_immediate_fail();
        break;
    case '1':
        test_case_1_multiple_polls();
        break;
    case '2':
        test_case_2_delegation_wrapper();
        break;
    default:
        std::cerr << "Unknown case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
