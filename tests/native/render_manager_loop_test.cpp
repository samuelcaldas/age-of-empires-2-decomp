#include "render_manager_loop.h"
#include <cassert>
#include <cstdlib>

const MSG D_00391CD0 = {0};
int D_004E89C4 = 0;
const InputTableEntry *D_004E89C8 = 0;

static int g_peek_count = 0;
static int g_translate_calls = 0;
static int g_dispatch_calls = 0;
static int g_idle_calls = 0;
static int g_end_calls = 0;
static MSG g_next_msg = {0};

class TestLoopManager : public RenderManagerLoop {
public:
    int pre_translate_result;
    TestLoopManager() : pre_translate_result(1) {}
    int PreTranslateMessage(MSG *) { return pre_translate_result; }
    void OnIdle() { g_idle_calls++; }
};

extern "C" {
int func_2265D0(MSG *msg, void *hwnd, int min, int max, int remove) {
    (void)hwnd; (void)min; (void)max; (void)remove;
    if (g_peek_count > 0) {
        g_peek_count--;
        *msg = g_next_msg;
        return 1;
    }
    return 0;
}
void func_226620(MSG *) { g_translate_calls++; }
void func_226630(MSG *) { g_dispatch_calls++; }
int func_185160(const MSG *, const InputTableEntry **) { return 0; }
void func_388010() { g_end_calls++; }
}

static void test_empty_queue() {
    TestLoopManager mgr;
    mgr.field_1C = 99;
    g_peek_count = 0;
    g_idle_calls = 0;
    g_end_calls = 0;
    int res = func_00185230(&mgr);
    assert(res == 0 && mgr.field_1C == 0 && g_idle_calls == 1 && g_end_calls == 1);
}

static void test_quit_exit() {
    TestLoopManager mgr;
    g_peek_count = 5;
    g_next_msg.message = 0x12; // WM_QUIT
    D_004E89C4 = 0;
    g_translate_calls = 0;
    func_00185230(&mgr);
    assert(g_translate_calls == 0 && g_peek_count == 4);
}

static void test_quit_continue() {
    TestLoopManager mgr;
    g_peek_count = 1;
    g_next_msg.message = 0x12; // WM_QUIT
    D_004E89C4 = 1;
    func_00185230(&mgr);
    assert(D_004E89C4 == 0);
}

static void test_pretranslate_skip() {
    TestLoopManager mgr;
    mgr.pre_translate_result = 0;
    g_peek_count = 1;
    g_next_msg.message = 0x100;
    g_translate_calls = 0;
    func_00185230(&mgr);
    assert(g_translate_calls == 0);
}

static void test_dispatch() {
    TestLoopManager mgr;
    g_peek_count = 1;
    g_next_msg.message = 0x200;
    g_translate_calls = 0;
    g_dispatch_calls = 0;
    func_00185230(&mgr);
    assert(g_translate_calls == 1 && g_dispatch_calls == 1);
}

int main(int count, char **args) {
    if (count != 2) return 1;
    switch (std::atoi(args[1])) {
    case 0: test_empty_queue(); return 0;
    case 1: test_quit_exit(); return 0;
    case 2: test_quit_continue(); return 0;
    case 3: test_pretranslate_skip(); return 0;
    case 4: test_dispatch(); return 0;
    default: return 1;
    }
}
