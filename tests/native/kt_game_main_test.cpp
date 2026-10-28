#include <cassert>
#include <csetjmp>
#include <iostream>
#include <string>
#include <vector>
#include "kt_game_main.h"

static std::vector<std::string> g_call_order;
static jmp_buf g_jump_buf;
static int g_loop_iterations = 0;

struct SemaContainer D_00C5F330 = {10, {0, 0, 0, 0, 0, 0}};
struct ThreadContainer D_00C5F350 = {20, {0}};

extern "C" {
void func_2215D0(void) { g_call_order.push_back("func_2215D0"); }
void func_1001C0(void) { g_call_order.push_back("func_1001C0"); }
int func_104C10(void) { g_call_order.push_back("func_104C10"); return 1; }
int func_104BB0(int id, int prio) {
    assert(id == 1);
    assert(prio == 10);
    g_call_order.push_back("func_104BB0");
    return 0;
}
void func_220DD0(void) { g_call_order.push_back("func_220DD0"); }
void func_21EA10(void) { g_call_order.push_back("func_21EA10"); }
void func_36AC20(void) { g_call_order.push_back("func_36AC20"); }
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option) {
    assert(sema == &D_00C5F330);
    assert(max_count == 1);
    assert(init_count == 0);
    assert(option == 0);
    g_call_order.push_back("func_220300");
    return 0;
}
int func_2205E0(void *arg) {
    assert((int)(size_t)arg == 1);
    g_call_order.push_back("func_2205E0");
    return 0;
}
int func_104D60(int sema_id) {
    assert(sema_id == 10);
    g_call_order.push_back("func_104D60");
    return 0;
}
int func_220280(int thread_id) {
    assert(thread_id == 20);
    g_call_order.push_back("func_220280");
    return 0;
}
void func_111710(void) { g_call_order.push_back("func_111710"); }
void func_102828(void) { g_call_order.push_back("func_102828"); }
void func_103948(int a0) {
    assert(a0 == 1);
    g_call_order.push_back("func_103948");
    g_loop_iterations++;
    if (g_loop_iterations >= 2) {
        longjmp(g_jump_buf, 1);
    }
}
}

static void test_case_0_initialization_and_loop_calls() {
    g_call_order.clear();
    g_loop_iterations = 0;

    if (setjmp(g_jump_buf) == 0) {
        func_00220530();
    }

    // Verify initial startup sequence
    assert(g_call_order.size() >= 8);
    assert(g_call_order[0] == "func_2215D0");
    assert(g_call_order[1] == "func_1001C0");
    assert(g_call_order[2] == "func_104C10");
    assert(g_call_order[3] == "func_104BB0");
    assert(g_call_order[4] == "func_220DD0");
    assert(g_call_order[5] == "func_21EA10");
    assert(g_call_order[6] == "func_36AC20");
    assert(g_call_order[7] == "func_220300");

    // Verify loop iterations
    assert(g_loop_iterations == 2);
    assert(g_call_order[8] == "func_104C10");
    assert(g_call_order[9] == "func_2205E0");
    assert(g_call_order[10] == "func_104D60");
    assert(g_call_order[11] == "func_220280");
    assert(g_call_order[12] == "func_111710");
    assert(g_call_order[13] == "func_102828");
    assert(g_call_order[14] == "func_103948");

    std::cout << "PASS: case 0 initialization and loop calls" << std::endl;
}

int main(int argc, char **argv) {
    test_case_0_initialization_and_loop_calls();
    return 0;
}
