#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "kt_game_thread_spawn_2205e0.h"

struct SemaContainer D_00C7F390 = {10, {0, 0, 0, 0, 0, 0}};
struct SemaContainer D_00C7F3B0 = {20, {0, 0, 0, 0, 0, 0}};
struct SemaContainer D_00C7F3D0 = {30, {0, 0, 0, 0, 0, 0}};
struct ThreadContainer D_00C6F350 = {42, {0}};
char D_00C6F390[0x10000] = {0};

static std::vector<std::string> g_call_order;
static int g_started_thread_id = -1;
static void *g_started_arg = nullptr;

extern "C" {
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option) {
    if (sema == &D_00C7F390) {
        g_call_order.push_back("func_220300_sema1");
    } else if (sema == &D_00C7F3B0) {
        g_call_order.push_back("func_220300_sema2");
    } else if (sema == &D_00C7F3D0) {
        g_call_order.push_back("func_220300_sema3");
    } else {
        assert(false && "unexpected semaphore pointer");
    }
    assert(max_count == 1);
    assert(init_count == 0 || init_count == 1); // 3rd sema is init_count=1
    assert(option == 0);
    return 0;
}

int func_220380(struct ThreadContainer *thread, void *entry, void *stack, int stack_size, int priority, int option) {
    assert(thread == &D_00C6F350);
    assert(stack == (void *)D_00C6F390);
    assert(stack_size == 0x10000);
    assert(priority == 13);
    assert(option == 0);
    g_call_order.push_back("func_220380");
    return 0;
}

int func_104B40(int thread_id, void *arg) {
    g_started_thread_id = thread_id;
    g_started_arg = arg;
    g_call_order.push_back("func_104B40");
    return 0;
}

void func_002206A0(void) {}
}

static void test_case_0_thread_spawn_2205e0_sequence() {
    g_call_order.clear();
    g_started_thread_id = -1;
    g_started_arg = nullptr;

    void *test_arg = (void *)0xDEADBEEF;
    int res = func_002205E0(test_arg);

    assert(res == 1);
    assert(g_call_order.size() == 5);
    assert(g_call_order[0] == "func_220300_sema1");
    assert(g_call_order[1] == "func_220300_sema2");
    assert(g_call_order[2] == "func_220300_sema3");
    assert(g_call_order[3] == "func_220380");
    assert(g_call_order[4] == "func_104B40");
    assert(g_started_thread_id == 42);
    assert(g_started_arg == test_arg);

    std::cout << "PASS: case 0 thread spawn 2205e0 sequence" << std::endl;
}

int main(int argc, char **argv) {
    test_case_0_thread_spawn_2205e0_sequence();
    return 0;
}
