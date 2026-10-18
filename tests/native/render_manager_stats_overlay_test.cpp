#include "render_manager_stats_overlay.h"
#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

static char g_buf_copy[256];
static int g_11A498_calls = 0;
static void *g_192B30_obj = 0;
static void *g_192B30_data = 0;
static int g_192B30_size = 0;
static int g_192B30_calls = 0;

const char D_00491AE0[] = "fps=%lu, rend=%lu";

extern "C" {
int func_11A498(char *buf, const char *fmt, ...) {
    g_11A498_calls++;
    va_list args;
    va_start(args, fmt);
    int res = vsprintf(buf, fmt, args);
    va_end(args);
    std::strcpy(g_buf_copy, buf);
    return res;
}

void func_192B30(void *obj, void *data, int size) {
    g_192B30_calls++;
    g_192B30_obj = obj;
    g_192B30_data = data;
    g_192B30_size = size;
}
}

static void test_stats_format_zero_field518() {
    RenderManagerStatsOverlay mgr = {};
    mgr.field_518 = 0;
    mgr.field_530 = 60;
    mgr.timers[2].frame_time = 100;
    g_11A498_calls = 0;

    func_00187b40(&mgr);
    assert(g_11A498_calls == 1);
    assert(std::strcmp(mgr.field_418, "fps=60, rend=100") == 0);
}

static void test_stats_format_nonzero_field518() {
    RenderManagerStatsOverlay mgr = {};
    mgr.field_518 = 2;
    mgr.field_530 = 30;
    mgr.timers[2].frame_time = 100;
    g_11A498_calls = 0;

    func_00187b40(&mgr);
    assert(g_11A498_calls == 1);
    assert(std::strcmp(mgr.field_418, "fps=30, rend=50") == 0);
}

static void test_stubs_and_save_config() {
    func_00187c40();
    func_00187c50();
    func_00187c60();

    RenderManagerStatsOverlay mgr = {};
    mgr.field_1AC = 0;
    g_192B30_calls = 0;
    func_00187c70(&mgr);
    assert(g_192B30_calls == 0);

    mgr.field_1AC = (void *)0xCAFE;
    func_00187c70(&mgr);
    assert(g_192B30_calls == 1);
    assert(g_192B30_obj == (void *)0xCAFE);
    assert(g_192B30_data == &mgr.field_90C);
    assert(g_192B30_size == 0xB0);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_stats_format_zero_field518(); return 0;
    case 1: test_stats_format_nonzero_field518(); return 0;
    case 2: test_stubs_and_save_config(); return 0;
    default: return 1;
    }
}
