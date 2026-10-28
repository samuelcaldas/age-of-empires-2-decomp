#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "kt_thread_spawn_220940.h"

struct SemaContainer D_00C7F430 = {10, {0, 0, 0, 0, 0, 0}};
struct ThreadContainer D_00C6F3F0 = {99, {0}};
char D_00C6F430[0x10000] = {0};

static std::vector<std::string> g_call_order;
static int g_started_thread_id = -1;

extern "C" {
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option) {
    assert(sema == &D_00C7F430);
    assert(max_count == 1);
    assert(init_count == 0);
    assert(option == 0);
    g_call_order.push_back("func_220300");
    return 0;
}

int func_220380(struct ThreadContainer *thread, void *entry, void *stack, int stack_size, int priority, int option) {
    assert(thread == &D_00C6F3F0);
    assert(stack == (void *)D_00C6F430);
    assert(stack_size == 0x10000);
    assert(priority == 11);
    assert(option == 0);
    g_call_order.push_back("func_220380");
    return 0;
}

int func_104B40(int thread_id, void *arg) {
    g_started_thread_id = thread_id;
    assert(arg == nullptr);
    g_call_order.push_back("func_104B40");
    return 0;
}

void func_2209B0(void) {}
}

static void test_case_0_thread_spawn_220940_sequence() {
    g_call_order.clear();
    g_started_thread_id = -1;

    func_00220940();

    assert(g_call_order.size() == 3);
    assert(g_call_order[0] == "func_220300");
    assert(g_call_order[1] == "func_220380");
    assert(g_call_order[2] == "func_104B40");
    assert(g_started_thread_id == 99);

    std::cout << "PASS: case 0 thread spawn 220940 sequence" << std::endl;
}

int main(int argc, char **argv) {
    test_case_0_thread_spawn_220940_sequence();
    return 0;
}
