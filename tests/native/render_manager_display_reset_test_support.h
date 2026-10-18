#ifndef RENDER_MANAGER_DISPLAY_RESET_TEST_SUPPORT_H
#define RENDER_MANAGER_DISPLAY_RESET_TEST_SUPPORT_H

#include "render_manager_display_reset.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>

struct MockResetCalls {
    void *last_198260_ptr;
    int count_198260;
    void *last_1a9bf0_ptr;
    int count_1a9bf0;
    void *last_193190_ptr;
    int count_193190;
};

static MockResetCalls g_mock_reset = {};

extern "C" {
const char D_00491B98[] = "[%d] %s - %s";

void func_198260(void *p) {
    g_mock_reset.last_198260_ptr = p;
    g_mock_reset.count_198260++;
}

void func_1A9BF0(void *p) {
    g_mock_reset.last_1a9bf0_ptr = p;
    g_mock_reset.count_1a9bf0++;
}

int func_193190(void *p) {
    g_mock_reset.last_193190_ptr = p;
    g_mock_reset.count_193190++;
    return 777;
}

const char *func_1910F0() {
    return "StatusA";
}

const char *func_00189c80(void *self, int a1) {
    (void)self;
    (void)a1;
    return "DetailB";
}

int func_11A498(char *dst, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int res = std::vsprintf(dst, fmt, args);
    va_end(args);
    return res;
}
}

#endif
