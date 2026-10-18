#include <cassert>
#include <cstddef>
#include "tactical_ai_combat_subsystem_profile_timer.h"

static int s_dummy_mgr = 0x1234;
void *D_004E3180 = &s_dummy_mgr;

static int s_timer_calls = 0;
static int s_work_calls = 0;
static void *s_work_self = 0;
static int s_log_calls = 0;
static void *s_log_mgr = 0;
static int s_log_channel = 0;
static int s_log_elapsed = 0;

extern "C" {
    int func_2261C0() {
        s_timer_calls++;
        if (s_timer_calls == 1) return 1000;
        return 1450;
    }

    void func_1A3640(void *self) {
        s_work_calls++;
        s_work_self = self;
    }

    void func_184B60(void *mgr, int channel, int elapsed) {
        s_log_calls++;
        s_log_mgr = mgr;
        s_log_channel = channel;
        s_log_elapsed = elapsed;
    }
}

static void test_profiling_wrapper() {
    int dummy_self = 99;
    s_timer_calls = 0;
    s_work_calls = 0;
    s_log_calls = 0;

    func_00328F80(&dummy_self);

    assert(s_timer_calls == 2);
    assert(s_work_calls == 1);
    assert(s_work_self == &dummy_self);
    assert(s_log_calls == 1);
    assert(s_log_mgr == D_004E3180);
    assert(s_log_channel == 7);
    assert(s_log_elapsed == 450);
}

int main() {
    test_profiling_wrapper();
    return 0;
}
