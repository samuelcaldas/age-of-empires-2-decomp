#include <cassert>
#include <csetjmp>
#include <iostream>
#include <string>
#include <vector>
#include "kt_render_sync.h"

struct SemaContainer D_00C6F390 = {10, {0, 0, 0, 0, 0, 0}};
struct SemaContainer D_00C824F0 = {20, {0, 0, 0, 0, 0, 0}};

static std::vector<std::string> g_call_order;
static jmp_buf g_jump_buf;
static int g_loop_iterations = 0;
static int g_signaled_sema = -1;
static int g_func_103358_arg = -1;

extern "C" {
int func_2204D0(int sema_id) {
    assert(sema_id == 10);
    g_call_order.push_back("func_2204D0");
    return 0;
}

int func_104D60(int sema_id) {
    assert(sema_id == 10);
    g_call_order.push_back("func_104D60");
    return 0;
}

int func_2204E0(int sema_id) {
    assert(sema_id == 20);
    g_call_order.push_back("func_2204E0");
    return 1; // Return 1 to trigger func_2207B0
}

void func_2207B0(void) {
    g_call_order.push_back("func_2207B0");
}

int func_104D40(int sema_id) {
    g_signaled_sema = sema_id;
    g_call_order.push_back("func_104D40");
    g_loop_iterations++;
    if (g_loop_iterations >= 2) {
        longjmp(g_jump_buf, 1);
    }
    return 0;
}

void func_103358(int a0) {
    g_func_103358_arg = a0;
    g_call_order.push_back("func_103358");
}
}

static void test_case_0_render_sync_loop() {
    g_call_order.clear();
    g_loop_iterations = 0;

    if (setjmp(g_jump_buf) == 0) {
        func_00220CD0();
    }

    assert(g_loop_iterations == 2);
    // Sequence per iteration: func_2204D0 -> func_104D60 -> func_2204E0 -> func_2207B0 -> func_104D40
    assert(g_call_order.size() >= 5);
    assert(g_call_order[0] == "func_2204D0");
    assert(g_call_order[1] == "func_104D60");
    assert(g_call_order[2] == "func_2204E0");
    assert(g_call_order[3] == "func_2207B0");
    assert(g_call_order[4] == "func_104D40");
    std::cout << "PASS: case 0 render sync loop" << std::endl;
}

static void test_case_1_render_sync_signal() {
    g_call_order.clear();
    g_signaled_sema = -1;
    g_func_103358_arg = -1;

    func_00220D20();
    assert(g_signaled_sema == 20);
    assert(g_func_103358_arg == 0);
    assert(g_call_order.size() == 2);
    assert(g_call_order[0] == "func_104D40");
    assert(g_call_order[1] == "func_103358");
    std::cout << "PASS: case 1 render sync signal" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_case_0_render_sync_loop();
        test_case_1_render_sync_signal();
        return 0;
    }

    switch (argv[1][0]) {
    case '0':
        test_case_0_render_sync_loop();
        break;
    case '1':
        test_case_1_render_sync_signal();
        break;
    default:
        std::cerr << "Unknown case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
