#ifndef RENDER_MANAGER_ERROR_TEST_SUPPORT_H
#define RENDER_MANAGER_ERROR_TEST_SUPPORT_H

#include "render_manager_error.h"
#include <cassert>
#include <cstdlib>

struct MockErrorCall {
    void *device;
    int capacity;
    int res_id;
    int arg;
    int call_count;
};

static MockErrorCall g_last_error_call = {};

extern "C" {
int func_2265E0(void *device, int capacity, int res_id, int arg) {
    g_last_error_call.device = device;
    g_last_error_call.capacity = capacity;
    g_last_error_call.res_id = res_id;
    g_last_error_call.arg = arg;
    g_last_error_call.call_count++;
    return res_id;
}

void func_100670(void *ptr) {
    std::free(ptr);
}
}

#endif
