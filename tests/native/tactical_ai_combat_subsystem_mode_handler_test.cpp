#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_mode_handler.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(SystemSub28, m_state) == 0xA0, "state");
static_assert(offsetof(SystemManager, m_sub28) == 0x28, "sub28");
static_assert(offsetof(SystemManager, m_mode) == 0x1C8, "mode");

static SystemSub28 s_sub28;
static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_status_ret = 0;
static int s_action_calls = 0;
static int s_reset_calls = 0;
static void *s_last_self = 0;
static int s_last_a1 = 0;
static int s_last_a2 = 0;

extern "C" {
    int func_185DC0(void *, int) {
        return s_status_ret;
    }

    void func_1A5200(void *self, int a1, int a2) {
        s_action_calls++;
        s_last_self = self;
        s_last_a1 = a1;
        s_last_a2 = a2;
    }

    void func_1F6510(void *self) {
        s_reset_calls++;
        s_last_self = self;
    }
}

static void test_status_and_mode_guards() {
    std::memset(&s_sub28, 0, sizeof(s_sub28));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;

    s_status_ret = 1;
    s_mgr.m_mode = 4;
    assert(func_00328B10(0, 0, 0) == 0);

    s_status_ret = 0;
    s_mgr.m_mode = 0;
    assert(func_00328B10(0, 0, 0) == 0);

    s_mgr.m_mode = 3;
    assert(func_00328B10(0, 0, 0) == 0);
}

static void test_state_2_branches() {
    std::memset(&s_sub28, 0, sizeof(s_sub28));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;
    s_status_ret = 0;
    s_sub28.m_state = 2;

    int dummy = 123;

    s_mgr.m_mode = 4;
    s_reset_calls = 0;
    assert(func_00328B10(&dummy, 0, 0) == 1);
    assert(s_reset_calls == 1);
    assert(s_last_self == &dummy);

    s_mgr.m_mode = 5;
    s_reset_calls = 0;
    s_action_calls = 0;
    assert(func_00328B10(&dummy, 0, 0) == 1);
    assert(s_reset_calls == 0);
    assert(s_action_calls == 0);
}

static void test_state_not_2_action() {
    std::memset(&s_sub28, 0, sizeof(s_sub28));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;
    s_status_ret = 0;
    s_mgr.m_mode = 6;
    s_sub28.m_state = 0;

    int dummy = 456;
    s_action_calls = 0;
    int res = func_00328B10(&dummy, 10, 20);

    assert(res == 1);
    assert(s_action_calls == 1);
    assert(s_last_self == &dummy);
    assert(s_last_a1 == 10);
    assert(s_last_a2 == 20);
}

int main() {
    test_status_and_mode_guards();
    test_state_2_branches();
    test_state_not_2_action();
    return 0;
}
