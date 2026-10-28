#include <cassert>
#include <csetjmp>
#include <iostream>
#include <string>
#include <vector>
#include <sys/mman.h>
#include "kt_game_loop.h"

static std::vector<std::string> g_call_order;
static jmp_buf g_jump_buf;
static int g_loop_iterations = 0;
static int g_msg_queue_polls = 0;

int D_00C6F390 = 1;
int D_00C6F3B0 = 2;
int D_00C6F3D0 = 3;
volatile u64 D_00CA1550 = 100;
volatile u64 D_00CA1560 = 200;

extern "C" {
void func_220940(void) { g_call_order.push_back("func_220940"); }
void func_220BA0(void) { g_call_order.push_back("func_220BA0"); }
void func_220C60(void) { g_call_order.push_back("func_220C60"); }
void func_221110(void) { g_call_order.push_back("func_221110"); }
void func_221410(void) { g_call_order.push_back("func_221410"); }
void func_103358(int a0) { assert(a0 == 0); g_call_order.push_back("func_103358"); }
void func_2208F0(void) { g_call_order.push_back("func_2208F0"); }
void func_222190(void) { g_call_order.push_back("func_222190"); }
void func_2263A0(int a0) { assert(a0 == 1); g_call_order.push_back("func_2263A0"); }

int func_2204D0(int id) {
    assert(id == 1);
    g_call_order.push_back("func_2204D0");
    return 0;
}
int func_104D40(int id) {
    g_call_order.push_back("func_104D40");
    return 0;
}
int func_104D60(int id) {
    assert(id == 1);
    g_call_order.push_back("func_104D60");
    return 0;
}
int func_226260(void) { g_call_order.push_back("func_226260"); return 0; }
int func_2204E0(int id) {
    assert(id == 3);
    g_msg_queue_polls++;
    // Return 1 on first call to trigger msg processing, then 0 to exit while loop
    if (g_msg_queue_polls % 2 == 1) {
        return 1;
    }
    return 0;
}
void func_2207B0(void) { g_call_order.push_back("func_2207B0"); }
void func_221790(void) { g_call_order.push_back("func_221790"); }
void func_3379F0(int a0) { assert(a0 == 0); g_call_order.push_back("func_3379F0"); }
void func_221F40(void) { g_call_order.push_back("func_221F40"); }
void func_36F800(int a0) { assert(a0 == 0); g_call_order.push_back("func_36F800"); }
void func_221C00(void) { g_call_order.push_back("func_221C00"); }
void func_224A10(void) {
    g_call_order.push_back("func_224A10");
    g_loop_iterations++;
    if (g_loop_iterations >= 2) {
        longjmp(g_jump_buf, 1);
    }
}
}

static void test_case_0_game_loop_iterations_and_counters() {
    g_call_order.clear();
    g_loop_iterations = 0;
    g_msg_queue_polls = 0;
    D_00CA1550 = 100;
    D_00CA1560 = 200;

    if (setjmp(g_jump_buf) == 0) {
        func_002206A0();
    }

    // Initial sequence
    assert(g_call_order[0] == "func_220940");
    assert(g_call_order[1] == "func_220BA0");
    assert(g_call_order[2] == "func_220C60");
    assert(g_call_order[3] == "func_221110");
    assert(g_call_order[4] == "func_221410");
    assert(g_call_order[5] == "func_103358");
    assert(g_call_order[6] == "func_2208F0");
    assert(g_call_order[7] == "func_222190");
    assert(g_call_order[8] == "func_2263A0");

    // Loop ran 2 full ticks
    assert(g_loop_iterations == 2);
    assert(D_00CA1550 == 102);
    assert(D_00CA1560 == 202);

    std::cout << "PASS: case 0 game loop iterations and counters" << std::endl;
}

int main(int argc, char **argv) {
    void *hw_page = mmap((void *)0x10000000, 4096, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    assert(hw_page == (void *)0x10000000);
    test_case_0_game_loop_iterations_and_counters();
    return 0;
}
