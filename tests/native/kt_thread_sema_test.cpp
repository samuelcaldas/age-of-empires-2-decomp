#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "kt_thread_sema.h"

static int g_thread_status_ret = 1;
static int g_thread_delete_ret = 1;
static int g_sema_create_ret = 10;
static struct SemaParam g_last_sema_param;
static std::vector<std::string> g_log_messages;

extern "C" {
extern const char D_00492C90[] = "ThreadNo.%d was already DORMANT.\n";
extern const char D_00492CC0[] = "Can't delete thread. id=%d\n";
extern const char D_00492CE0[] = "ThreadNo.%d was deleted.\n";
extern const char D_00492D00[] = "Semaphore: id=%d current=%d max=%d init=%d wait=%d attr=%d\n";

int func_104B70(int id) {
    return g_thread_status_ret;
}

int func_104B30(int id) {
    return g_thread_delete_ret;
}

int func_104D20(struct SemaParam *param) {
    g_last_sema_param = *param;
    return g_sema_create_ret;
}

int func_104D90(int id, struct SemaParam *status) {
    status->current_count = 5;
    status->max_count = 10;
    status->init_count = 5;
    status->wait_threads = 0;
    status->attr = 0;
    status->option = 0;
    return 0;
}

int func_118DE0(const char *fmt, ...) {
    char buf[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    g_log_messages.push_back(buf);
    return 0;
}
}

static void test_case_0_thread_delete_dormant() {
    g_log_messages.clear();
    g_thread_status_ret = -1; // Status is not thread_id -> triggers "already DORMANT"
    g_thread_delete_ret = 42; // Successfully deleted

    int ret = func_00220280(42);
    assert(ret == 42);
    assert(g_log_messages.size() == 2);
    assert(g_log_messages[0] == "ThreadNo.42 was already DORMANT.\n");
    assert(g_log_messages[1] == "ThreadNo.42 was deleted.\n");
    std::cout << "PASS: case 0 thread delete dormant" << std::endl;
}

static void test_case_1_thread_delete_failure() {
    g_log_messages.clear();
    g_thread_status_ret = 42; // Status matches thread_id -> not dormant
    g_thread_delete_ret = -1; // Delete failed

    int ret = func_00220280(42);
    assert(ret == 42);
    assert(g_log_messages.size() == 1);
    assert(g_log_messages[0] == "Can't delete thread. id=42\n");
    std::cout << "PASS: case 1 thread delete failure" << std::endl;
}

static void test_case_2_sema_create_and_query() {
    g_log_messages.clear();
    g_sema_create_ret = 7;

    struct SemaContainer sema;
    std::memset(&sema, 0, sizeof(sema));

    int ret = func_00220300(&sema, 20, 10, 0x1234);
    assert(ret == 7);
    assert(sema.id == 7);
    assert(sema.param.max_count == 20);
    assert(sema.param.init_count == 10);
    assert(sema.param.option == 0x1234);
    assert(g_last_sema_param.max_count == 20);
    assert(g_last_sema_param.init_count == 10);
    assert(g_last_sema_param.option == 0x1234);
    assert(g_log_messages.size() == 1);
    std::cout << "PASS: case 2 sema create and query" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_case_0_thread_delete_dormant();
        test_case_1_thread_delete_failure();
        test_case_2_sema_create_and_query();
        return 0;
    }

    switch (argv[1][0]) {
    case '0':
        test_case_0_thread_delete_dormant();
        break;
    case '1':
        test_case_1_thread_delete_failure();
        break;
    case '2':
        test_case_2_sema_create_and_query();
        break;
    default:
        std::cerr << "Unknown case: " << argv[1] << std::endl;
        return 1;
    }
    return 0;
}
