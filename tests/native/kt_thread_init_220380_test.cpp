#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "kt_thread_init_220380.h"

static std::vector<std::string> g_call_order;

extern "C" {
int func_104B20(void *param) {
    g_call_order.push_back("func_104B20");
    return 77;
}

int func_104C20(int id, void *info) {
    assert(id == 77);
    g_call_order.push_back("func_104C20");
    return 0;
}

int func_118DE0(...) {
    g_call_order.push_back("func_118DE0");
    return 0;
}

int func_105748(int a) {
    g_call_order.push_back("func_105748");
    return 0;
}

int func_104A00(int a, void *b, int c) {
    g_call_order.push_back("func_104A00");
    return 55;
}

int func_1057B0(int a) {
    g_call_order.push_back("func_1057B0");
    return 0;
}
}

static void test_case_0_thread_init_380() {
    g_call_order.clear();
    int thread_container[16] = {0};

    int id = func_00220380(thread_container, (void *)0x1234, (void *)0x5678, 0x1000, 15, 0);

    assert(id == 77);
    assert(thread_container[0] == 77);
    assert(thread_container[2] == 0x1234);
    assert(thread_container[3] == 0x5678);
    assert(thread_container[4] == 0x1000);
    assert(thread_container[6] == 15);
    assert(g_call_order.size() == 2);
    assert(g_call_order[0] == "func_104B20");
    assert(g_call_order[1] == "func_104C20");

    std::cout << "PASS: case 0 thread init 380" << std::endl;
}

static void test_case_1_handler_init_420() {
    g_call_order.clear();
    int handler_container[4] = {0};

    int res = func_00220420(handler_container, 2, (void *)0x8888, -1);

    assert(res == 55);
    assert(handler_container[0] == 55);
    assert(handler_container[1] == 2);
    assert(handler_container[2] == 0);
    assert(handler_container[3] == 0x8888);
    assert(g_call_order.size() == 3);
    assert(g_call_order[0] == "func_105748");
    assert(g_call_order[1] == "func_104A00");
    assert(g_call_order[2] == "func_1057B0");

    std::cout << "PASS: case 1 handler init 420" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    switch (argv[1][0]) {
    case '0':
        test_case_0_thread_init_380();
        break;
    case '1':
        test_case_1_handler_init_420();
        break;
    default:
        std::cerr << "Unknown case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
