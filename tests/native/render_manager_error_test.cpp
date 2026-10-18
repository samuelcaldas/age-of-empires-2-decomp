#include "render_manager_error_test_support.h"

static void test_constructor() {
    int dummy_device = 42;
    RenderManagerError err(&dummy_device);
    assert(err.device == &dummy_device);
    assert(err.error_code == 0);
}

static void test_format_error() {
    int dummy_device = 99;
    RenderManagerError err(&dummy_device);
    g_last_error_call = {};
    int res = err.format_error(0x17B7, 12);
    assert(res == 0x17B7);
    assert(g_last_error_call.device == &dummy_device);
    assert(g_last_error_call.capacity == 0x400);
    assert(g_last_error_call.res_id == 0x17B7);
    assert(g_last_error_call.arg == 12);
    assert(g_last_error_call.call_count == 1);
}

static void test_translate_zero_hr() {
    int dummy_device = 1;
    RenderManagerError err(&dummy_device);
    g_last_error_call = {};
    err.translate_error(0);
    assert(err.error_code == 0);
    assert(g_last_error_call.call_count == 0);
}

static void test_translate_surface_lost() {
    int dummy_device = 2;
    RenderManagerError err(&dummy_device);
    g_last_error_call = {};
    err.translate_error(static_cast<int>(0x88770118));
    assert(err.error_code == static_cast<int>(0x88770118));
    assert(g_last_error_call.call_count == 1);
    assert(g_last_error_call.res_id == 0x17B7);
    assert(g_last_error_call.arg == 0);
}

static void test_translate_noop_error() {
    int dummy_device = 3;
    RenderManagerError err(&dummy_device);
    g_last_error_call = {};
    err.translate_error(static_cast<int>(0x80004001));
    assert(err.error_code == static_cast<int>(0x80004001));
    assert(g_last_error_call.call_count == 0);
}

static void test_destructor() {
    int dummy_device = 4;
    RenderManagerError *err = new RenderManagerError(&dummy_device);
    assert(err != 0);
    delete err;
}

int main(int count, char **arguments) {
    if (count != 2) return 1;
    switch (std::atoi(arguments[1])) {
    case 0: test_constructor(); return 0;
    case 1: test_format_error(); return 0;
    case 2: test_translate_zero_hr(); return 0;
    case 3: test_translate_surface_lost(); return 0;
    case 4: test_translate_noop_error(); return 0;
    case 5: test_destructor(); return 0;
    default: return 1;
    }
}
