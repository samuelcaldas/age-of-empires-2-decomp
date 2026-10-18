#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_mode_dispatch.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(SystemManager, m_mode) == 0x1C8, "mode");
static_assert(offsetof(CombatSubsystemMeshInstance, m_active) == 0x17C, "active");

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_status_ret = 0;
static int s_disable_calls = 0;
static int s_reset_calls = 0;
static int s_action_calls = 0;
static void *s_last_self = 0;
static int s_last_a1 = 0;
static int s_last_a2 = 0;

extern "C" {
    int func_185DC0(void *, int) {
        return s_status_ret;
    }

    void func_1A5390(void *self) {
        s_disable_calls++;
        s_last_self = self;
    }

    void func_1F65A0(void *self) {
        s_reset_calls++;
        s_last_self = self;
    }

    int func_1A52D0(void *self, int a1, int a2) {
        s_action_calls++;
        s_last_self = self;
        s_last_a1 = a1;
        s_last_a2 = a2;
        return 1;
    }
}

static void test_mode_guards() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    inst.m_active = 1;

    s_mgr.m_mode = 0;
    assert(func_00328820(&inst, 0, 0) == 0);

    s_mgr.m_mode = 3;
    assert(func_00328820(&inst, 0, 0) == 0);
}

static void test_status_nonzero_branches() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_mode = 4;
    s_status_ret = 1;

    inst.m_active = 1;
    s_disable_calls = 0;
    s_reset_calls = 0;
    assert(func_00328820(&inst, 0, 0) == 0);
    assert(s_disable_calls == 1);
    assert(s_reset_calls == 0);
    assert(s_last_self == &inst);

    inst.m_active = 0;
    s_disable_calls = 0;
    s_reset_calls = 0;
    assert(func_00328820(&inst, 0, 0) == 0);
    assert(s_disable_calls == 0);
    assert(s_reset_calls == 1);
    assert(s_last_self == &inst);
}

static void test_status_zero_dispatch() {
    CombatSubsystemMeshInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_mode = 6;
    s_status_ret = 0;

    inst.m_active = 0;
    s_action_calls = 0;
    assert(func_00328820(&inst, 10, 20) == 0);
    assert(s_action_calls == 0);

    inst.m_active = 1;
    int res = func_00328820(&inst, 10, 20);
    assert(res == 1);
    assert(s_action_calls == 1);
    assert(s_last_self == &inst);
    assert(s_last_a1 == 10);
    assert(s_last_a2 == 20);
}

int main() {
    test_mode_guards();
    test_status_nonzero_branches();
    test_status_zero_dispatch();
    return 0;
}
